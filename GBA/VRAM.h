u8* VRAM = AGBmem + 0x06000000;
u32* OBJCD = (u32*)VRAM + 0x10000;
u32* BGCD = (u32*)VRAM + 0x00000;
u32* CDB[4] = {(u32*)VRAM + 0x0000, (u32*)VRAM + 0x4000, (u32*)VRAM + 0x8000, (u32*)VRAM + 0xC000};
u16* SDB[32] = {(u16*)VRAM + 0x0000, (u16*)VRAM + 0x0800, (u16*)VRAM + 0x1000, (u16*)VRAM + 0x1800,
                    (u16*)VRAM + 0x2000, (u16*)VRAM + 0x2800, (u16*)VRAM + 0x3000, (u16*)VRAM + 0x3800,
                    (u16*)VRAM + 0x4000, (u16*)VRAM + 0x4800, (u16*)VRAM + 0x5000, (u16*)VRAM + 0x5800,
                    (u16*)VRAM + 0x6000, (u16*)VRAM + 0x6800, (u16*)VRAM + 0x7000, (u16*)VRAM + 0x7800,
                    (u16*)VRAM + 0x8000, (u16*)VRAM + 0x8800, (u16*)VRAM + 0x9000, (u16*)VRAM + 0x9800,
                    (u16*)VRAM + 0xA000, (u16*)VRAM + 0xA800, (u16*)VRAM + 0xB000, (u16*)VRAM + 0xB800,
                    (u16*)VRAM + 0xC000, (u16*)VRAM + 0xC800, (u16*)VRAM + 0xD000, (u16*)VRAM + 0xD800,
                    (u16*)VRAM + 0xE000, (u16*)VRAM + 0xE800, (u16*)VRAM + 0xF000, (u16*)VRAM + 0xF800};

