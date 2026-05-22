// 0x8025FCF8 DVDCheckDisk (248 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-16(1); stw 31,0xc(1); bl _s8025FCF8_0; lwz 0,-23456(13); cmpwi 0,0; beq 0f; li 4,-1; b 4f; 0:; lwz 0,-23464(13); cmpwi 0,0; beq 1f; li 4,8; b 4f; 1:; lwz 5,-23480(13); cmplwi 5,0; bne 2f; li 4,0; b 4f; 2:; lis 4,-32694; addi 0,4,-17184; cmplw 5,0; bne 3f; li 4,0; b 4f; 3:; lwz 4,0xc(5); 4:; addi 0,4,1; cmplwi 0,12; bgt 8f; lis 4,-32700; addi 4,4,-14240; rlwinm 0,0,2,0,29; lwzx 0,4,0; mtspr 9,0; bctr; li 31,1; b 8f; li 31,0; b 8f; lis 4,-13312; addi 4,4,24576; lwz 4,0x4(4); rlwinm. 0,4,30,31,31; bne 5f; rlwinm. 0,4,0,31,31; beq 6f; 5:; li 31,0; b 8f; 6:; lwz 0,-23440(13); cmplwi 0,0; beq 7f; li 31,0; b 8f; 7:; li 31,1; 8:; bl _s8025FCF8_1; mr 3,31; lwz 0,0x14(1); lwz 31,0xc(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s8025FCF8_0();
extern "C" void _s8025FCF8_1();
extern "C" void f_8025FCF8() {}
