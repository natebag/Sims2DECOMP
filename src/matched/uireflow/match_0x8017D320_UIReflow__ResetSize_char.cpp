// 0x8017D320 UIReflow::ResetSize(char (384 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-672(1); mfspr 0,8; stmw 27,0x28c(1); stw 0,0x2a4(1); lwz 0,0x4(3); mr 31,4; mr 28,5; mr 27,6; mr 29,7; cmpwi 0,0; bne 2f; lis 9,-32706; addi 30,1,8; lwz 11,0x375c(9); lis 4,-32706; addi 9,9,14172; addi 4,4,14184; lbz 10,0x8(9); mr 3,30; lwz 0,0x4(9); stw 11,0x8(1); stw 0,0x4(30); stb 10,0x8(30); bl _s8017D320_0; cmpwi 29,0; beq 0f; lis 4,-32706; mr 3,30; addi 4,4,14192; bl _s8017D320_1; b 1f; 0:; lis 4,-32706; mr 3,30; addi 4,4,14196; bl _s8017D320_2; 1:; addi 3,1,8; mr 4,31; bl _s8017D320_3; lis 29,-32706; lis 4,-32706; addi 30,1,520; addi 3,1,8; addi 4,4,14200; bl _s8017D320_4; lis 4,-32706; addi 3,1,8; addi 4,4,14208; bl _s8017D320_5; mr 5,28; addi 4,29,14212; mr 3,30; crxor 6,6,6; bl _s8017D320_6; addi 3,1,8; mr 4,30; bl _s8017D320_7; lis 4,-32706; addi 3,1,8; addi 4,4,14216; bl _s8017D320_8; lis 4,-32706; addi 3,1,8; addi 4,4,14224; bl _s8017D320_9; mr 5,27; addi 4,29,14212; mr 3,30; crxor 6,6,6; bl _s8017D320_10; mr 4,30; addi 3,1,8; bl _s8017D320_11; lis 4,-32706; addi 3,1,8; addi 4,4,14228; bl _s8017D320_12; lis 4,-32706; addi 3,1,8; addi 4,4,14236; bl _s8017D320_13; lis 4,-32706; lis 8,-32706; lwz 3,-25136(13); addi 4,4,14152; addi 8,8,14248; li 5,0; li 6,0; li 7,2; addi 9,1,8; crxor 6,6,6; bl _s8017D320_14; 2:; lwz 0,0x2a4(1); mtspr 8,0; lmw 27,0x28c(1); addi 1,1,672"

extern "C" void _s8017D320_0();
extern "C" void _s8017D320_1();
extern "C" void _s8017D320_2();
extern "C" void _s8017D320_3();
extern "C" void _s8017D320_4();
extern "C" void _s8017D320_5();
extern "C" void _s8017D320_6();
extern "C" void _s8017D320_7();
extern "C" void _s8017D320_8();
extern "C" void _s8017D320_9();
extern "C" void _s8017D320_10();
extern "C" void _s8017D320_11();
extern "C" void _s8017D320_12();
extern "C" void _s8017D320_13();
extern "C" void _s8017D320_14();

struct UIReflow {
    void ResetSize();
};

void UIReflow::ResetSize() {
}
