// 0x8015E688 TreeTableEntryQuickData::GetDebugOnly(void) (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x4(3); li 3,0; lwz 0,0x10(9); andi. 11,0,128; bne 1f; lwz 9,0x1c(9); li 11,0; cmpwi 9,0; beq 0f; lwz 11,0x0(9); 0:; lhz 0,0x0(11); cmpwi 0,33; bnelr; 1:; li 3,1"
extern "C" int f_8015E688() {}
