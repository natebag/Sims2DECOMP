// 0x80132DD8 ReconBuffer::ReconBuffer(void) (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,3; li 0,0; li 11,2; li 10,1; stw 11,0xc(9); stw 0,0x2c(9); stw 10,0x10(9); stw 0,0x0(9); stw 0,0x4(9); stw 0,0x8(9); stw 0,0x14(9); stw 0,0x18(9); stw 0,0x1c(9); stw 0,0x20(9); stw 0,0x28(9)"
extern "C" void f_80132DD8() {}
