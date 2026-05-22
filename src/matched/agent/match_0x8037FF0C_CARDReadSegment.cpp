// 0x8037FF0C __CARDReadSegment (308 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; li 6,5; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); addi 30,3,0; mulli 5,30,272; lis 3,-32688; addi 0,3,-24000; add 31,0,5; li 0,82; stb 0,0x94(31); li 0,0; addi 3,30,0; lwz 5,0xb0(31); rlwinm 5,5,15,25,31; stb 5,0x95(31); li 5,0; lwz 7,0xb0(31); rlwinm 7,7,23,24,31; stb 7,0x96(31); lwz 7,0xb0(31); rlwinm 7,7,25,30,31; stb 7,0x97(31); lwz 7,0xb0(31); rlwinm 7,7,0,25,31; stb 7,0x98(31); stw 6,0xa0(31); stw 0,0xa4(31); stw 0,0xa8(31); bl _s8037FF0C_0; cmpwi 3,-1; bne 0f; li 3,0; b 3f; 0:; cmpwi 3,0; blt 3f; lwz 5,0xa0(31); addi 3,30,0; addi 4,31,148; li 6,1; bl _s8037FF0C_1; cmpwi 3,0; beq 1f; lwz 4,0x80(31); mr 3,30; lwz 5,0x14(31); li 6,1; addi 4,4,512; bl _s8037FF0C_2; cmpwi 3,0; beq 1f; lis 3,-32712; lwz 4,0xb4(31); addi 7,3,-3752; lwz 6,0xa4(31); addi 3,30,0; li 5,512; bl _s8037FF0C_3; cmpwi 3,0; bne 2f; 1:; li 0,0; stw 0,0xc8(31); mr 3,30; bl _s8037FF0C_4; mr 3,30; bl _s8037FF0C_5; li 3,-3; b 3f; 2:; li 3,0; 3:; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8037FF0C_0();
extern "C" void _s8037FF0C_1();
extern "C" void _s8037FF0C_2();
extern "C" void _s8037FF0C_3();
extern "C" void _s8037FF0C_4();
extern "C" void _s8037FF0C_5();
extern "C" void f_8037FF0C() {}
