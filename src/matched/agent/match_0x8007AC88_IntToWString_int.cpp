// 0x8007AC88 IntToWString(int, (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 29,4; mr 28,5; lis 3,-32696; mr 31,6; addi 3,3,22428; li 4,0; li 5,32; bl _s8007AC88_0; lis 3,-32696; cmpwi 31,0; bne 0f; lis 4,-32707; addi 3,3,22428; addi 4,4,26348; mr 5,30; crxor 6,6,6; bl _s8007AC88_1; b 1f; 0:; lis 4,-32707; addi 3,3,22428; addi 4,4,26352; mr 5,31; mr 6,30; crxor 6,6,6; bl _s8007AC88_2; 1:; lis 3,-32696; mr 4,29; addi 3,3,22428; mr 5,28; bl _s8007AC88_3; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8007AC88_0();
extern "C" void _s8007AC88_1();
extern "C" void _s8007AC88_2();
extern "C" void _s8007AC88_3();
extern "C" void f_8007AC88() {}
