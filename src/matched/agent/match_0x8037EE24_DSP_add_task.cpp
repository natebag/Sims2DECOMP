// 0x8037EE24 __DSP_add_task (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; addi 4,3,0; stw 0,0x4(1); stwu 1,-8(1); lwz 5,-22024(13); cmplwi 5,0; bne 0f; stw 4,-22016(13); li 0,0; stw 4,-22024(13); stw 4,-22020(13); stw 0,0x3c(4); stw 0,0x38(4); b 1f; 0:; stw 4,0x38(5); li 0,0; stw 0,0x38(4); lwz 0,-22024(13); stw 0,0x3c(4); stw 4,-22024(13); 1:; li 0,0; crxor 6,6,6; lis 3,-32698; stw 0,0x0(4); addi 3,3,-27600; bl _s8037EE24_0; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8037EE24_0();
extern "C" void f_8037EE24() {}
