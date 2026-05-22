// 0x8032E6AC ResetCallback(void) (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s8032E6AC_0; cmpwi 3,0; beq 0f; li 0,1; stw 0,-26480(13); b 1f; 0:; lis 3,-32717; addi 3,3,-6484; bl _s8032E6AC_1; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8032E6AC_0();
extern "C" void _s8032E6AC_1();
extern "C" void f_8032E6AC() {}
