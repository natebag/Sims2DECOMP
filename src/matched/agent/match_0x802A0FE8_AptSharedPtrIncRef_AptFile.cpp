// 0x802A0FE8 AptSharedPtrIncRef(AptFile (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,3; lwz 3,0x0(9); addi 3,3,1; stw 3,0x0(9)"
extern "C" void f_802A0FE8() {}
