// 0x8017DCAC UIReflow::ResetFontSizeOverride(char (316 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-664(1); mfspr 0,8; stmw 28,0x288(1); stw 0,0x29c(1); lwz 0,0x4(3); mr 29,4; mr 28,5; mr 31,6; cmpwi 0,0; bne 2f; lis 9,-32706; addi 30,1,8; lwz 11,0x375c(9); lis 4,-32706; addi 9,9,14172; addi 4,4,14184; lbz 10,0x8(9); mr 3,30; lwz 0,0x4(9); stw 11,0x8(1); stw 0,0x4(30); stb 10,0x8(30); bl _s8017DCAC_0; cmpwi 31,0; beq 0f; lis 4,-32706; mr 3,30; addi 4,4,14192; bl _s8017DCAC_1; b 1f; 0:; lis 4,-32706; mr 3,30; addi 4,4,14196; bl _s8017DCAC_2; 1:; addi 3,1,8; mr 4,29; bl _s8017DCAC_3; lis 4,-32706; addi 30,1,520; addi 3,1,8; addi 4,4,14200; bl _s8017DCAC_4; lis 4,-32706; addi 3,1,8; addi 4,4,14380; bl _s8017DCAC_5; lis 4,-32706; mr 5,28; addi 4,4,14212; mr 3,30; crxor 6,6,6; bl _s8017DCAC_6; mr 4,30; addi 3,1,8; bl _s8017DCAC_7; lis 4,-32706; addi 3,1,8; addi 4,4,14388; bl _s8017DCAC_8; lis 4,-32706; addi 3,1,8; addi 4,4,14236; bl _s8017DCAC_9; lis 4,-32706; lis 8,-32706; lwz 3,-25136(13); addi 4,4,14152; addi 8,8,14248; li 5,0; li 6,0; li 7,2; addi 9,1,8; crxor 6,6,6; bl _s8017DCAC_10; 2:; lwz 0,0x29c(1); mtspr 8,0; lmw 28,0x288(1); addi 1,1,664"
extern "C" void _s8017DCAC_0();
extern "C" void _s8017DCAC_1();
extern "C" void _s8017DCAC_2();
extern "C" void _s8017DCAC_3();
extern "C" void _s8017DCAC_4();
extern "C" void _s8017DCAC_5();
extern "C" void _s8017DCAC_6();
extern "C" void _s8017DCAC_7();
extern "C" void _s8017DCAC_8();
extern "C" void _s8017DCAC_9();
extern "C" void _s8017DCAC_10();
extern "C" void f_8017DCAC() {}
