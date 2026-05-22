// 0x800A7758 QuickStringSet::GetNativeString(int, (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x8(3); li 3,0; cmplwi 0,0"
extern "C" int f_800A7758() {}
