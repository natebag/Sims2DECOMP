// 0x8038E2FC GXSetTlutRegionCallback (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 4,-17720(13); lwzu 0,0x4cc(4); stw 3,0x0(4); mr 3,0"
extern "C" void f_8038E2FC() {}
