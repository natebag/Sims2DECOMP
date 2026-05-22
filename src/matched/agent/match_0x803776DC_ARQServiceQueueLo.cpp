// 0x803776DC __ARQServiceQueueLo (256 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); lwz 0,-22308(13); cmplwi 0,0; bne 0f; lwz 3,-22328(13); cmplwi 3,0; beq 0f; stw 3,-22308(13); lwz 0,0x0(3); stw 0,-22328(13); 0:; lwz 5,-22308(13); cmplwi 5,0; beq 6f; lwz 6,0x18(5); lwz 0,-22296(13); cmplw 6,0; bgt 3f; lwz 3,0x8(5); cmplwi 3,0; bne 1f; lwz 4,0x10(5); lwz 5,0x14(5); bl _s803776DC_0; b 2f; 1:; lwz 4,0x14(5); lwz 5,0x10(5); bl _s803776DC_1; 2:; lwz 3,-22308(13); lwz 0,0x1c(3); stw 0,-22300(13); b 5f; 3:; lwz 3,0x8(5); cmplwi 3,0; bne 4f; lwz 4,0x10(5); mr 6,0; lwz 5,0x14(5); bl _s803776DC_2; b 5f; 4:; lwz 4,0x14(5); mr 6,0; lwz 5,0x10(5); bl _s803776DC_3; 5:; lwz 3,-22308(13); lwz 4,-22296(13); lwz 0,0x18(3); subf 0,4,0; stw 0,0x18(3); lwz 4,-22308(13); lwz 0,-22296(13); lwz 3,0x10(4); add 0,3,0; stw 0,0x10(4); lwz 4,-22308(13); lwz 0,-22296(13); lwz 3,0x14(4); add 0,3,0; stw 0,0x14(4); 6:; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s803776DC_0();
extern "C" void _s803776DC_1();
extern "C" void _s803776DC_2();
extern "C" void _s803776DC_3();
extern "C" void f_803776DC() {}
