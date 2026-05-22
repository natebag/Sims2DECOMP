// 0x8033AF08 ENgcRC::SetBlendMode(int, (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 0,0x1c(1); lis 9,-32702; lfs f13,0x1b90(9); rlwinm 5,5,2,0,29; or 0,4,5; rlwinm 6,6,4,0,27; fmuls f1,f1,f13; or 0,0,6; rlwinm 7,7,6,0,25; fctiwz f0,f1; or 0,0,7; stfd f0,0x10(1); li 9,52; addi 10,1,8; sth 8,0xa(1); lwz 11,0x14(1); lis 3,-32691; stb 9,0x8(1); addi 3,3,21688; rlwinm 11,11,8,16,23; mr 4,10; or 0,0,11; stw 0,0x4(10); bl _s8033AF08_0; lwz 0,0x1c(1); mtspr 8,0; addi 1,1,24"
extern "C" void _s8033AF08_0();
extern "C" void f_8033AF08() {}
