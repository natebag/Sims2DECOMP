// 0x8025F60C DVDGetDriveStatus (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); bl _s8025F60C_0; lwz 0,-23456(13); addi 30,3,0; cmpwi 0,0; beq 0f; li 31,-1; b 5f; 0:; lwz 0,-23464(13); cmpwi 0,0; beq 1f; li 31,8; b 5f; 1:; lwz 31,-23480(13); cmplwi 31,0; bne 2f; li 31,0; b 5f; 2:; lis 3,-32694; addi 0,3,-17184; cmplw 31,0; bne 3f; li 31,0; b 5f; 3:; bl _s8025F60C_1; lwz 31,0xc(31); cmpwi 31,3; bne 4f; li 31,1; 4:; bl _s8025F60C_2; 5:; mr 3,30; bl _s8025F60C_3; mr 3,31; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8025F60C_0();
extern "C" void _s8025F60C_1();
extern "C" void _s8025F60C_2();
extern "C" void _s8025F60C_3();
extern "C" void f_8025F60C() {}
