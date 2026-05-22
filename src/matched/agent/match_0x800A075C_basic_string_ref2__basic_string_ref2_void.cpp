// 0x800A075C basic_string_ref2::basic_string_ref2(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 11,3; lwz 9,0xc(11); addi 9,9,1; stw 9,0xc(11)"
extern "C" void f_800A075C() {}
