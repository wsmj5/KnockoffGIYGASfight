olc::Sprite sprScreen = olc::Sprite(240, 160);
olc::Sprite sprBackDrop = olc::Sprite(240, 160);
u32 uint1632(u16 pixel){
    u8 r = (pixel & 0x001F) >> 0, g = (pixel & 0x03E0) >> 5, b = (pixel & 0x7C00) >> 10, a = (pixel & 0x8000) >> 15;
    r = r / 31.0 * 255;
    g = g / 31.0 * 255;
    b = b / 31.0 * 255;
    u32 color = (0xFF << 24) + (b << 16) + (g << 8) + r;
    return color;}
u16 uint3216(olc::Pixel pixel){
    u8 r = pixel.r / 31;
    u8 g = pixel.g / 31;
    u8 b = pixel.b / 31;
    u8 a;
    u16 color = a << 15 | b << 10 | g << 5 | r;
    return color;}
void printtileBG3(u8 tilex, u8 tiley, u16 tileslot){
    u8 screenblock = (*BG3CNT & 0b0001111100000000) >> 8;
    u8 charblock = (*BG3CNT & 0b0000000000001100) >> 2;
    tileslot %= 1024;
    u16 tile = *(SDB[screenblock] + tileslot);
    u8 palette = (tile & 0xF000) >> 12, hflip = (tile & 0x0800) >> 11, vflip = (tile & 0x0400) >> 10;
    u16 tileid = tile & 0x03FF;
    short xdirect = hflip * -2 + 1;
    short ydirect = vflip * -2 + 1;
    for(int i = 0; i < 8; i++){
        sprScreen.SetPixel((8 + 0 * xdirect - hflip) % 8 + *BG3HOFS + tilex * 8, (8 + i * ydirect - vflip) % 8 + *BG3VOFS + tiley * 8, uint1632(*(BGpal[palette] + ((*(CDB[charblock] + i + 0x8 * tileid) & 0x0000000F) >> 0x00))));
        sprScreen.SetPixel((8 + 1 * xdirect - hflip) % 8 + *BG3HOFS + tilex * 8, (8 + i * ydirect - vflip) % 8 + *BG3VOFS + tiley * 8, uint1632(*(BGpal[palette] + ((*(CDB[charblock] + i + 0x8 * tileid) & 0x000000F0) >> 0x04))));
        sprScreen.SetPixel((8 + 2 * xdirect - hflip) % 8 + *BG3HOFS + tilex * 8, (8 + i * ydirect - vflip) % 8 + *BG3VOFS + tiley * 8, uint1632(*(BGpal[palette] + ((*(CDB[charblock] + i + 0x8 * tileid) & 0x00000F00) >> 0x08))));
        sprScreen.SetPixel((8 + 3 * xdirect - hflip) % 8 + *BG3HOFS + tilex * 8, (8 + i * ydirect - vflip) % 8 + *BG3VOFS + tiley * 8, uint1632(*(BGpal[palette] + ((*(CDB[charblock] + i + 0x8 * tileid) & 0x0000F000) >> 0x0C))));
        sprScreen.SetPixel((8 + 4 * xdirect - hflip) % 8 + *BG3HOFS + tilex * 8, (8 + i * ydirect - vflip) % 8 + *BG3VOFS + tiley * 8, uint1632(*(BGpal[palette] + ((*(CDB[charblock] + i + 0x8 * tileid) & 0x000F0000) >> 0x10))));
        sprScreen.SetPixel((8 + 5 * xdirect - hflip) % 8 + *BG3HOFS + tilex * 8, (8 + i * ydirect - vflip) % 8 + *BG3VOFS + tiley * 8, uint1632(*(BGpal[palette] + ((*(CDB[charblock] + i + 0x8 * tileid) & 0x00F00000) >> 0x14))));
        sprScreen.SetPixel((8 + 6 * xdirect - hflip) % 8 + *BG3HOFS + tilex * 8, (8 + i * ydirect - vflip) % 8 + *BG3VOFS + tiley * 8, uint1632(*(BGpal[palette] + ((*(CDB[charblock] + i + 0x8 * tileid) & 0x0F000000) >> 0x18))));
        sprScreen.SetPixel((8 + 7 * xdirect - hflip) % 8 + *BG3HOFS + tilex * 8, (8 + i * ydirect - vflip) % 8 + *BG3VOFS + tiley * 8, uint1632(*(BGpal[palette] + ((*(CDB[charblock] + i + 0x8 * tileid) & 0xF0000000) >> 0x1C))));}}
u16 bldmath(u16 pxb, u16 pxa, s8 blendb, s8 blenda, u16 pxc){
    //u8 rb = pxb & 0x1F, gb = (pxb & 0x3E0) >> 5, bb = (pxb & 0x7C00) >> 10;
    //u8 ra = pxa & 0x1F, ga = (pxa & 0x3E0) >> 5, ba = (pxa & 0x7C00) >> 10;
    //rb *= ((*BLDALPHA & 0x1F00) >> 8) / 16.0, gb *= ((*BLDALPHA & 0x1F00) >> 8) / 16.0, bb *= ((*BLDALPHA & 0x1F00) >> 8) / 16.0;
    //ra *= (*BLDALPHA & 0x001F) / 16.0, ga *= (*BLDALPHA & 0x001F) / 16.0, ba *= (*BLDALPHA & 0x001F) / 16.0;
    //return (rb + ra) | (gb + ga) << 5 | (bb + ba) << 10;
    if(pxb == 0 && pxa == 0) return pxc;
    if(pxb == 0 && pxa != 0) return pxa;
    if(pxb != 0 && pxa == 0) return pxb;
    if(pxb != 0 && pxa != 0){
    pxb = ((pxb & 0x1F) * blendb >> 4) | (((pxb & 0x3E0) >> 5) * blendb >> 4) << 5 | (((pxb & 0x7C00) >> 10) * blendb >> 4) << 10;
    pxa = ((pxa & 0x1F) * blenda >> 4) | (((pxa & 0x3E0) >> 5) * blenda >> 4) << 5 | (((pxa & 0x7C00) >> 10) * blenda >> 4) << 10;
    return 0x8000 | pxb + pxa;}}
void scanline(u8 scan){
    u8 blendb = (*BLDALPHA & 0x1F00) >> 8;
    u8 blenda = *BLDALPHA & 0x001F;
    u8 blendy = *BLDY & 0x001F;
    u16 pxdata[256] = {0};
    u8 OBJMOSV = (*MOSAIC & 0xF000) >> 12,
    OBJMOSH = (*MOSAIC & 0x00F00) >> 8,
    BGMOSV = (*MOSAIC & 0x00F0) >> 4,
    BGMOSH = *MOSAIC & 0x000F,
    OBJWINstat = (*DISPCNT & 0x8000) >> 15,
    WINstat[2] = {(*DISPCNT & 0x2000) >> 13, (*DISPCNT & 0x4000) >> 14},
    OBJstat = (*DISPCNT & 0x1000) >> 12,
    BGstat[4] = {(*DISPCNT & 0x0100) >> 8, (*DISPCNT & 0x0200) >> 9, (*DISPCNT & 0x0400) >> 10, (*DISPCNT & 0x0800) >> 11},
    Blank = (*DISPCNT & 0x0080) >> 7,
    OBJmap = (*DISPCNT & 0x0040) >> 6,
    HBOBJmod = (*DISPCNT & 0x0020) >> 5,
    Frameselect = (*DISPCNT & 0x0010) >> 4,
    BGmode = *DISPCNT & 0x0007,
    WINHcorh[2] = {(*WIN0H & 0xFF00) >> 8, (*WIN1H & 0xFF00) >> 8},
    WINHcorm[2] = {*WIN0H & 0xFF, *WIN1H & 0xFF},
    WINVcoru[2] = {(*WIN0V & 0xFF00) >> 8, (*WIN1V & 0xFF00) >> 8},
    WINVcors[2] = {*WIN0V & 0xFF, *WIN1V & 0xFF},
    WININBLDstat[2] = {(*WININ & 0x0020) >> 5, (*WININ & 0x2000) >> 13},
    WININOBJstat[2] = {(*WININ & 0x0010) >> 4, (*WININ & 0x1000) >> 12},
    WININBGstat[4][2] = {{*WININ & 0x0001, (*WININ & 0x0100) >> 8},
                        {(*WININ & 0x0002) >> 1, (*WININ & 0x0200) >> 9},
                        {(*WININ & 0x0004) >> 2, (*WININ & 0x0400) >> 10},
                        {(*WININ & 0x0008) >> 3, (*WININ & 0x0800) >> 11}},
    WINOBJBLDstat = (*WINOUT & 0x2000) >> 13,
    WINOBJOBJstat = (*WINOUT & 0x1000) >> 12,
    WINOBJBG3stat = (*WINOUT & 0x0800) >> 11,
    WINOBJBG2stat = (*WINOUT & 0x0400) >> 10,
    WINOBJBG1stat = (*WINOUT & 0x0200) >> 9,
    WINOBJBG0stat = (*WINOUT & 0x0100) >> 8,
    WINOUTBLDstat = (*WINOUT & 0x0020) >> 5,
    WINOUTOBJstat = (*WINOUT & 0x0010) >> 4,
    WINOUTBGstat[4] = {*WINOUT & 0x0001, (*WINOUT & 0x0002) >> 1, (*WINOUT & 0x0004) >> 2, (*WINOUT & 0x0008) >> 3},
    blendmode = (*BLDCNT & 0x00C0) >> 6;

    switch(BGmode){
        case 0:{
            u8 BGscan[4][256] = {0};
            u8 BGscanprior[16] = {255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};
            for(int l = 3; l >= 0; l--){
                u8 BGy = ((*BGCNT[l]) & 0b1000000000000000) >> 15,
                BGx = ((*BGCNT[l]) & 0b0100000000000000) >> 14,
                //AreaV = ((*BGCNT[l]) & 0b0010000000000000) >> 13,
                screenblock = ((*BGCNT[l]) & 0b0001111100000000) >> 8,
                colormode = ((*BGCNT[l]) & 0b0000000010000000) >> 7,
                mosaic = ((*BGCNT[l]) & 0b0000000001000000) >> 6,
                charblock = ((*BGCNT[l]) & 0b0000000000001100) >> 2,
                priority = (*BGCNT[l] & 0b0000000000000011);
                u16 line = (scan / (1 + mosaic * BGMOSV) * (1 + mosaic * BGMOSV) + *BGVOFS[l]) % (0x100 << BGy);
                u16 BGrow = line / 8;
                u16 tilerow = line % 8;
                u8 h8 = 8 << colormode, h1 = 1 << colormode, m8 = 8 >> colormode, m1 = 1 >> colormode;
                for(int h = 0; h < 256; h++){
                    u16 dot = (h / (1 + mosaic * BGMOSH) * (1 + mosaic * BGMOSH)) % (0x100 << BGx);
                    u16 tile = *(SDB[screenblock] + dot / 8 + BGrow * 0x20);
                    u16 pixel = dot % 8;
                    u8 hflip = (tile & 0x0800) >> 11, vflip = (tile & 0x0400) >> 10;
                    u8 xdirect = hflip * -2 + 1, ydirect = vflip * -2 + 1;
                    u32 row = *(CDB[charblock] + ((h8 + tilerow * ydirect * h1 - vflip * h1 + h / 4 % h1) % h8 + (tile & 0x03FF) * h8));
                    u8 palid = 0;
                    for(u8 i = 0; i < h1; i++){
                        palid += ((row & (0xF << (m8 + pixel * xdirect - hflip) % m8 * 4 * h1 + 4 * i)) >> (m8 + pixel * xdirect - hflip) % m8 * 4 * h1 + 4 * i) << (4 * colormode * (1 - i));}
                    if(palid != 0){
                        BGscan[l][(h - *BGHOFS[l]) & 0xFF] = ((tile & 0xF000) >> 8) * (1 - colormode) | palid;}}
                BGscanprior[priority << 2 | l] = l;}
            u8 layer[4];
            u8 qwerty = 0;
            for(u8 i = 0; i < 16; i++){
                if(BGscanprior[i] != 255){
                    layer[qwerty] = BGscanprior[i];
                    qwerty++;}}
            for(u32 px = 0; px < 256; px++){
                pxdata[px] = *BGPRAM;}
            switch(blendmode){
                case 0:{
                    if(WINstat[0] == 0 && WINstat[1] == 0){
                        for(u32 i = 0; i < 4; i++){
                            if(BGstat[layer[3 - i]]){
                                u8 colormode = ((*BGCNT[layer[i]] & 0x0080) >> 7);
                                for(u32 px = 0; px < 256; px++){
                                    if(BGscan[layer[3 - i]][px] & (0x10 << 4 * colormode) - 1){
                                        pxdata[px] = *(BGPRAM + BGscan[layer[3 - i]][px]);}}}}}
                    else{
                        for(u32 i = 0; i < 4; i++){
                            if(WINOUTBGstat[layer[3 - i]] && BGstat[layer[3 - i]]){
                                u8 colormode = ((*BGCNT[layer[i]] & 0x0080) >> 7);
                                for(u32 px = 0; px < 256; px++){
                                    if(BGscan[layer[3 - i]][px] & (0x10 << 4 * colormode) - 1){
                                        pxdata[px] = *(BGPRAM + BGscan[layer[3 - i]][px]);}}}}
                        for(u8 i = 0; i < 2; i++){
                            if(WINstat[1 - i]){
                                for(u8 j = WINVcoru[1 - i]; j != WINVcors[1 - i]; j++){
                                    if(j == scan){
                                        for(u8 k = WINHcorh[1 - i]; k != WINHcorm[1 - i]; k++){
                                            pxdata[k] = *BGPRAM;}
                                        for(u8 l = 0; l < 4; l++){
                                            if(WININBGstat[layer[3 - l]][1 - i] && BGstat[layer[3 - l]]){
                                                u8 colormode = ((*BGCNT[layer[i]] & 0x0080) >> 7);
                                                for(u8 k = WINHcorh[1 - i]; k != WINHcorm[1 - i]; k++){
                                                    if(BGscan[layer[3 - l]][k] & (0x10 << 4 * colormode) - 1){
                                                        pxdata[k] = *(BGPRAM + BGscan[layer[3 - l]][k]);}}}}}}}}}
                    break;}
                case 1:{
                    if(WINstat[0] == 0 && WINstat[1] == 0){
                        if(BGstat[layer[3]] && WINOUTBGstat[layer[3]]){
                            if((*BLDCNT & 0x2000) >> 13 && ((*BLDCNT & 0x0001 << layer[3]) >> layer[3])){
                                for(u16 r = 0; r < 256; r++){
                                    pxdata[r] = bldmath(*BGPRAM, *(BGPRAM + BGscan[layer[3]][r]) * (bool)(BGscan[layer[3]][r] & (0x10 << 4 * ((*BGCNT[layer[3]] & 0x0080) >> 7)) - 1), blendb, blenda, pxdata[r]);}}
                            else{
                                for(u16 r = 0; r < 256; r++){
                                    if(BGscan[layer[3]][r] & (0x10 << 4 * ((*BGCNT[layer[3]] & 0x0080) >> 7)) - 1){
                                        pxdata[r] = *(BGPRAM + BGscan[layer[3]][r]);}}}}
                        if(BGstat[layer[2]] && WINOUTBGstat[layer[2]]){
                            if(((*BLDCNT & 0x0100 << layer[3]) >> 8 + layer[3]) && ((*BLDCNT & 0x0001 << layer[2]) >> layer[2])){
                                for(u16 r = 0; r < 256; r++){
                                    pxdata[r] = bldmath(*(BGPRAM + BGscan[layer[3]][r]) * (bool)(BGscan[layer[3]][r] & (0x10 << 4 * ((*BGCNT[layer[3]] & 0x0080) >> 7)) - 1), *(BGPRAM + BGscan[layer[2]][r]) * (bool)(BGscan[layer[2]][r] & (0x10 << 4 * ((*BGCNT[layer[2]] & 0x0080) >> 7)) - 1), blendb, blenda, pxdata[r]);}}
                            else{
                                for(u16 r = 0; r < 256; r++){
                                    if(BGscan[layer[2]][r] & (0x10 << 4 * ((*BGCNT[layer[2]] & 0x0080) >> 7)) - 1){
                                        pxdata[r] = *(BGPRAM + BGscan[layer[2]][r]);}}}}
                        if(BGstat[layer[1]] && WINOUTBGstat[layer[1]]){
                            if(((*BLDCNT & 0x0100 << layer[2]) >> 8 + layer[2]) && ((*BLDCNT & 0x0001 << layer[1]) >> layer[1])){
                                for(u16 r = 0; r < 256; r++){
                                    pxdata[r] = bldmath(*(BGPRAM + BGscan[layer[2]][r]) * (bool)(BGscan[layer[2]][r] & (0x10 << 4 * ((*BGCNT[layer[2]] & 0x0080) >> 7)) - 1), *(BGPRAM + BGscan[layer[1]][r]) * (bool)(BGscan[layer[1]][r] & (0x10 << 4 * ((*BGCNT[layer[1]] & 0x0080) >> 7)) - 1), blendb, blenda, pxdata[r]);}}
                            else{
                                for(u16 r = 0; r < 256; r++){
                                    if(BGscan[layer[1]][r] & (0x10 << 4 * ((*BGCNT[layer[1]] & 0x0080) >> 7)) - 1){
                                        pxdata[r] = *(BGPRAM + BGscan[layer[1]][r]);}}}}
                        if(BGstat[layer[0]] && WINOUTBGstat[layer[0]]){
                            if(((*BLDCNT & 0x0100 << layer[1]) >> 8 + layer[1]) && ((*BLDCNT & 0x0001 << layer[0]) >> layer[0])){
                                for(u16 r = 0; r < 256; r++){
                                    pxdata[r] = bldmath(*(BGPRAM + BGscan[layer[1]][r]) * (bool)(BGscan[layer[1]][r] & (0x10 << 4 * ((*BGCNT[layer[1]] & 0x0080) >> 7)) - 1), *(BGPRAM + BGscan[layer[0]][r]) * (bool)(BGscan[layer[0]][r] & (0x10 << 4 * ((*BGCNT[layer[0]] & 0x0080) >> 7)) - 1), blendb, blenda, pxdata[r]);}}
                            else{
                                for(u16 r = 0; r < 256; r++){
                                    if(BGscan[layer[0]][r] & (0x10 << 4 * ((*BGCNT[layer[0]] & 0x0080) >> 7)) - 1){
                                        pxdata[r] = *(BGPRAM + BGscan[layer[0]][r]);}}}}}
                    else{
                        if(WINOUTBGstat[layer[3]] && BGstat[layer[3]]){
                            if((*BLDCNT & 0x2000) >> 13 && ((*BLDCNT & 0x0001 << layer[3]) >> layer[3]) && WINOUTBLDstat){
                                for(u16 r = 0; r < 256; r++){
                                    pxdata[r] = bldmath(*BGPRAM, *(BGPRAM + BGscan[layer[3]][r]) * (bool)(BGscan[layer[3]][r] & (0x10 << 4 * ((*BGCNT[layer[3]] & 0x0080) >> 7)) - 1), blendb, blenda, pxdata[r]);}}
                            else{
                                for(u16 r = 0; r < 256; r++){
                                    if(BGscan[layer[3]][r] & (0x10 << 4 * ((*BGCNT[layer[3]] & 0x0080) >> 7)) - 1){
                                        pxdata[r] = *(BGPRAM + BGscan[layer[3]][r]);}}}}
                        if(WINOUTBGstat[layer[2]] && BGstat[layer[2]]){
                            if(((*BLDCNT & 0x0100 << layer[3]) >> 8 + layer[3]) && ((*BLDCNT & 0x0001 << layer[2]) >> layer[2]) && WINOUTBLDstat){
                                for(u16 r = 0; r < 256; r++){
                                    pxdata[r] = bldmath(*(BGPRAM + BGscan[layer[3]][r]) * (bool)(BGscan[layer[3]][r] & (0x10 << 4 * ((*BGCNT[layer[3]] & 0x0080) >> 7)) - 1), *(BGPRAM + BGscan[layer[2]][r]) * (bool)(BGscan[layer[2]][r] & (0x10 << 4 * ((*BGCNT[layer[2]] & 0x0080) >> 7)) - 1), blendb, blenda, pxdata[r]);}}
                            else{
                                for(u16 r = 0; r < 256; r++){
                                    if(BGscan[layer[2]][r] & (0x10 << 4 * ((*BGCNT[layer[2]] & 0x0080) >> 7)) - 1){
                                        pxdata[r] = *(BGPRAM + BGscan[layer[2]][r]);}}}}
                        if(WINOUTBGstat[layer[1]] && BGstat[layer[1]]){
                            if(((*BLDCNT & 0x0100 << layer[2]) >> 8 + layer[2]) && ((*BLDCNT & 0x0001 << layer[1]) >> layer[1]) && WINOUTBLDstat){
                                for(u16 r = 0; r < 256; r++){
                                    pxdata[r] = bldmath(*(BGPRAM + BGscan[layer[2]][r]) * (bool)(BGscan[layer[2]][r] & (0x10 << 4 * ((*BGCNT[layer[2]] & 0x0080) >> 7)) - 1), *(BGPRAM + BGscan[layer[1]][r]) * (bool)(BGscan[layer[1]][r] & (0x10 << 4 * ((*BGCNT[layer[1]] & 0x0080) >> 7)) - 1), blendb, blenda, pxdata[r]);}}
                            else{
                                for(u16 r = 0; r < 256; r++){
                                    if(BGscan[layer[1]][r] & (0x10 << 4 * ((*BGCNT[layer[1]] & 0x0080) >> 7)) - 1){
                                        pxdata[r] = *(BGPRAM + BGscan[layer[1]][r]);}}}}
                        if(WINOUTBGstat[layer[0]] && BGstat[layer[0]]){
                            if(((*BLDCNT & 0x0100 << layer[1]) >> 8 + layer[1]) && ((*BLDCNT & 0x0001 << layer[0]) >> layer[0]) && WINOUTBLDstat){
                                for(u16 r = 0; r < 256; r++){
                                    pxdata[r] = bldmath(*(BGPRAM + BGscan[layer[1]][r]) * (bool)(BGscan[layer[1]][r] & (0x10 << 4 * ((*BGCNT[layer[1]] & 0x0080) >> 7)) - 1), *(BGPRAM + BGscan[layer[0]][r]) * (bool)(BGscan[layer[0]][r] & (0x10 << 4 * ((*BGCNT[layer[0]] & 0x0080) >> 7)) - 1), blendb, blenda, pxdata[r]);}}
                            else{
                                for(u16 r = 0; r < 256; r++){
                                    if(BGscan[layer[0]][r] & (0x10 << 4 * ((*BGCNT[layer[0]] & 0x0080) >> 7)) - 1){
                                        pxdata[r] = *(BGPRAM + BGscan[layer[0]][r]);}}}}
                        for(u8 i = 0; i < 2; i++){
                            if(WINstat[1 - i] != 0){
                                for(u8 j = WINVcoru[1 - i]; j != WINVcors[1 - i]; j++){
                                    if(j == scan){
                                        for(u16 r = WINHcorh[1 - i]; r != WINHcorm[1 - i]; r++){
                                            pxdata[r] = *BGPRAM;}
                                        if(WININBGstat[layer[3]][1 - i] && BGstat[layer[3]]){
                                            if((*BLDCNT & 0x2000) >> 13 && ((*BLDCNT & 0x0001 << layer[3]) >> layer[3]) && WININBLDstat[1 - i]){
                                                for(u16 r = WINHcorh[1 - i]; r != WINHcorm[1 - i]; r++){
                                                    pxdata[r] = bldmath(*BGPRAM, *(BGPRAM + BGscan[layer[3]][r]) * (bool)(BGscan[layer[3]][r] & (0x10 << 4 * ((*BGCNT[layer[3]] & 0x0080) >> 7)) - 1), blendb, blenda, pxdata[r]);}}
                                            else{
                                                for(u16 r = WINHcorh[1 - i]; r != WINHcorm[1 - i]; r++){
                                                    if(BGscan[layer[3]][r] & (0x10 << 4 * ((*BGCNT[layer[3]] & 0x0080) >> 7)) - 1){
                                                        pxdata[r] = *(BGPRAM + BGscan[layer[3]][r]);}}}}
                                        if(WININBGstat[layer[2]][1 - i] && BGstat[layer[2]]){
                                            if(((*BLDCNT & 0x0100 << layer[3]) >> 8 + layer[3]) && ((*BLDCNT & 0x0001 << layer[2]) >> layer[2]) && WININBLDstat[1 - i]){
                                                for(u16 r = WINHcorh[1 - i]; r != WINHcorm[1 - i]; r++){
                                                    pxdata[r] = bldmath(*(BGPRAM + BGscan[layer[3]][r]) * (bool)(BGscan[layer[3]][r] & (0x10 << 4 * ((*BGCNT[layer[3]] & 0x0080) >> 7)) - 1), *(BGPRAM + BGscan[layer[2]][r]) * (bool)(BGscan[layer[2]][r] & (0x10 << 4 * ((*BGCNT[layer[2]] & 0x0080) >> 7)) - 1), blendb, blenda, pxdata[r]);}}
                                            else{
                                                for(u16 r = WINHcorh[1 - i]; r != WINHcorm[1 - i]; r++){
                                                    if(BGscan[layer[2]][r] & (0x10 << 4 * ((*BGCNT[layer[2]] & 0x0080) >> 7)) - 1){
                                                        pxdata[r] = *(BGPRAM + BGscan[layer[2]][r]);}}}}
                                        if(WININBGstat[layer[1]][1 - i] && BGstat[layer[1]]){
                                            if(((*BLDCNT & 0x0100 << layer[2]) >> 8 + layer[2]) && ((*BLDCNT & 0x0001 << layer[1]) >> layer[1]) && WININBLDstat[1 - i]){
                                                for(u16 r = WINHcorh[1 - i]; r != WINHcorm[1 - i]; r++){
                                                    pxdata[r] = bldmath(*(BGPRAM + BGscan[layer[2]][r]) * (bool)(BGscan[layer[2]][r] & (0x10 << 4 * ((*BGCNT[layer[2]] & 0x0080) >> 7)) - 1), *(BGPRAM + BGscan[layer[1]][r]) * (bool)(BGscan[layer[1]][r] & (0x10 << 4 * ((*BGCNT[layer[1]] & 0x0080) >> 7)) - 1), blendb, blenda, pxdata[r]);}}
                                            else{
                                                for(u16 r = WINHcorh[1 - i]; r != WINHcorm[1 - i]; r++){
                                                    if(BGscan[layer[1]][r] & (0x10 << 4 * ((*BGCNT[layer[1]] & 0x0080) >> 7)) - 1){
                                                        pxdata[r] = *(BGPRAM + BGscan[layer[1]][r]);}}}}
                                        if(WININBGstat[layer[0]][1 - i] && BGstat[layer[0]]){
                                            if(((*BLDCNT & 0x0100 << layer[1]) >> 8 + layer[1]) && ((*BLDCNT & 0x0001 << layer[0]) >> layer[0]) && WININBLDstat[1 - i]){
                                                for(u16 r = WINHcorh[1 - i]; r != WINHcorm[1 - i]; r++){
                                                    pxdata[r] = bldmath(*(BGPRAM + BGscan[layer[1]][r]) * (bool)(BGscan[layer[1]][r] & (0x10 << 4 * ((*BGCNT[layer[1]] & 0x0080) >> 7)) - 1), *(BGPRAM + BGscan[layer[0]][r]) * (bool)(BGscan[layer[0]][r] & (0x10 << 4 * ((*BGCNT[layer[0]] & 0x0080) >> 7)) - 1), blendb, blenda, pxdata[r]);}}
                                            else{
                                                for(u16 r = WINHcorh[1 - i]; r != WINHcorm[1 - i]; r++){
                                                    if(BGscan[layer[0]][r] & (0x10 << 4 * ((*BGCNT[layer[0]] & 0x0080) >> 7)) - 1){
                                                        pxdata[r] = *(BGPRAM + BGscan[layer[0]][r]);}}}}}}}}}
                    break;}
                case 2:{
                    if(WINstat[0] == 0 && WINstat[1] == 0){
                        if(BGstat[layer[3]]){
                            if(((*BLDCNT & 0x0001 << layer[3]) >> layer[3])){
                                for(u16 r = 0; r < 256; r++){
                                    pxdata[r] = bldmath((0xFFFF - *(BGPRAM + BGscan[layer[3]][r])) * (bool)(BGscan[layer[3]][r] & (0x10 << 4 * ((*BGCNT[layer[3]] & 0x0080) >> 7)) - 1), *(BGPRAM + BGscan[layer[3]][r]) * (bool)(BGscan[layer[3]][r] & (0x10 << 4 * ((*BGCNT[layer[3]] & 0x0080) >> 7)) - 1), blendy, 16, pxdata[r]);}}
                            else{
                                for(u16 r = 0; r < 256; r++){
                                    if(BGscan[layer[3]][r] & (0x10 << 4 * ((*BGCNT[layer[3]] & 0x0080) >> 7)) - 1){
                                        pxdata[r] = *(BGPRAM + BGscan[layer[3]][r]);}}}}
                        if(BGstat[layer[2]]){
                            if(((*BLDCNT & 0x0001 << layer[2]) >> layer[2])){
                                for(u16 r = 0; r < 256; r++){
                                    pxdata[r] = bldmath((0xFFFF - *(BGPRAM + BGscan[layer[2]][r])) * (bool)(BGscan[layer[2]][r] & (0x10 << 4 * ((*BGCNT[layer[2]] & 0x0080) >> 7)) - 1), *(BGPRAM + BGscan[layer[2]][r]) * (bool)(BGscan[layer[2]][r] & (0x10 << 4 * ((*BGCNT[layer[2]] & 0x0080) >> 7)) - 1), blendy, 16, pxdata[r]);}}
                            else{
                                for(u16 r = 0; r < 256; r++){
                                    if(BGscan[layer[2]][r] & (0x10 << 4 * ((*BGCNT[layer[2]] & 0x0080) >> 7)) - 1){
                                        pxdata[r] = *(BGPRAM + BGscan[layer[2]][r]);}}}}
                        if(BGstat[layer[1]]){
                            if(((*BLDCNT & 0x0001 << layer[1]) >> layer[1])){
                                for(u16 r = 0; r < 256; r++){
                                    pxdata[r] = bldmath((0xFFFF - *(BGPRAM + BGscan[layer[1]][r])) * (bool)(BGscan[layer[1]][r] & (0x10 << 4 * ((*BGCNT[layer[1]] & 0x0080) >> 7)) - 1), *(BGPRAM + BGscan[layer[1]][r]) * (bool)(BGscan[layer[1]][r] & (0x10 << 4 * ((*BGCNT[layer[1]] & 0x0080) >> 7)) - 1), blendy, 16, pxdata[r]);}}
                            else{
                                for(u16 r = 0; r < 256; r++){
                                    if(BGscan[layer[1]][r] & (0x10 << 4 * ((*BGCNT[layer[1]] & 0x0080) >> 7)) - 1){
                                        pxdata[r] = *(BGPRAM + BGscan[layer[1]][r]);}}}}
                        if(BGstat[layer[0]]){
                            if(((*BLDCNT & 0x0001 << layer[0]) >> layer[0])){
                                for(u16 r = 0; r < 256; r++){
                                    pxdata[r] = bldmath((0xFFFF - *(BGPRAM + BGscan[layer[0]][r])) * (bool)(BGscan[layer[0]][r] & (0x10 << 4 * ((*BGCNT[layer[0]] & 0x0080) >> 7)) - 1), *(BGPRAM + BGscan[layer[0]][r]) * (bool)(BGscan[layer[0]][r] & (0x10 << 4 * ((*BGCNT[layer[0]] & 0x0080) >> 7)) - 1), blendy, 16, pxdata[r]);}}
                            else{
                                for(u16 r = 0; r < 256; r++){
                                    if(BGscan[layer[0]][r] & (0x10 << 4 * ((*BGCNT[layer[0]] & 0x0080) >> 7)) - 1){
                                        pxdata[r] = *(BGPRAM + BGscan[layer[0]][r]);}}}}}
                    else{
                        if(WINOUTBGstat[layer[3]] && BGstat[layer[3]]){
                            if((*BLDCNT & 0x2000) >> 13 && ((*BLDCNT & 0x0001 << layer[3]) >> layer[3]) && WINOUTBLDstat){
                                for(u16 r = 0; r < 256; r++){
                                    pxdata[r] = bldmath((0xFFFF - *(BGPRAM + BGscan[layer[3]][r])) * (bool)(BGscan[layer[3]][r] & (0x10 << 4 * ((*BGCNT[layer[3]] & 0x0080) >> 7)) - 1), *(BGPRAM + BGscan[layer[3]][r]) * (bool)(BGscan[layer[3]][r] & (0x10 << 4 * ((*BGCNT[layer[3]] & 0x0080) >> 7)) - 1), blendy, 16, pxdata[r]);}}
                            else{
                                for(u16 r = 0; r < 256; r++){
                                    if(BGscan[layer[3]][r] & (0x10 << 4 * ((*BGCNT[layer[3]] & 0x0080) >> 7)) - 1){
                                        pxdata[r] = *(BGPRAM + BGscan[layer[3]][r]);}}}}
                        if(WINOUTBGstat[layer[2]] && BGstat[layer[2]]){
                            if(((*BLDCNT & 0x0100 << layer[3]) >> 8 + layer[3]) && ((*BLDCNT & 0x0001 << layer[2]) >> layer[2]) && WINOUTBLDstat){
                                for(u16 r = 0; r < 256; r++){
                                    pxdata[r] = bldmath((0xFFFF - *(BGPRAM + BGscan[layer[2]][r])) * (bool)(BGscan[layer[2]][r] & (0x10 << 4 * ((*BGCNT[layer[2]] & 0x0080) >> 7)) - 1), *(BGPRAM + BGscan[layer[2]][r]) * (bool)(BGscan[layer[2]][r] & (0x10 << 4 * ((*BGCNT[layer[2]] & 0x0080) >> 7)) - 1), blendy, 16, pxdata[r]);}}
                            else{
                                for(u16 r = 0; r < 256; r++){
                                    if(BGscan[layer[2]][r] & (0x10 << 4 * ((*BGCNT[layer[2]] & 0x0080) >> 7)) - 1){
                                        pxdata[r] = *(BGPRAM + BGscan[layer[2]][r]);}}}}
                        if(WINOUTBGstat[layer[1]] && BGstat[layer[1]]){
                            if(((*BLDCNT & 0x0100 << layer[2]) >> 8 + layer[2]) && ((*BLDCNT & 0x0001 << layer[1]) >> layer[1]) && WINOUTBLDstat){
                                for(u16 r = 0; r < 256; r++){
                                    pxdata[r] = bldmath((0xFFFF - *(BGPRAM + BGscan[layer[1]][r])) * (bool)(BGscan[layer[1]][r] & (0x10 << 4 * ((*BGCNT[layer[1]] & 0x0080) >> 7)) - 1), *(BGPRAM + BGscan[layer[1]][r]) * (bool)(BGscan[layer[1]][r] & (0x10 << 4 * ((*BGCNT[layer[1]] & 0x0080) >> 7)) - 1), blendy, 16, pxdata[r]);}}
                            else{
                                for(u16 r = 0; r < 256; r++){
                                    if(BGscan[layer[1]][r] & (0x10 << 4 * ((*BGCNT[layer[1]] & 0x0080) >> 7)) - 1){
                                        pxdata[r] = *(BGPRAM + BGscan[layer[1]][r]);}}}}
                        if(WINOUTBGstat[layer[0]] && BGstat[layer[0]]){
                            if(((*BLDCNT & 0x0100 << layer[1]) >> 8 + layer[1]) && ((*BLDCNT & 0x0001 << layer[0]) >> layer[0]) && WINOUTBLDstat){
                                for(u16 r = 0; r < 256; r++){
                                    pxdata[r] = bldmath((0xFFFF - *(BGPRAM + BGscan[layer[0]][r])) * (bool)(BGscan[layer[0]][r] & (0x10 << 4 * ((*BGCNT[layer[0]] & 0x0080) >> 7)) - 1), *(BGPRAM + BGscan[layer[0]][r]) * (bool)(BGscan[layer[0]][r] & (0x10 << 4 * ((*BGCNT[layer[0]] & 0x0080) >> 7)) - 1), blendy, 16, pxdata[r]);}}
                            else{
                                for(u16 r = 0; r < 256; r++){
                                    if(BGscan[layer[0]][r] & (0x10 << 4 * ((*BGCNT[layer[0]] & 0x0080) >> 7)) - 1){
                                        pxdata[r] = *(BGPRAM + BGscan[layer[0]][r]);}}}}
                        for(u8 i = 0; i < 2; i++){
                            if(WINstat[1 - i] != 0){
                                for(u8 j = WINVcoru[1 - i]; j != WINVcors[1 - i]; j++){
                                    if(j == scan){
                                        for(u16 r = WINHcorh[1 - i]; r != WINHcorm[1 - i]; r++){
                                            pxdata[r] = *BGPRAM;}
                                        if(WININBGstat[layer[3]][1 - i] && BGstat[layer[3]]){
                                            if((*BLDCNT & 0x2000) >> 13 && ((*BLDCNT & 0x0001 << layer[3]) >> layer[3]) && WININBLDstat[1 - i]){
                                                for(u16 r = WINHcorh[1 - i]; r != WINHcorm[1 - i]; r++){
                                                    pxdata[r] = bldmath((0xFFFF - *(BGPRAM + BGscan[layer[3]][r])) * (bool)(BGscan[layer[3]][r] & (0x10 << 4 * ((*BGCNT[layer[3]] & 0x0080) >> 7)) - 1), *(BGPRAM + BGscan[layer[3]][r]) * (bool)(BGscan[layer[3]][r] & (0x10 << 4 * ((*BGCNT[layer[3]] & 0x0080) >> 7)) - 1), blendy, 16, pxdata[r]);}}
                                            else{
                                                for(u16 r = WINHcorh[1 - i]; r != WINHcorm[1 - i]; r++){
                                                    if(BGscan[layer[3]][r] & (0x10 << 4 * ((*BGCNT[layer[3]] & 0x0080) >> 7)) - 1){
                                                        pxdata[r] = *(BGPRAM + BGscan[layer[3]][r]);}}}}
                                        if(WININBGstat[layer[2]][1 - i] && BGstat[layer[2]]){
                                            if(((*BLDCNT & 0x0100 << layer[3]) >> 8 + layer[3]) && ((*BLDCNT & 0x0001 << layer[2]) >> layer[2]) && WININBLDstat[1 - i]){
                                                for(u16 r = WINHcorh[1 - i]; r != WINHcorm[1 - i]; r++){
                                                    pxdata[r] = bldmath((0xFFFF - *(BGPRAM + BGscan[layer[2]][r])) * (bool)(BGscan[layer[2]][r] & (0x10 << 4 * ((*BGCNT[layer[2]] & 0x0080) >> 7)) - 1), *(BGPRAM + BGscan[layer[2]][r]) * (bool)(BGscan[layer[2]][r] & (0x10 << 4 * ((*BGCNT[layer[2]] & 0x0080) >> 7)) - 1), blendy, 16, pxdata[r]);}}
                                            else{
                                                for(u16 r = WINHcorh[1 - i]; r != WINHcorm[1 - i]; r++){
                                                    if(BGscan[layer[2]][r] & (0x10 << 4 * ((*BGCNT[layer[2]] & 0x0080) >> 7)) - 1){
                                                        pxdata[r] = *(BGPRAM + BGscan[layer[2]][r]);}}}}
                                        if(WININBGstat[layer[1]][1 - i] && BGstat[layer[1]]){
                                            if(((*BLDCNT & 0x0100 << layer[2]) >> 8 + layer[2]) && ((*BLDCNT & 0x0001 << layer[1]) >> layer[1]) && WININBLDstat[1 - i]){
                                                for(u16 r = WINHcorh[1 - i]; r != WINHcorm[1 - i]; r++){
                                                    pxdata[r] = bldmath((0xFFFF - *(BGPRAM + BGscan[layer[1]][r])) * (bool)(BGscan[layer[1]][r] & (0x10 << 4 * ((*BGCNT[layer[1]] & 0x0080) >> 7)) - 1), *(BGPRAM + BGscan[layer[1]][r]) * (bool)(BGscan[layer[1]][r] & (0x10 << 4 * ((*BGCNT[layer[1]] & 0x0080) >> 7)) - 1), blendy, 16, pxdata[r]);}}
                                            else{
                                                for(u16 r = WINHcorh[1 - i]; r != WINHcorm[1 - i]; r++){
                                                    if(BGscan[layer[1]][r] & (0x10 << 4 * ((*BGCNT[layer[1]] & 0x0080) >> 7)) - 1){
                                                        pxdata[r] = *(BGPRAM + BGscan[layer[1]][r]);}}}}
                                        if(WININBGstat[layer[0]][1 - i] && BGstat[layer[0]]){
                                            if(((*BLDCNT & 0x0100 << layer[1]) >> 8 + layer[1]) && ((*BLDCNT & 0x0001 << layer[0]) >> layer[0]) && WININBLDstat[1 - i]){
                                                for(u16 r = WINHcorh[1 - i]; r != WINHcorm[1 - i]; r++){
                                                    pxdata[r] = bldmath((0xFFFF - *(BGPRAM + BGscan[layer[0]][r])) * (bool)(BGscan[layer[0]][r] & (0x10 << 4 * ((*BGCNT[layer[0]] & 0x0080) >> 7)) - 1), *(BGPRAM + BGscan[layer[0]][r]) * (bool)(BGscan[layer[0]][r] & (0x10 << 4 * ((*BGCNT[layer[0]] & 0x0080) >> 7)) - 1), blendy, 16, pxdata[r]);}}
                                            else{
                                                for(u16 r = WINHcorh[1 - i]; r != WINHcorm[1 - i]; r++){
                                                    if(BGscan[layer[0]][r] & (0x10 << 4 * ((*BGCNT[layer[0]] & 0x0080) >> 7)) - 1){
                                                        pxdata[r] = *(BGPRAM + BGscan[layer[0]][r]);}}}}}}}}}
                    break;}
                case 3:{
                    if(WINstat[0] == 0 && WINstat[1] == 0){
                        if(BGstat[layer[3]] && BGstat[layer[3]]){
                            if(((*BLDCNT & 0x0001 << layer[3]) >> layer[3])){
                                for(u16 r = 0; r < 256; r++){
                                    pxdata[r] = bldmath(*(BGPRAM + BGscan[layer[3]][r]) * (bool)(BGscan[layer[3]][r] & (0x10 << 4 * ((*BGCNT[layer[3]] & 0x0080) >> 7)) - 1), *(BGPRAM + BGscan[layer[3]][r]) * (bool)(BGscan[layer[3]][r] & (0x10 << 4 * ((*BGCNT[layer[3]] & 0x0080) >> 7)) - 1), -blendy, 16, pxdata[r]);}}
                            else{
                                for(u16 r = 0; r < 256; r++){
                                    if(BGscan[layer[3]][r] & (0x10 << 4 * ((*BGCNT[layer[3]] & 0x0080) >> 7)) - 1){
                                        pxdata[r] = *(BGPRAM + BGscan[layer[3]][r]);}}}}
                        if(BGstat[layer[2]] && BGstat[layer[2]]){
                            if(((*BLDCNT & 0x0001 << layer[2]) >> layer[2])){
                                for(u16 r = 0; r < 256; r++){
                                    pxdata[r] = bldmath(*(BGPRAM + BGscan[layer[2]][r]) * (bool)(BGscan[layer[2]][r] & (0x10 << 4 * ((*BGCNT[layer[2]] & 0x0080) >> 7)) - 1), *(BGPRAM + BGscan[layer[2]][r]) * (bool)(BGscan[layer[2]][r] & (0x10 << 4 * ((*BGCNT[layer[2]] & 0x0080) >> 7)) - 1), -blendy, 16, pxdata[r]);}}
                            else{
                                for(u16 r = 0; r < 256; r++){
                                    if(BGscan[layer[2]][r] & (0x10 << 4 * ((*BGCNT[layer[2]] & 0x0080) >> 7)) - 1){
                                        pxdata[r] = *(BGPRAM + BGscan[layer[2]][r]);}}}}
                        if(BGstat[layer[1]] && BGstat[layer[1]]){
                            if(((*BLDCNT & 0x0001 << layer[1]) >> layer[1])){
                                for(u16 r = 0; r < 256; r++){
                                    pxdata[r] = bldmath(*(BGPRAM + BGscan[layer[1]][r]) * (bool)(BGscan[layer[1]][r] & (0x10 << 4 * ((*BGCNT[layer[1]] & 0x0080) >> 7)) - 1), *(BGPRAM + BGscan[layer[1]][r]) * (bool)(BGscan[layer[1]][r] & (0x10 << 4 * ((*BGCNT[layer[1]] & 0x0080) >> 7)) - 1), -blendy, 16, pxdata[r]);}}
                            else{
                                for(u16 r = 0; r < 256; r++){
                                    if(BGscan[layer[1]][r] & (0x10 << 4 * ((*BGCNT[layer[1]] & 0x0080) >> 7)) - 1){
                                        pxdata[r] = *(BGPRAM + BGscan[layer[1]][r]);}}}}
                        if(BGstat[layer[0]] && BGstat[layer[0]]){
                            if(((*BLDCNT & 0x0001 << layer[0]) >> layer[0])){
                                for(u16 r = 0; r < 256; r++){
                                    pxdata[r] = bldmath(*(BGPRAM + BGscan[layer[0]][r]) * (bool)(BGscan[layer[0]][r] & (0x10 << 4 * ((*BGCNT[layer[0]] & 0x0080) >> 7)) - 1), *(BGPRAM + BGscan[layer[0]][r]) * (bool)(BGscan[layer[0]][r] & (0x10 << 4 * ((*BGCNT[layer[0]] & 0x0080) >> 7)) - 1), -blendy, 16, pxdata[r]);}}
                            else{
                                for(u16 r = 0; r < 256; r++){
                                    if(BGscan[layer[0]][r] & (0x10 << 4 * ((*BGCNT[layer[0]] & 0x0080) >> 7)) - 1){
                                        pxdata[r] = *(BGPRAM + BGscan[layer[0]][r]);}}}}}
                    else{
                        if(WINOUTBGstat[layer[3]] && BGstat[layer[3]]){
                            if(((*BLDCNT & 0x0001 << layer[3]) >> layer[3]) && WINOUTBLDstat){
                                for(u16 r = 0; r < 256; r++){
                                    pxdata[r] = bldmath(*(BGPRAM + BGscan[layer[3]][r]) * (bool)(BGscan[layer[3]][r] & (0x10 << 4 * ((*BGCNT[layer[3]] & 0x0080) >> 7)) - 1), *(BGPRAM + BGscan[layer[3]][r]) * (bool)(BGscan[layer[3]][r] & (0x10 << 4 * ((*BGCNT[layer[3]] & 0x0080) >> 7)) - 1), -blendy, 16, pxdata[r]);}}
                            else{
                                for(u16 r = 0; r < 256; r++){
                                    if(BGscan[layer[3]][r] & (0x10 << 4 * ((*BGCNT[layer[3]] & 0x0080) >> 7)) - 1){
                                        pxdata[r] = *(BGPRAM + BGscan[layer[3]][r]);}}}}
                        if(WINOUTBGstat[layer[2]] && BGstat[layer[2]]){
                            if(((*BLDCNT & 0x0001 << layer[2]) >> layer[2]) && WINOUTBLDstat){
                                for(u16 r = 0; r < 256; r++){
                                    pxdata[r] = bldmath(*(BGPRAM + BGscan[layer[2]][r]) * (bool)(BGscan[layer[2]][r] & (0x10 << 4 * ((*BGCNT[layer[2]] & 0x0080) >> 7)) - 1), *(BGPRAM + BGscan[layer[2]][r]) * (bool)(BGscan[layer[2]][r] & (0x10 << 4 * ((*BGCNT[layer[2]] & 0x0080) >> 7)) - 1), -blendy, 16, pxdata[r]);}}
                            else{
                                for(u16 r = 0; r < 256; r++){
                                    if(BGscan[layer[2]][r] & (0x10 << 4 * ((*BGCNT[layer[2]] & 0x0080) >> 7)) - 1){
                                        pxdata[r] = *(BGPRAM + BGscan[layer[2]][r]);}}}}
                        if(WINOUTBGstat[layer[1]] && BGstat[layer[1]]){
                            if(((*BLDCNT & 0x0001 << layer[1]) >> layer[1]) && WINOUTBLDstat){
                                for(u16 r = 0; r < 256; r++){
                                    pxdata[r] = bldmath(*(BGPRAM + BGscan[layer[1]][r]) * (bool)(BGscan[layer[1]][r] & (0x10 << 4 * ((*BGCNT[layer[1]] & 0x0080) >> 7)) - 1), *(BGPRAM + BGscan[layer[1]][r]) * (bool)(BGscan[layer[1]][r] & (0x10 << 4 * ((*BGCNT[layer[1]] & 0x0080) >> 7)) - 1), -blendy, 16, pxdata[r]);}}
                            else{
                                for(u16 r = 0; r < 256; r++){
                                    if(BGscan[layer[1]][r] & (0x10 << 4 * ((*BGCNT[layer[1]] & 0x0080) >> 7)) - 1){
                                        pxdata[r] = *(BGPRAM + BGscan[layer[1]][r]);}}}}
                        if(WINOUTBGstat[layer[0]] && BGstat[layer[0]]){
                            if(((*BLDCNT & 0x0001 << layer[0]) >> layer[0]) && WINOUTBLDstat){
                                for(u16 r = 0; r < 256; r++){
                                    pxdata[r] = bldmath(*(BGPRAM + BGscan[layer[0]][r]) * (bool)(BGscan[layer[0]][r] & (0x10 << 4 * ((*BGCNT[layer[0]] & 0x0080) >> 7)) - 1), *(BGPRAM + BGscan[layer[0]][r]) * (bool)(BGscan[layer[0]][r] & (0x10 << 4 * ((*BGCNT[layer[0]] & 0x0080) >> 7)) - 1), -blendy, 16, pxdata[r]);}}
                            else{
                                for(u16 r = 0; r < 256; r++){
                                    if(BGscan[layer[0]][r] & (0x10 << 4 * ((*BGCNT[layer[0]] & 0x0080) >> 7)) - 1){
                                        pxdata[r] = *(BGPRAM + BGscan[layer[0]][r]);}}}}
                        for(u8 i = 0; i < 2; i++){
                            if(WINstat[1 - i] != 0){
                                for(u8 j = WINVcoru[1 - i]; j != WINVcors[1 - i]; j++){
                                    if(j == scan){
                                        if(WININBGstat[layer[3]][1 - i] && BGstat[layer[3]]){
                                            if(((*BLDCNT & 0x0001 << layer[3]) >> layer[3]) && WININBLDstat[1 - i]){
                                                for(u16 r = WINHcorh[1 - i]; r != WINHcorm[1 - i]; r++){
                                                    pxdata[r] = bldmath(*(BGPRAM + BGscan[layer[3]][r]) * (bool)(BGscan[layer[3]][r] & (0x10 << 4 * ((*BGCNT[layer[3]] & 0x0080) >> 7)) - 1), *(BGPRAM + BGscan[layer[3]][r]) * (bool)(BGscan[layer[3]][r] & (0x10 << 4 * ((*BGCNT[layer[3]] & 0x0080) >> 7)) - 1), -blendy, 16, pxdata[r]);}}
                                            else{
                                                for(u16 r = WINHcorh[1 - i]; r != WINHcorm[1 - i]; r++){
                                                    if(BGscan[layer[3]][r] & (0x10 << 4 * ((*BGCNT[layer[3]] & 0x0080) >> 7)) - 1){
                                                        pxdata[r] = *(BGPRAM + BGscan[layer[3]][r]);}}}}
                                        if(WININBGstat[layer[2]][1 - i] && BGstat[layer[2]]){
                                            if(((*BLDCNT & 0x0001 << layer[2]) >> layer[2]) && WININBLDstat[1 - i]){
                                                for(u16 r = WINHcorh[1 - i]; r != WINHcorm[1 - i]; r++){
                                                    pxdata[r] = bldmath(*(BGPRAM + BGscan[layer[2]][r]) * (bool)(BGscan[layer[2]][r] & (0x10 << 4 * ((*BGCNT[layer[2]] & 0x0080) >> 7)) - 1), *(BGPRAM + BGscan[layer[2]][r]) * (bool)(BGscan[layer[2]][r] & (0x10 << 4 * ((*BGCNT[layer[2]] & 0x0080) >> 7)) - 1), -blendy, 16, pxdata[r]);}}
                                            else{
                                                for(u16 r = WINHcorh[1 - i]; r != WINHcorm[1 - i]; r++){
                                                    if(BGscan[layer[2]][r] & (0x10 << 4 * ((*BGCNT[layer[2]] & 0x0080) >> 7)) - 1){
                                                        pxdata[r] = *(BGPRAM + BGscan[layer[2]][r]);}}}}
                                        if(WININBGstat[layer[1]][1 - i] && BGstat[layer[1]]){
                                            if(((*BLDCNT & 0x0001 << layer[1]) >> layer[1]) && WININBLDstat[1 - i]){
                                                for(u16 r = WINHcorh[1 - i]; r != WINHcorm[1 - i]; r++){
                                                    pxdata[r] = bldmath(*(BGPRAM + BGscan[layer[1]][r]) * (bool)(BGscan[layer[1]][r] & (0x10 << 4 * ((*BGCNT[layer[1]] & 0x0080) >> 7)) - 1), *(BGPRAM + BGscan[layer[1]][r]) * (bool)(BGscan[layer[1]][r] & (0x10 << 4 * ((*BGCNT[layer[1]] & 0x0080) >> 7)) - 1), -blendy, 16, pxdata[r]);}}
                                            else{
                                                for(u16 r = WINHcorh[1 - i]; r != WINHcorm[1 - i]; r++){
                                                    if(BGscan[layer[1]][r] & (0x10 << 4 * ((*BGCNT[layer[1]] & 0x0080) >> 7)) - 1){
                                                        pxdata[r] = *(BGPRAM + BGscan[layer[1]][r]);}}}}
                                        if(WININBGstat[layer[0]][1 - i] && BGstat[layer[0]]){
                                            if(((*BLDCNT & 0x0001 << layer[0]) >> layer[0]) && WININBLDstat[1 - i]){
                                                for(u16 r = WINHcorh[1 - i]; r != WINHcorm[1 - i]; r++){
                                                    pxdata[r] = bldmath(*(BGPRAM + BGscan[layer[0]][r]) * (bool)(BGscan[layer[0]][r] & (0x10 << 4 * ((*BGCNT[layer[0]] & 0x0080) >> 7)) - 1), *(BGPRAM + BGscan[layer[0]][r]) * (bool)(BGscan[layer[0]][r] & (0x10 << 4 * ((*BGCNT[layer[0]] & 0x0080) >> 7)) - 1), -blendy, 16, pxdata[r]);}}
                                            else{
                                                for(u16 r = WINHcorh[1 - i]; r != WINHcorm[1 - i]; r++){
                                                    if(BGscan[layer[0]][r] & (0x10 << 4 * ((*BGCNT[layer[0]] & 0x0080) >> 7)) - 1){
                                                        pxdata[r] = *(BGPRAM + BGscan[layer[0]][r]);}}}}}}}}}
                    break;}
                default:{}}
            break;}
        case 1:{
            for(int k = 0; k < 3; k++){
                for(int k = 0; k < 4; k++){
                u8 BGy = (*BGCNT[3 - k] & 0b1000000000000000) >> 15,
                BGx = (*BGCNT[3 - k] & 0b0100000000000000) >> 14,
                AreaV = (*BGCNT[3 - k] & 0b0010000000000000) >> 13,
                screenblock = (*BGCNT[3 - k] & 0b0001111100000000) >> 8,
                colormode = (*BGCNT[3 - k] & 0b0000000010000000) >> 7,
                mosaic = (*BGCNT[3 - k] & 0b0000000001000000) >> 6,
                charblock = (*BGCNT[3 - k] & 0b0000000000001100) >> 2,
                priority = (*BGCNT[3 - k] & 0b0000000000000011);
                u16 line = (scan + *BGVOFS[3 - k]) % (0x100 << BGy);
                u16 BGrow = line / (8 + 8 * mosaic * BGMOSV);
                u16 tilerow = line % (8 * (1 + mosaic * BGMOSV)) / (1 + mosaic * BGMOSV);
                for(int h = 0; h < 32  / (1 + mosaic * BGMOSH); h++){
                    u16 tile = *(SDB[screenblock] + h + BGrow * 0x20);
                    u8 palette = (tile & 0xF000) >> 12, hflip = (tile & 0x0800) >> 11, vflip = (tile & 0x0400) >> 10;
                    u16 tileid = tile & 0x03FF;
                    short xdirect = hflip * -2 + 1;
                    short ydirect = vflip * -2 + 1;
                    u32 row = *(CDB[charblock] + (8 + tilerow * ydirect - vflip) % 8 + tileid * 8);
                    for(int i = 0; i < 8 * (1 + mosaic * BGMOSH); i++){
                        u8 palid = (row & (0xF << (8 + i * xdirect / (1 + mosaic * BGMOSH) - hflip) % 8 * 4)) >> (8 + i * xdirect / (1 + mosaic * BGMOSH) - hflip) % 8 * 4;
                        if(palid != 0){
                            pxdata[((unsigned)(i + 8 * h * (1 + mosaic * BGMOSH) - *BGHOFS[3 - k]) % 0x100)] = *(BGpal[palette] + palid);}}}}}
            break;}
        default:{}}
    for(int i = 0; i < 256; i++){
        sprScreen.SetPixel(i, scan, uint1632(pxdata[i]));}}
void DrawPixel();

