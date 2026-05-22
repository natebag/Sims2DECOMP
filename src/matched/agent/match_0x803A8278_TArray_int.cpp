// 0x803A8278 TArray<int, (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mtspr 8,0; addi 1,1,8; blr; lwz 3,0x8(3)"
extern "C" int f_803A8278() {}
