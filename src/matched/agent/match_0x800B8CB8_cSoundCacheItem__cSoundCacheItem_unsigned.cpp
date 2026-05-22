// 0x800B8CB8 cSoundCacheItem::cSoundCacheItem(unsigned (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x0(3)"
extern "C" void f_800B8CB8() {}
