// 0x802685D4 DBGEXIDeselect (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-13312; lwz 0,0x6828(3); addi 4,3,26624; li 3,1; andi. 0,0,1029; stw 0,0x28(4)"
extern "C" void f_802685D4() {}
