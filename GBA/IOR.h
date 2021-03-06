uint8_t* IOR = AGBmem + 0x04000000;
u16* DISPCNT = (u16*)IOR + 0x0000;
u16* CLRSWAP = (u16*)IOR + 0x002;
u16* DISPSTAT = (u16*)IOR + 0x004;
u16* VCOUNT = (u16*)IOR + 0x006;
u16* BG0CNT = (u16*)IOR + 0x008;
u16* BG1CNT = (u16*)IOR + 0x00A;
u16* BG2CNT = (u16*)IOR + 0x00C;
u16* BG3CNT = (u16*)IOR + 0x00E;
u16* BGCNT[4] = {BG0CNT, BG1CNT, BG2CNT, BG3CNT};
u16* BG0HOFS = (u16*)IOR + 0x010;
u16* BG0VOFS = (u16*)IOR + 0x012;
u16* BG1HOFS = (u16*)IOR + 0x014;
u16* BG1VOFS = (u16*)IOR + 0x016;
u16* BG2HOFS = (u16*)IOR + 0x018;
u16* BG2VOFS = (u16*)IOR + 0x01A;
u16* BG3HOFS = (u16*)IOR + 0x01C;
u16* BG3VOFS = (u16*)IOR + 0x01E;
u16* BGHOFS[4] = {BG0HOFS, BG1HOFS, BG2HOFS, BG3HOFS};
u16* BGVOFS[4] = {BG0VOFS, BG1VOFS, BG2VOFS, BG3VOFS};
u16* BG2PA = (u16*)IOR + 0x020;
u16* BG2PB = (u16*)IOR + 0x022;
u16* BG2PC = (u16*)IOR + 0x024;
u16* BG2PD = (u16*)IOR + 0x026;
u16* BG2X_L = (u16*)IOR + 0x028;
u16* BG2X_H = (u16*)IOR + 0x02A;
u16* BG2Y_L = (u16*)IOR + 0x02C;
u16* BG2Y_H = (u16*)IOR + 0x02E;
u16* BG3PA = (u16*)IOR + 0x030;
u16* BG3PB = (u16*)IOR + 0x032;
u16* BG3PC = (u16*)IOR + 0x034;
u16* BG3PD = (u16*)IOR + 0x036;
u16* BG3X_L = (u16*)IOR + 0x038;
u16* BG3X_H = (u16*)IOR + 0x03A;
u16* BG3Y_L = (u16*)IOR + 0x03C;
u16* BG3Y_H = (u16*)IOR + 0x03E;
u16* BGPA[2] = {BG2PA, BG3PA};
u16* BGPB[2] = {BG2PB, BG3PB};
u16* BGPC[2] = {BG2PC, BG3PC};
u16* BGPD[2] = {BG2PD, BG3PD};
u16* BGX_L[2] = {BG2X_L, BG3X_L};
u16* BGX_H[2] = {BG2X_H, BG3X_H};
u16* BGY_L[2] = {BG2Y_L, BG3Y_L};
u16* BGY_H[2] = {BG2Y_H, BG3Y_H};
u16* WIN0H = (u16*)IOR + 0x040;
u16* WIN1H = (u16*)IOR + 0x042;
u16* WINH[2] = {WIN0H, WIN1H};
u16* WIN0V = (u16*)IOR + 0x044;
u16* WIN1V = (u16*)IOR + 0x046;
u16* WINV[2] = {WIN0V, WIN1V};
u16* WININ = (u16*)IOR + 0x048;
u16* WINOUT = (u16*)IOR + 0x04A;
u16* MOSAIC = (u16*)IOR + 0x04C;

u16* BLDCNT = (u16*)IOR + 0x050;
u16* BLDALPHA = (u16*)IOR + 0x052;
u16* BLDY = (u16*)IOR + 0x054;

u16* SOUND1CNT_L = (u16*)IOR + 0x060;
u16* SOUND1CNT_H = (u16*)IOR + 0x062;
u16* SOUND1CNT_X = (u16*)IOR + 0x064;
u16* SOUND2CNT_L = (u16*)IOR + 0x068;
u16* SOUND2CNT_H = (u16*)IOR + 0x06C;

u16* SOUND3CNT_L = (u16*)IOR + 0x070;
u16* SOUND3CNT_H = (u16*)IOR + 0x072;
u16* SOUND3CNT_X = (u16*)IOR + 0x074;

u16* SOUND4CNT_L = (u16*)IOR + 0x078;

u16* SOUND4CNT_H = (u16*)IOR + 0x07C;

u16* SOUNDCNT_L = (u16*)IOR + 0x080;
u16* SOUNDCNT_H = (u16*)IOR + 0x082;
u16* SOUNDCNT_X = (u16*)IOR + 0x084;

u16* SOUNDBIAS = (u16*)IOR + 0x088;

u16* WAVE_RAM0_L = (u16*)IOR + 0x090;
u16* WAVE_RAM0_H = (u16*)IOR + 0x092;
u16* WAVE_RAM1_L = (u16*)IOR + 0x094;
u16* WAVE_RAM1_H = (u16*)IOR + 0x096;
u16* WAVE_RAM2_L = (u16*)IOR + 0x098;
u16* WAVE_RAM2_H = (u16*)IOR + 0x09A;
u16* WAVE_RAM3_L = (u16*)IOR + 0x09C;
u16* WAVE_RAM3_H = (u16*)IOR + 0x09E;
u16* WAVE_RAM_L[4] = {WAVE_RAM0_L, WAVE_RAM1_L, WAVE_RAM2_L, WAVE_RAM3_L};
u16* WAVE_RAM_H[4] = {WAVE_RAM0_H, WAVE_RAM1_H, WAVE_RAM2_H, WAVE_RAM3_H};

u16* FIFO_A_L = (u16*)IOR + 0x0A0;
u16* FIFO_A_H = (u16*)IOR + 0x0A2;
u16* FIFO_B_L = (u16*)IOR + 0x0A4;
u16* FIFO_B_H = (u16*)IOR + 0x0A6;

u16* DMA0SAD_L = (u16*)IOR + 0x0B0;
u16* DMA0SAD_H = (u16*)IOR + 0x0B2;
u16* DMA0DAD_L = (u16*)IOR + 0x0B4;
u16* DMA0DAD_H = (u16*)IOR + 0x0B6;
u16* DMA0CNT_L = (u16*)IOR + 0x0B8;
u16* DMA0CNT_H = (u16*)IOR + 0x0BA;
u16* DMA1SAD_L = (u16*)IOR + 0x0BC;
u16* DMA1SAD_H = (u16*)IOR + 0x0BE;
u16* DMA1DAD_L = (u16*)IOR + 0x0C0;
u16* DMA1DAD_H = (u16*)IOR + 0x0C2;
u16* DMA1CNT_L = (u16*)IOR + 0x0C4;
u16* DMA1CNT_H = (u16*)IOR + 0x0C6;
u16* DMA2SAD_L = (u16*)IOR + 0x0C8;
u16* DMA2SAD_H = (u16*)IOR + 0x0CA;
u16* DMA2DAD_L = (u16*)IOR + 0x0CC;
u16* DMA2DAD_H = (u16*)IOR + 0x0CE;
u16* DMA2CNT_L = (u16*)IOR + 0x0D0;
u16* DMA2CNT_H = (u16*)IOR + 0x0D2;
u16* DMA3SAD_L = (u16*)IOR + 0x0D4;
u16* DMA3SAD_H = (u16*)IOR + 0x0D6;
u16* DMA3DAD_L = (u16*)IOR + 0x0D8;
u16* DMA3DAD_H = (u16*)IOR + 0x0DA;
u16* DMA3CNT_L = (u16*)IOR + 0x0DC;
u16* DMA3CNT_H = (u16*)IOR + 0x0DE;
u16* DMASAD_L[4] = {DMA0SAD_L, DMA1SAD_L, DMA2SAD_L, DMA3SAD_L};
u16* DMASAD_H[4] = {DMA0SAD_H, DMA1SAD_H, DMA2SAD_H, DMA3SAD_H};
u16* DMADAD_L[4] = {DMA0DAD_L, DMA1DAD_L, DMA2DAD_L, DMA3DAD_L};
u16* DMADAD_H[4] = {DMA0DAD_H, DMA1DAD_H, DMA2DAD_H, DMA3DAD_H};
u16* DMACNT_L[4] = {DMA0CNT_L, DMA1CNT_L, DMA2CNT_L, DMA3CNT_L};
u16* DMACNT_H[4] = {DMA0CNT_H, DMA1CNT_H, DMA2CNT_H, DMA3CNT_H};

u16* TM0CNT_L = (u16*)IOR + 0x100;
u16* TM0CNT_H = (u16*)IOR + 0x102;
u16* TM1CNT_L = (u16*)IOR + 0x104;
u16* TM1CNT_H = (u16*)IOR + 0x106;
u16* TM2CNT_L = (u16*)IOR + 0x108;
u16* TM2CNT_H = (u16*)IOR + 0x10A;
u16* TM3CNT_L = (u16*)IOR + 0x10C;
u16* TM3CNT_H = (u16*)IOR + 0x10E;
u16* TM_CNT_L[4] = {TM0CNT_L, TM1CNT_L, TM2CNT_L, TM3CNT_L};
u16* TM_CNT_H[4] = {TM0CNT_H, TM1CNT_H, TM2CNT_H, TM3CNT_H};

u16* SIODATA32_L = (u16*)IOR + 0x120;
u16* SIOMULTI0 = (u16*)IOR + 0x120;
u16* SIODATA32_H = (u16*)IOR + 0x122;
u16* SIOMULTI1 = (u16*)IOR + 0x122;
u16* SIOMULTI2 = (u16*)IOR + 0x124;
u16* SIOMULTI3 = (u16*)IOR + 0x126;
u16* SIOMULTI[4] = {SIOMULTI0, SIOMULTI1, SIOMULTI2, SIOMULTI3};
u16* SIOCNT = (u16*)IOR + 0x128;
u16* SIODATA8 = (u16*)IOR + 0x12A;
u16* SIOMLT_SEND = (u16*)IOR + 0x12A;

u16* KEYINPUT = (u16*)IOR + 0x130;
u16* KEYCNT = (u16*)IOR + 0x132;
u16* RCNT = (u16*)IOR + 0x134;
u16* IR = (u16*)IOR + 0x136;

u16* JOYCNT = (u16*)IOR + 0x140;

u16* JOYRECV_L = (u16*)IOR + 0x150;
u16* JOYRECV_H = (u16*)IOR + 0x152;
u16* JOYTRANS_L = (u16*)IOR + 0x154;
u16* JOYTRANS_H = (u16*)IOR + 0x156;
u16* JOYSTAT = (u16*)IOR + 0x158;

u16* IE = (u16*)IOR + 0x200;
u16* IF = (u16*)IOR + 0x202;
u16* WAITCNT = (u16*)IOR + 0x204;

u16* IME = (u16*)IOR + 0x208;

uint8_t* POSTFLAG = (uint8_t*)IOR + 0x300;
uint8_t* HALTCNT = (uint8_t*)IOR + 0x301;

uint8_t* UNDOC = (uint8_t*)IOR + 0x410;

u16* IMEMCNT_L = (u16*)IOR + 0x800;
u16* IMEMCNT_H = (u16*)IOR + 0x802;

uint32_t* ARM7 = (uint32_t*)IOR + 0x700000;
