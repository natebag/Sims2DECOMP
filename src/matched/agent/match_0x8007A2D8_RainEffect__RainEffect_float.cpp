// 0x8007A2D8 RainEffect::RainEffect(float, (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lis 9,-32707; mr 30,3; lfs f0,0x66ac(9); li 29,0; stfs f1,0x14(30); lis 9,-32702; stfs f2,0x1c(30); addi 9,9,15940; stfs f3,0x18(30); rlwinm 0,4,2,0,29; stfs f0,0x30(30); lis 28,-32692; stw 29,0x8(30); addi 3,28,6092; stw 4,0x34(30); stw 29,0x10(30); stw 29,0xc(30); lwzx 4,9,0; bl _s8007A2D8_0; lwz 0,0x34(30); lis 9,-32702; stw 29,0x4(30); addi 9,9,15928; stw 29,0x0(30); rlwinm 0,0,2,0,29; addi 3,28,6092; lwzx 4,9,0; bl _s8007A2D8_1; mr 3,30; bl _s8007A2D8_2; li 3,1; bl _s8007A2D8_3; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8007A2D8_0();
extern "C" void _s8007A2D8_1();
extern "C" void _s8007A2D8_2();
extern "C" void _s8007A2D8_3();
extern "C" void f_8007A2D8() {}
