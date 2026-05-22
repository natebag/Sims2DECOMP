// 0x80386690 TArray<EVec3, (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lmw 22,0xf8(1); lwz 0,0x124(1); addi 1,1,288; mtspr 8,0"
extern "C" int f_80386690() {}
