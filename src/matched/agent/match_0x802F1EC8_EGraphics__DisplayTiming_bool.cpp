// 0x802F1EC8 EGraphics::DisplayTiming(bool, (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 9,0x4(5); mr 31,3; lwz 0,0x0(5); mr. 30,4; stw 9,0xa0(31); stw 0,0x9c(31); beq 0f; bl _s802F1EC8_0; 0:; stw 30,0x14(31); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802F1EC8_0();
extern "C" void f_802F1EC8() {}
