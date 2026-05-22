// 0x80234724 TArray<EVec3, (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mtspr 8,0; lmw 25,0x5c(1); lfd f29,0x78(1); lfd f30,0x80(1); lfd f31,0x88(1); addi 1,1,144"
extern "C" float f_80234724() {}
