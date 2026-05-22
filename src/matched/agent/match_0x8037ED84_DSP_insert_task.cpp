// 0x8037ED84 __DSP_insert_task (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-22020(13); cmplwi 0,0; bne 0f; stw 3,-22016(13); li 0,0; stw 3,-22024(13); stw 3,-22020(13); stw 0,0x3c(3); stw 0,0x38(3); blr; 0:; mr 5,0; b 4f; 1:; lwz 4,0x4(3); lwz 0,0x4(5); cmplw 4,0; bge 3f; lwz 0,0x3c(5); stw 0,0x3c(3); stw 3,0x3c(5); stw 5,0x38(3); lwz 4,0x3c(3); cmplwi 4,0; bne 2f; stw 3,-22020(13); b 5f; 2:; stw 3,0x38(4); b 5f; 3:; lwz 5,0x38(5); 4:; cmplwi 5,0; bne 1b; 5:; cmplwi 5,0; bnelr; lwz 4,-22024(13); li 0,0; stw 3,0x38(4); stw 0,0x38(3); lwz 0,-22024(13); stw 0,0x3c(3); stw 3,-22024(13)"
extern "C" void f_8037ED84() {}
