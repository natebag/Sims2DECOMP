// 0x8037EE9C __DSP_remove_task (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 4,0; stw 4,0x8(3); li 0,3; stw 0,0x0(3); lwz 0,-22020(13); cmplw 0,3; bne 1f; lwz 0,0x38(3); cmplwi 0,0; beq 0f; stw 0,-22020(13); lwz 3,0x38(3); stw 4,0x3c(3); blr; 0:; stw 4,-22016(13); stw 4,-22024(13); stw 4,-22020(13); blr; 1:; lwz 0,-22024(13); cmplw 0,3; bne 2f; lwz 0,0x3c(3); stw 0,-22024(13); lwz 3,0x3c(3); stw 4,0x38(3); lwz 0,-22020(13); stw 0,-22016(13); blr; 2:; lwz 0,0x38(3); stw 0,-22016(13); lwz 0,0x38(3); lwz 4,0x3c(3); stw 0,0x38(4); lwz 0,0x3c(3); lwz 3,0x38(3); stw 0,0x3c(3)"
extern "C" void f_8037EE9C() {}
