// 0x802140CC TArray<int, (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x4c(1); mtspr 8,0; lmw 30,0x40(1); addi 1,1,72"
extern "C" int f_802140CC() {}
