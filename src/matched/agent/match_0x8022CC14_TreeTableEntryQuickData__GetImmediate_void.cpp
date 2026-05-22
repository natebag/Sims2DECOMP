// 0x8022CC14 TreeTableEntryQuickData::GetImmediate(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mtspr 8,0; lmw 24,0x40(1); addi 1,1,96"
extern "C" int f_8022CC14() {}
