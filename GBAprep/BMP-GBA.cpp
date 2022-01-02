#include <fstream>
#include <iostream>

int main()
{
//Start of data collection.
    char file[64] = "Devilmachine.bmp";
    //std::cin >> file;
    std::ifstream ifile(file, std::ios::binary);
    char filepal[64] = "Devilmachinepal.bmp";
    //std::cin >> filepal;
    std::ifstream ifilepal(filepal, std::ios::binary);
    unsigned int x, y, beg;
    unsigned short paldata[16];
    ifile.seekg(0x0A);
    ifile.read((char*)&beg, 4);
    ifile.seekg(0x12);
    ifile.read((char*)&x, 4);
//I don't know if it's because I'm storing it in A1R5G5B5 or something, but it always stores enough data for an even number of pixel on each row, but does not record it in the metadata.
    x += (x % 2);
    ifile.seekg(0x16);
    ifile.read((char*)&y, 4);
    ifile.seekg(beg);
    unsigned short notdata[(x) * y];
    ifile.read((char*)notdata, (x) * y * 2);
    ifile.close();
    ifilepal.seekg(beg);
    ifilepal.read((char*)paldata, 32);
    ifilepal.close();
    unsigned short data[x * y];
//End of data collection.
//This simply flips the image upside down. Since it's stored as such, I'm just flipping it right side up again.
    for(unsigned int i = 0; i < y; i++)
    {
        for(unsigned int j = 0; j < x; j++)
        {
            data[i * x + j] = notdata[(y - 1 - i) * x + j];
        }
    }
//Start of padding.
//Padding is necessary to turn it into AGB tiles.
    unsigned int padx = x + (8 - x % 8) % 8, pady = y + (8 - y % 8) % 8;
    unsigned int tilex = padx / 8, tiley = pady / 8;
    unsigned int paddata[padx * pady] = {0};

    for(unsigned int i = 0; i < y; i++)
    {
        for(unsigned int j = 0; j < x; j++)
        {
            paddata[i * padx + j] = data[i * x + j];
        }
    }
//End of padding
//Start of GBA transformation.
    unsigned short GBAdatpre[padx * pady];
    unsigned char notGBAdata[padx * pady / 2];
    unsigned char GBAdata[padx * pady / 2];
//This part turns the tile into palette index data.
    for(unsigned int i = 0; i < padx*pady; i++)
    {
        int q = 0;
        while(paddata[i] != paldata[q])
        {
            q = (q + 1) % 16;
        }
        GBAdatpre[i] = q;
    }
//This turns it into the actual bytes the GBA will read. 1B stores the palette index info for 2px.
    for(unsigned int i = 0; i < padx * pady / 2; i++)
    {
        notGBAdata[i] = GBAdatpre[(i) * 2] + (GBAdatpre[(i) * 2 + 1] << 4);
    }
//Since tile data is stored in 1 consecutive place, the tiles need to be stored in clusters of 8x8.
    for(unsigned int i = 0; i < tiley; i++)
    {
        for(unsigned int j = 0; j < tilex; j++)
        {
            for(unsigned int k = 0; k < 8; k++)
            {
                for(unsigned int l = 0; l < 4; l++)
                {
                    GBAdata[l + k * 4 + j * 32 + i * tilex * 32] = notGBAdata[l + k * (padx / 2) + j * 4 + i * (padx / 2) * 8];
                }
            }
        }
    }
//Start of output.
    std::ofstream ofile(file, std::ios::binary);
    ofile.write((char*)&GBAdata, padx * pady / 2);
    ofile.close();
    for(int i = 0; i < 16; i++)
    {
        paldata[i] = (paldata[i] & 0x7C00) >> 10 | paldata[i] & 0x3E0 | (paldata[i] & 0x1F) << 10;
    }
    std::ofstream ofilepal(filepal, std::ios::binary);
    ofilepal.write((char*)&paldata, 32);
    ofilepal.close();
//End of output.
//Viola! You now have GBA tile data!
    return 0;
}
