// 0x8024FA3C __OSUnmaskInterrupts (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); stw 29,0x14(1); mr 31,3; bl _s8024FA3C_0; lis 4,-32768; lwz 29,0xc4(4); mr 30,3; lwz 5,0xc8(4); or 0,29,5; and 3,31,0; andc 31,29,31; stw 31,0xc4(4); or 31,31,5; b 0f; 0:; b 1f; 1:; b 3f; 2:; mr 4,31; bl _s8024FA3C_1; 3:; cmplwi 3,0; bne 2b; mr 3,30; bl _s8024FA3C_2; mr 3,29; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s8024FA3C_0();
extern "C" void _s8024FA3C_1();
extern "C" void _s8024FA3C_2();
extern "C" void f_8024FA3C() {}
