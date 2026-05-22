// 0x8015A150 IFFBehaviorConstants::LoadData(iResFile (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 28,5; mr 29,3; lwz 30,0x4(28); mr 27,4; lwz 9,0x0(29); lhz 0,0x0(30); lha 3,0x60(9); rlwinm 31,0,0,17,31; lwz 0,0x64(9); mr 4,31; add 3,29,3; mtspr 8,0; blrl; lha 4,0x0(30); mr 3,29; rlwinm 4,4,17,31,31; bl _s8015A150_0; li 11,0; cmpw 11,31; bge 1f; 0:; add 8,11,11; lwz 10,0x14(29); add 9,30,8; addi 11,11,1; lhz 0,0x2(9); extsh 11,11; cmpw 11,31; sthx 0,8,10; blt 0b; 1:; lwz 9,0xc(27); mr 4,28; addi 5,1,8; li 0,0; lha 3,0xb0(9); lwz 9,0xb4(9); add 3,27,3; sth 0,0x8(1); mtspr 8,9; blrl; lhz 4,0x8(1); addi 3,29,8; bl _s8015A150_1; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s8015A150_0();
extern "C" void _s8015A150_1();
extern "C" void f_8015A150() {}
