// 0x802F7234 ERC::ParticleListRot(int, (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,5; mr. 30,4; beq 0f; mr 4,29; rlwinm 5,30,6,0,25; bl _s802F7234_0; lwz 9,0x70(31); mr 29,3; li 4,0; li 5,12; lwz 0,0x2b4(9); lha 3,0x2b0(9); mtspr 8,0; add 3,31,3; blrl; lwz 11,0x0(31); add 9,30,30; li 4,1; lwz 0,0x54(11); add 0,0,9; stw 0,0x54(11); lwz 9,0x70(31); lwz 0,0x2ac(9); lha 3,0x2a8(9); mtspr 8,0; add 3,31,3; blrl; li 0,61; stw 29,0x4(3); stb 0,0x0(3); sth 30,0x2(3); lwz 9,0x70(31); lha 3,0x2b8(9); lwz 0,0x2bc(9); add 3,31,3; mtspr 8,0; blrl; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802F7234_0();
extern "C" void f_802F7234() {}
