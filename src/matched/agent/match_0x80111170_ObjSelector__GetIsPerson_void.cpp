// 0x80111170 ObjSelector::GetIsPerson(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x38(3); lha 3,0x12(9); xoris 3,3,2; subfic 0,3,0; adde 3,0,3"
extern "C" int f_80111170() {}
