// 0x8025325C OSSetSwitchThreadCallback (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); mr 30,3; bl _s8025325C_0; cmplwi 30,0; lwz 31,-27896(13); beq 0f; mr 0,30; b 1f; 0:; lis 4,-32731; addi 0,4,12888; 1:; stw 0,-27896(13); bl _s8025325C_1; lis 3,-32731; addi 0,3,12888; cmplw 31,0; bne 2f; li 3,0; b 3f; 2:; mr 3,31; 3:; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8025325C_0();
extern "C" void _s8025325C_1();
extern "C" void f_8025325C() {}
