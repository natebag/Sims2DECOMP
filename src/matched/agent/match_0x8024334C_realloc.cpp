// 0x8024334C realloc (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mfspr 6,8; lis 5,-32704; addi 6,6,-4; addi 5,5,-420; li 3,0; li 4,0; crxor 6,6,6; bl _s8024334C_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8024334C_0();
extern "C" void f_8024334C() {}
