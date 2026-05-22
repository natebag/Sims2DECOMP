// 0x8015E92C TreeTableQuickData::GetPrefixCheckTreeID(void) (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x4(3); cmpwi 3,0; beq 0f; lha 3,0x8(3); blr; 0:; li 3,0"
extern "C" int f_8015E92C() {}
