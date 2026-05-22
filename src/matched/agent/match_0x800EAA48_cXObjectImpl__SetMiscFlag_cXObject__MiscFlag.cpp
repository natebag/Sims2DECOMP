// 0x800EAA48 cXObjectImpl::SetMiscFlag(cXObject::MiscFlag, (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x84(3); cmplwi 5,0; andc 0,0,4; stw 0,0x84(3); beqlr; or 0,0,4; stw 0,0x84(3)"
extern "C" void f_800EAA48() {}
