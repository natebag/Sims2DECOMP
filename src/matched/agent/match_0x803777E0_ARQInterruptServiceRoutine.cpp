// 0x803777E0 __ARQInterruptServiceRoutine (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); lwz 12,-22304(13); cmplwi 12,0; beq 0f; lwz 3,-22312(13); mtspr 8,12; blrl; li 0,0; stw 0,-22312(13); stw 0,-22304(13); b 1f; 0:; lwz 12,-22300(13); cmplwi 12,0; beq 1f; lwz 3,-22308(13); mtspr 8,12; blrl; li 0,0; stw 0,-22308(13); stw 0,-22300(13); 1:; lwz 6,-22336(13); cmplwi 6,0; beq 4f; lwz 3,0x8(6); cmplwi 3,0; bne 2f; lwz 4,0x10(6); lwz 5,0x14(6); lwz 6,0x18(6); bl _s803777E0_0; b 3f; 2:; lwz 4,0x14(6); lwz 5,0x10(6); lwz 6,0x18(6); bl _s803777E0_1; 3:; lwz 3,-22336(13); lwz 0,0x1c(3); stw 0,-22304(13); stw 3,-22312(13); lwz 0,0x0(3); stw 0,-22336(13); 4:; lwz 0,-22312(13); cmplwi 0,0; bne 5f; bl _s803777E0_2; 5:; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s803777E0_0();
extern "C" void _s803777E0_1();
extern "C" void _s803777E0_2();
extern "C" void f_803777E0() {}
