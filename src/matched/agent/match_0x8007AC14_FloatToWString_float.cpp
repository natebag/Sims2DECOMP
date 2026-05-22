// 0x8007AC14 FloatToWString(float, (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stfd f31,0x18(1); stmw 28,0x8(1); stw 0,0x24(1); lis 30,-32696; mr 29,3; mr 28,4; li 5,32; li 4,0; fmr f31,f1; addi 3,30,22428; bl _s8007AC14_0; lis 4,-32707; fmr f1,f31; addi 4,4,26344; addi 3,30,22428; creqv 6,6,6; bl _s8007AC14_1; addi 3,30,22428; mr 4,29; mr 5,28; bl _s8007AC14_2; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x8(1); lfd f31,0x18(1); addi 1,1,32"
extern "C" void _s8007AC14_0();
extern "C" void _s8007AC14_1();
extern "C" void _s8007AC14_2();
extern "C" void f_8007AC14() {}
