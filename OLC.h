//uint16_t* null;
//uint16_t zero = 0;
//uint16_t hito = 1;
//struct reg
//{
//    uint16_t* addr;
//    uint16_t init = 0x0000;
//    uint16_t* attr[16];
//    reg(uint16_t* address,
//        uint16_t* bF = null, uint16_t* bE = null, uint16_t* bD = null, uint16_t* bC = null, uint16_t* bB = null, uint16_t* bA = null, uint16_t* b9 = null, uint16_t* b8 = null,
//        uint16_t* b7 = null, uint16_t* b6 = null, uint16_t* b5 = null, uint16_t* b4 = null, uint16_t* b3 = null, uint16_t* b2 = null, uint16_t* b1 = null, uint16_t* b0 = null,
//         uint16_t initial = 0){
//        attr[0xF] = bF;
//        attr[0xE] = bE;
//        attr[0xD] = bD;
//        attr[0xC] = bC;
//        attr[0xB] = bB;
//        attr[0xA] = bA;
//        attr[0x9] = b9;
//        attr[0x8] = b8;
//        attr[0x7] = b7;
//        attr[0x6] = b6;
//        attr[0x5] = b5;
//        attr[0x4] = b4;
//        attr[0x3] = b3;
//        attr[0x2] = b2;
//        attr[0x1] = b1;
//        attr[0x0] = b0;
//        addr = address, init = initial;}
//    void inw(){
//        *addr = 0x0000;
//        for(int i = 0xF; i >= 0x0; i--){
//            if(attr[i] != null || attr[i] != &zero || attr[i] != &hito){
//                uint8_t sizeofattr = 0;
//                while(attr[i] == nullptr){
//                    sizeofattr++;
//                    i--;}
//                *addr += ((*attr[i] & ((2 << sizeofattr) - 1)) << i);}}}
//    void inr(){
//        for(int i = 0xF; i >= 0x0; i--){
//            if(attr[i] != null || attr[i] != &zero || attr[i] != &hito){
//                uint8_t sizeofattr = 0;
//                while(attr[i] == nullptr){
//                    sizeofattr++;
//                    i--;}
//                *attr[i] = (*addr & ((2 << sizeofattr) - 1) << i) >> i;}}}
//    void w(uint16_t data){
//        *addr = data;}
//    uint16_t r(){
//        return *addr;}
//    void initize(){
//        *addr = init;}
//};
//
//struct tile
//{
//    uint16_t* addr;
//    uint8_t Palette;
//    bool Vmirr, Hmirr;
//    uint16_t ID;
//    void w(){
//        *addr = 0x0000;
//        *addr = ((Palette & 1111) << 12) + ((Vmirr & 1) << 11) + ((Hmirr & 1) << 10) + ((ID & 1111111111) << 0);}
//};
//
//uint16_t OBJW = 0, W1 = 0, W0 = 0, rendOBJ = 0, rendBG3 = 0, rendBG2 = 0, rendBG1 = 0, rendBG0 = 0, ForcedBlank = 1, VRAMform = 0, HBIOPF = 0, BMPframe = 0, CGBmode = 0, BGmode = 0;
//uint16_t grnswap = 0;
//uint16_t vcounttest = 0, vcounttestirq = 0, hbirq = 0, vbirq = 0, vcounteval = 0, hbstat = 0, vbstat = 0;
//uint16_t vcount = 0;
//uint16_t ScreenSize = 0, AreaV = 0, ScreenBaseBlock = 0, ColorMode = 0, Mosaic = 0, CharBaseBlock = 0, PRIORITY = 0;
//uint16_t VOBJM = 0, HOBJM = 0, VBGM, HBGM;
//uint16_t BG2XcorL = 0;
//uint16_t BG3XcorL = 0;
//uint16_t BG2XcorH = 0;
//uint16_t BG3XcorH = 0;
//uint16_t BG2YcorL = 0;
//uint16_t BG3YcorL = 0;
//uint16_t BG2YcorH = 0;
//uint16_t BG3YcorH = 0;
//
//
//reg regDISPCNT(DISPCNT, &OBJW, &W1, &W0, &rendOBJ, &rendBG3, &rendBG2, &rendBG1, &rendBG0, &ForcedBlank, &VRAMform, &HBIOPF, &BMPframe, &CGBmode, nullptr, nullptr, &BGmode, 0x0080);
//reg regCLRSWAP(CLRSWAP, &grnswap);
//reg regDISPSTAT(DISPSTAT, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, &vcounttest, null, null, &vcounttestirq, &hbirq, &vbirq, &vcounteval, &hbstat, &vbstat);
//reg regVCOUNT(VCOUNT, null, null, null, null, null, null, null, null, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, &vcount);
//reg regBG0CNT(BG0CNT, nullptr, &ScreenSize, &AreaV, nullptr, nullptr, nullptr, nullptr, &ScreenBaseBlock, &ColorMode, &Mosaic, &zero, &zero, nullptr, &CharBaseBlock, nullptr, &PRIORITY);
//reg regBG1CNT(BG1CNT, nullptr, &ScreenSize, &AreaV, nullptr, nullptr, nullptr, nullptr, &ScreenBaseBlock, &ColorMode, &Mosaic, &zero, &zero, nullptr, &CharBaseBlock, nullptr, &PRIORITY);
//reg regBG2CNT(BG2CNT, nullptr, &ScreenSize, &AreaV, nullptr, nullptr, nullptr, nullptr, &ScreenBaseBlock, &ColorMode, &Mosaic, &zero, &zero, nullptr, &CharBaseBlock, nullptr, &PRIORITY);
//reg regBG3CNT(BG3CNT, nullptr, &ScreenSize, &AreaV, nullptr, nullptr, nullptr, nullptr, &ScreenBaseBlock, &ColorMode, &Mosaic, &zero, &zero, nullptr, &CharBaseBlock, nullptr, &PRIORITY);
//reg regMOSAIC(MOSAIC, nullptr, nullptr, nullptr, &VOBJM, nullptr, nullptr, nullptr, &HOBJM, nullptr, nullptr, nullptr, &VBGM, nullptr, nullptr, nullptr, &HBGM);
//reg regBG2X_L(BG2X_L, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, &BG2XcorL);
//reg regBG3X_L(BG3X_L, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, &BG3XcorL);
//reg regBG2X_H(BG2X_H, null, null, null, null, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, &BG2XcorH);
//reg regBG3X_H(BG3X_H, null, null, null, null, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, &BG3XcorH);
//reg regBG2Y_L(BG2Y_L, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, &BG2YcorL);
//reg regBG3Y_L(BG3Y_L, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, &BG3YcorL);
//reg regBG2Y_H(BG2Y_H, null, null, null, null, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, &BG2YcorH);
//reg regBG3Y_H(BG3Y_H, null, null, null, null, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, &BG3YcorH);
//

//void loadSD()
void load16pal(char filename[64], uint8_t palslot){
    std::ifstream ifile(filename, std::ios::binary);
    uint16_t colors[16];
    ifile.read((char*)colors, 32);
    for(int i = 0; i < 16; i++){
        *(BGPRAM + palslot * 16 + i) = colors[i];}}
void load256pal(char filename[64], uint8_t palslot){
    std::ifstream ifile(filename, std::ios::binary);
    uint16_t colors[256];
    ifile.read((char*)colors, 512);
    for(int i = 0; i < 256; i++){
        *(BGPRAM + palslot * 16 + i) = colors[i];}}
void loadpal(char filename[64], uint8_t palslot){
    std::ifstream ifile(filename, std::ios::binary);
    uint16_t colors[16];
    ifile.read((char*)colors, 32);
    for(int i = 0; i < 16; i++){
        *(OBJPRAM + palslot * 16 + i) = colors[i];}}
void wbreg(u16* reg, u8 pos, bool val){
    u16 temp = *reg & (1 << pos);
    *reg ^= temp;
    *reg |= val << pos;}



