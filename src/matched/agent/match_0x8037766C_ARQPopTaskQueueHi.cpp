// 0x8037766C __ARQPopTaskQueueHi (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); lwz 6,-22336(13); cmplwi 6,0; beq 2f; lwz 3,0x8(6); cmplwi 3,0; bne 0f; lwz 4,0x10(6); lwz 5,0x14(6); lwz 6,0x18(6); bl _s8037766C_0; b 1f; 0:; lwz 4,0x14(6); lwz 5,0x10(6); lwz 6,0x18(6); bl _s8037766C_1; 1:; lwz 3,-22336(13); lwz 0,0x1c(3); stw 0,-22304(13); stw 3,-22312(13); lwz 0,0x0(3); stw 0,-22336(13); 2:; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8037766C_0();
extern "C" void _s8037766C_1();
extern "C" void f_8037766C() {}
