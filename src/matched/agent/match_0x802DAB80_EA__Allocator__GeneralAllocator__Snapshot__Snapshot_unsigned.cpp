// 0x802DAB80 EA::Allocator::GeneralAllocator::Snapshot::Snapshot(unsigned (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 29,4; mr 28,5; li 4,0; mr 5,29; bl _s802DAB80_0; lis 9,21326; li 0,0; ori 9,9,16720; stw 29,0x4(30); stw 9,0x0(30); mr 3,30; stw 28,0x8(30); stw 0,0x28(30); stw 0,0xc(30); stw 0,0x10(30); stw 0,0x14(30); stw 0,0x18(30); stw 0,0x1c(30); stw 0,0x20(30); stw 0,0x24(30); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802DAB80_0();
extern "C" void f_802DAB80() {}
