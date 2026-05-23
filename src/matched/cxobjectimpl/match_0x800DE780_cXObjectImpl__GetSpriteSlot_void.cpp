// 0x800DE780 cXObjectImpl::GetSpriteSlot(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0xb0(3)"
extern "C" int f_800DE780() {}
