// 0x8014527C IFFSlotDescList::GetNumSlots(void) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x54(3); lis 0,14563; lwz 3,0x58(3); ori 0,0,36409; subf 3,9,3; mullw 3,3,0; srawi 3,3,3"
extern "C" int f_8014527C() {}
