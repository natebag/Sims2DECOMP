// 0x801450C4 cGZSnd::Release(void) (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 0,0x14(1); mr 30,3; bl _s801450C4_0; lis 9,-32698; li 0,0; addi 9,9,19184; stw 0,0x5c(30); stw 9,0x0(30); mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32698; mr 11,3; addi 9,9,19184; stw 9,0x0(11); bl _s801450C4_1; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; li 3,0; blr; li 3,0; blr; lwz 9,0x54(3); li 3,0; cmpwi 9,0; beqlr; lwz 3,-4(9); blr; mulli 4,4,72; lwz 3,0x54(3); add 3,3,4; blr; li 3,0; blr; blr; li 3,0; blr; li 3,1"
extern "C" void _s801450C4_0();
extern "C" void _s801450C4_1();
extern "C" void f_801450C4() {}
