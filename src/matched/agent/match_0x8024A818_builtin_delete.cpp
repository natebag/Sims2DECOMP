// 0x8024A818 __builtin_delete (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 5,-32704; li 3,0; addi 5,5,776; li 4,0; crxor 6,6,6; bl _s8024A818_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8024A818_0();
extern "C" void f_8024A818() {}
