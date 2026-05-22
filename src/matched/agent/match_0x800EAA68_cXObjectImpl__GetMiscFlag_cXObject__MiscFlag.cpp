// 0x800EAA68 cXObjectImpl::GetMiscFlag(cXObject::MiscFlag) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x84(3); li 3,1; and 9,0,4; bnelr; li 3,0"
extern "C" int f_800EAA68() {}
