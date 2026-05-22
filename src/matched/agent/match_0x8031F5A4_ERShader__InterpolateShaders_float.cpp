// 0x8031F5A4 ERShader::InterpolateShaders(float) (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32702; mr 31,3; lfs f12,0xa9c(9); fcmpu 0,f1,f12; beq 1f; lfs f0,0x60(31); lfs f13,0x40(31); fadds f0,f0,f1; stfs f0,0x60(31); fcmpu 0,f0,f13; cror 3,2,1; bns 0f; fmr f1,f12; bl _s8031F5A4_0; li 30,0; lwz 4,0x1c(31); mr 3,31; bl _s8031F5A4_1; lwz 0,0x58(31); lis 3,-32692; stw 30,0x1c(31); addi 3,3,-17444; rlwinm 0,0,0,29,27; lwz 4,0x68(31); stw 0,0x58(31); bl _s8031F5A4_2; stw 30,0x68(31); b 1f; 0:; fdivs f1,f0,f13; mr 3,31; bl _s8031F5A4_3; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8031F5A4_0();
extern "C" void _s8031F5A4_1();
extern "C" void _s8031F5A4_2();
extern "C" void _s8031F5A4_3();
extern "C" void f_8031F5A4() {}
