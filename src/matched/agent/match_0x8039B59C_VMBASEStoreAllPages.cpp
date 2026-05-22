// 0x8039B59C VMBASEStoreAllPages (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 0,0x24(1); addi 11,1,32; bl _s8039B59C_0; mr 27,3; bl _s8039B59C_1; li 30,0; mr 29,3; li 31,0; 0:; lwz 0,-21536(13); add 28,0,31; lwz 0,0x0(28); rlwinm. 0,0,0,0,0; beq 1f; lwz 0,0x4(28); rlwinm. 0,0,0,24,24; beq 1f; mr 3,28; bl _s8039B59C_2; mr 12,27; mtspr 9,12; bctrl; lwz 0,0x4(28); addi 3,28,4; li 4,4; rlwinm 0,0,0,25,23; stw 0,0x4(28); bl _s8039B59C_3; 1:; addi 30,30,1; addi 31,31,8; cmplwi 30,8192; blt 0b; bl _s8039B59C_4; bl _s8039B59C_5; mr 3,29; bl _s8039B59C_6; addi 11,1,32; bl _s8039B59C_7; lwz 0,0x24(1); mtspr 8,0; addi 1,1,32"
extern "C" void _s8039B59C_0();
extern "C" void _s8039B59C_1();
extern "C" void _s8039B59C_2();
extern "C" void _s8039B59C_3();
extern "C" void _s8039B59C_4();
extern "C" void _s8039B59C_5();
extern "C" void _s8039B59C_6();
extern "C" void _s8039B59C_7();
extern "C" void f_8039B59C() {}
