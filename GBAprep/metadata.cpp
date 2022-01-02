#include <iostream>
#include <iomanip>
#include <fstream>

int main()
{
    char file[64];
    std::cin >> file;
    std::ifstream ifile(file, std::ios::binary);
    unsigned int x;
    unsigned int y;
    ifile.seekg(0x0A);
    int beg;
    ifile.seekg(0x10);
    ifile.read((char*)&x, 4);

    ifile.read((char*)&y, 4);
    ifile.read((char*)&beg, 4);
    unsigned short notdata[64];
    ifile.seekg(beg);
    ifile.read((char*)&notdata, 128);
    unsigned short data[64];
    for(int i = 0; i < 64; i++)
    {
        data[i] = notdata[63-i] + 0x8000;
    }
    std::cout << std::showbase // show the 0x prefix
         << std::internal // fill between the prefix and the number
         << std::setfill('0')
         << std::hex << std::setw(2) ;
    for(int i = 0; i < 64; i++)
    {
        std::cout << data[i];
    }
    std::ofstream ofile(file, std::ios::binary);
    ofile.write((char*)&data, 128);
    ifile.close();
    ofile.close();
}
