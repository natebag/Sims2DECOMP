// 0x80299450 AptDisplayListState::getLength(void) (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x0(3); li 9,0; cmpwi 3,0; beq 1f; 0:; lwz 3,0x54(3); addi 9,9,1; cmpwi 3,0; bne 0b; 1:; mr 3,9"
extern "C" int f_80299450() {}
