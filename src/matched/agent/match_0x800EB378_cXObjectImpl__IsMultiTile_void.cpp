// 0x800EB378 cXObjectImpl::IsMultiTile(void) (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x88(3); li 3,1; lha 0,0x14(9); cmplwi 0,0; bnelr; li 3,0"
extern "C" int f_800EB378() {}
