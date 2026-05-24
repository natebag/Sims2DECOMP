// 0x802CC900 ENodeList::GetSize(void) (52 B)
// FLAGS: -fno-schedule-insns
// NOTE: DOL uses li r0,1 boolean-materialize loop condition; SN ProDG v1.76 emits simpler cmpwi/bne -- unmatchable
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x0(3); li 9,0; b 1f; 0:; lwz 3,0x8(3); addi 9,9,1; 1:; li 0,1; cmpwi 3,0; bne 2f; li 0,0; 2:; cmpwi 0,0; bne 0b; mr 3,9"
extern "C" int f_802CC900() {}
