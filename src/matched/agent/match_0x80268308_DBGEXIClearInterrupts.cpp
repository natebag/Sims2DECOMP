// 0x80268308 DBGEXIClearInterrupts (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-13312; addi 4,3,26624; lwz 3,0x6828(3); li 0,2058; stw 0,0x28(4)"
extern "C" void f_80268308() {}
