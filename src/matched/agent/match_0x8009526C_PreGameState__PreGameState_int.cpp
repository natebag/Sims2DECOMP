// 0x8009526C PreGameState::PreGameState(int) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 11,-32698; mr 9,3; li 0,0; li 10,-1; li 8,1; addi 11,11,-8152; stw 4,0x0(9); stw 10,0xc(9); stw 11,0x18(9); stw 0,0x28(9); stw 8,0x2c(9); stw 10,0x4(9); stw 0,0x8(9); stw 0,0x10(9); stw 8,0x14(9); stw 0,0x1c(9); stw 0,0x24(9)"
extern "C" void f_8009526C() {}
