// 0x80259310 TArray<EVec3, (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 30,0x28(1); lwz 29,0x24(1); addi 1,1,48; mtspr 8,0"
extern "C" int f_80259310() {}
