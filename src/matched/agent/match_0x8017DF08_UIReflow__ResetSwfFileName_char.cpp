// 0x8017DF08 UIReflow::ResetSwfFileName(char (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-536(1); mfspr 0,8; stmw 28,0x208(1); stw 0,0x21c(1); lwz 0,0x4(3); mr 29,4; mr 28,5; mr 30,6; cmpwi 0,0; bne 2f; lis 9,-32706; addi 31,1,8; lwz 11,0x375c(9); lis 4,-32706; addi 9,9,14172; addi 4,4,14184; lbz 10,0x8(9); mr 3,31; lwz 0,0x4(9); stw 11,0x8(1); stw 0,0x4(31); stb 10,0x8(31); bl _s8017DF08_0; cmpwi 30,0; beq 0f; lis 4,-32706; mr 3,31; addi 4,4,14192; bl _s8017DF08_1; b 1f; 0:; lis 4,-32706; mr 3,31; addi 4,4,14196; bl _s8017DF08_2; 1:; addi 3,1,8; mr 4,29; bl _s8017DF08_3; lis 4,-32706; addi 3,1,8; addi 4,4,14200; bl _s8017DF08_4; lis 4,-32706; addi 3,1,8; addi 4,4,14420; bl _s8017DF08_5; mr 4,28; addi 3,1,8; bl _s8017DF08_6; lis 4,-32706; addi 3,1,8; addi 4,4,14428; bl _s8017DF08_7; lis 4,-32706; addi 3,1,8; addi 4,4,14236; bl _s8017DF08_8; lis 4,-32706; lis 8,-32706; lwz 3,-25136(13); addi 4,4,14152; addi 8,8,14248; li 5,0; li 6,0; li 7,2; addi 9,1,8; crxor 6,6,6; bl _s8017DF08_9; 2:; lwz 0,0x21c(1); mtspr 8,0; lmw 28,0x208(1); addi 1,1,536"
extern "C" void _s8017DF08_0();
extern "C" void _s8017DF08_1();
extern "C" void _s8017DF08_2();
extern "C" void _s8017DF08_3();
extern "C" void _s8017DF08_4();
extern "C" void _s8017DF08_5();
extern "C" void _s8017DF08_6();
extern "C" void _s8017DF08_7();
extern "C" void _s8017DF08_8();
extern "C" void _s8017DF08_9();
extern "C" void f_8017DF08() {}
