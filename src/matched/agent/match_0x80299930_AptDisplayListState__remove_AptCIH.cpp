// 0x80299930 AptDisplayListState::remove(AptCIH (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,3; lwz 11,0x50(9); cmpwi 11,0; beq 0f; lwz 0,0x54(9); stw 0,0x54(11); 0:; lwz 11,0x54(9); cmpwi 11,0; beq 1f; lwz 0,0x50(9); stw 0,0x50(11); 1:; li 0,0; mr 3,9; stw 0,0x54(9); stw 0,0x50(9)"
extern "C" void f_80299930() {}
