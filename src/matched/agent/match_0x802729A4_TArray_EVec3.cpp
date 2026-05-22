// 0x802729A4 TArray<EVec3, (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32694; add 3,30,3; lwz 0,-16240(9); mr 4,29; mtspr 8,0; blrl; li 3,1; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" int f_802729A4() {}
