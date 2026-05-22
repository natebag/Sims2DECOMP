// 0x8009567C StartScreenVars::DrawPressStart(ERC (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); lwz 0,0xc(3); lis 9,-32697; addi 30,9,24012; mr 29,4; lwz 31,0x104(30); cmpwi 0,0; beq 1f; lis 9,-32706; lis 28,-32706; lfs f1,-30812(9); mr 3,31; lfs f2,-30808(28); li 4,1; bl _s8009567C_0; mr 3,31; mr 4,29; bl _s8009567C_1; lis 9,-32696; addi 11,31,88; lfs f0,0x5924(9); lis 5,-32706; addi 9,9,22820; addi 5,5,-30828; stfs f0,0x58(31); mr 4,30; addi 3,1,16; lfs f0,0x4(9); stfs f0,0x4(11); lfs f13,0x8(9); stfs f13,0x8(11); lfs f0,0xc(9); stfs f0,0xc(11); crxor 6,6,6; bl _s8009567C_2; lwz 9,0x10(1); li 5,0; cmpwi 9,0; beq 0f; lwz 5,0x0(9); 0:; lis 9,-32706; lis 11,-32706; lfs f0,-30804(9); lis 10,-32706; lfs f13,-30800(11); addi 6,1,8; stfs f0,0x8(1); mr 3,31; lfs f1,-30796(10); mr 4,29; lfs f2,-30808(28); li 7,2; stfs f13,0x4(6); li 8,0; li 9,0; li 10,1; bl _s8009567C_3; 1:; lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"
extern "C" void _s8009567C_0();
extern "C" void _s8009567C_1();
extern "C" void _s8009567C_2();
extern "C" void _s8009567C_3();
extern "C" void f_8009567C() {}
