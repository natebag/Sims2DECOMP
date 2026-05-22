// 0x8014529C IFFSlotDescList::GetSlot(int) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mulli 4,4,72; lwz 3,0x54(3); add 3,3,4"
extern "C" int f_8014529C() {}
