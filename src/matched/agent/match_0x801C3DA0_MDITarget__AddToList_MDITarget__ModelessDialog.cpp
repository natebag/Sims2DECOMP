// 0x801C3DA0 MDITarget::AddToList(MDITarget::ModelessDialog (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,0x84(3); li 0,1; stw 0,0x88(3); cmpwi 11,0; bne 0f; stw 4,0x84(3); blr; 0:; li 9,2; b 2f; 1:; lwz 9,0x88(3); lwz 11,0x20(11); addi 9,9,1; 2:; stw 9,0x88(3); lwz 0,0x20(11); cmpwi 0,0; bne 1b; stw 4,0x20(11); li 0,0; stw 0,0x20(4)"
extern "C" void f_801C3DA0() {}
