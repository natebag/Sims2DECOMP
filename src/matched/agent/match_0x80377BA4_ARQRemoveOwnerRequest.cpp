// 0x80377BA4 ARQRemoveOwnerRequest (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); mr 31,3; bl _s80377BA4_0; li 0,0; lwz 5,-22336(13); stw 0,-22320(13); stw 0,-22316(13); b 3f; 0:; lwz 0,0x4(5); cmplw 0,31; beq 2f; lwz 0,-22320(13); cmplwi 0,0; bne 1f; stw 5,-22320(13); stw 5,-22316(13); b 2f; 1:; lwz 4,-22316(13); stw 5,0x0(4); stw 5,-22316(13); 2:; lwz 5,0x0(5); 3:; cmplwi 5,0; bne 0b; lwz 5,-22320(13); li 0,0; lwz 4,-22316(13); stw 5,-22336(13); lwz 5,-22328(13); stw 4,-22332(13); stw 0,-22320(13); stw 0,-22316(13); b 7f; 4:; lwz 0,0x4(5); cmplw 0,31; beq 6f; lwz 0,-22320(13); cmplwi 0,0; bne 5f; stw 5,-22320(13); stw 5,-22316(13); b 6f; 5:; lwz 4,-22316(13); stw 5,0x0(4); stw 5,-22316(13); 6:; lwz 5,0x0(5); 7:; cmplwi 5,0; bne 4b; lwz 4,-22320(13); lwz 0,-22316(13); stw 4,-22328(13); stw 0,-22324(13); bl _s80377BA4_1; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80377BA4_0();
extern "C" void _s80377BA4_1();
extern "C" void f_80377BA4() {}
