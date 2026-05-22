// 0x8024CE00 LCAllocTags (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 6,8; cmplwi 5,0; ble 2f; mtspr 9,5; cmpwi 3,0; beq 1f; 0:; dcbi 0,4; .long 0x100027EC; addi 4,4,32; bdnz 0b; b 2f; 1:; .long 0x100027EC; addi 4,4,32; bdnz 1b; 2:; mtspr 8,6"
extern "C" int f_8024CE00() {}
