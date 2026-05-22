// 0x80364DAC ERenderSurface::ERenderSurface(void) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); lis 11,-32697; mr 9,3; li 10,64; addi 11,11,-9552; li 8,1; li 0,3; stw 10,0x0(9); lis 7,-32702; stw 10,0x4(9); addi 6,9,12; stw 11,0x20(9); li 5,-1; stw 0,0x8(9); stw 8,0x1c(9); stw 8,0x18(9); lfs f0,0x3104(7); stfs f0,0x8(1); stfs f0,0x10(1); stfs f0,0xc(1); lwz 11,0x8(1); lwz 10,0xc(1); lwz 0,0x10(1); stw 11,0xc(9); stw 0,0x8(6); stw 10,0x4(6); stw 5,0x0(9); stw 5,0x4(9); addi 1,1,24"
extern "C" void f_80364DAC() {}
