// 0x802552F0 __SetTime (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 5,0; mtspr 284,5; mtspr 285,3; mtspr 284,4"
extern "C" int f_802552F0() {}
