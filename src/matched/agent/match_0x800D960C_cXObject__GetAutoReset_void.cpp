// 0x800D960C cXObject::GetAutoReset(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,-31900(13)"
extern "C" int f_800D960C() {}
