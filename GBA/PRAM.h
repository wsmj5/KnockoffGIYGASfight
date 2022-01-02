u8* PRAM = AGBmem + 0x05000000;
u16* BGPRAM = (u16*)PRAM + 0x0000;
u16* BGpal[16] = {BGPRAM + 0x00, BGPRAM + 0x10, BGPRAM + 0x20, BGPRAM + 0x30,
                        BGPRAM + 0x40, BGPRAM + 0x50, BGPRAM + 0x60, BGPRAM + 0x70,
                        BGPRAM + 0x80, BGPRAM + 0x90, BGPRAM + 0xA0, BGPRAM + 0xB0,
                        BGPRAM + 0xC0, BGPRAM + 0xD0, BGPRAM + 0xE0, BGPRAM + 0xF0};
u16* OBJPRAM = (u16*)PRAM + 0x0100;
u16* OBJpal[16] = {OBJPRAM + 0x00, OBJPRAM + 0x10, OBJPRAM + 0x20, OBJPRAM + 0x30,
                        OBJPRAM + 0x40, OBJPRAM + 0x50, OBJPRAM + 0x60, OBJPRAM + 0x70,
                        OBJPRAM + 0x80, OBJPRAM + 0x90, OBJPRAM + 0xA0, OBJPRAM + 0xB0,
                        OBJPRAM + 0xC0, OBJPRAM + 0xD0, OBJPRAM + 0xE0, OBJPRAM + 0xF0};
