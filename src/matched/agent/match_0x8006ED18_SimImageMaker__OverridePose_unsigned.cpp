// 0x8006ED18 SimImageMaker::OverridePose(unsigned (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x218(3); addi 10,3,496; addi 8,3,508; addi 4,3,520; lwz 11,0x0(5); lwz 9,0x8(5); lwz 0,0x4(5); stw 11,0x1f0(3); stw 9,0x8(10); stw 0,0x4(10); lwz 9,0x0(6); lwz 0,0x8(6); lwz 11,0x4(6); stw 9,0x1fc(3); stw 0,0x8(8); stw 11,0x4(8); lwz 0,0x0(7); lwz 9,0x8(7); lwz 11,0x4(7); stw 0,0x208(3); stw 9,0x8(4); stw 11,0x4(4); stfs f1,0x214(3)"
extern "C" void f_8006ED18() {}
