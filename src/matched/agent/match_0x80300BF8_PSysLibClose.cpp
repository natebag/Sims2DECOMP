// 0x80300BF8 PSysLibClose (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); addi 3,13,-22708; bl _s80300BF8_0; addi 3,13,-22704; bl _s80300BF8_1; addi 3,13,-22700; bl _s80300BF8_2; addi 3,13,-22696; bl _s80300BF8_3; bl _s80300BF8_4; bl _s80300BF8_5; li 3,0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80300BF8_0();
extern "C" void _s80300BF8_1();
extern "C" void _s80300BF8_2();
extern "C" void _s80300BF8_3();
extern "C" void _s80300BF8_4();
extern "C" void _s80300BF8_5();
extern "C" void f_80300BF8() {}
