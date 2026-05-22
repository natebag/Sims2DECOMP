// 0x80224064 InteractorModule::WallPainter::WallPainter(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,3; bl _s80224064_0; lis 9,-32697; li 0,0; addi 9,9,-30600; stw 0,0x9c(30); stw 9,0x5c(30); addi 11,30,164; stw 0,0xa0(30); lis 9,-32698; stw 0,0x4(11); addi 9,9,28960; addi 11,30,172; li 10,4; stw 9,0x10(11); mr 3,30; stw 10,0xac(30); stw 0,0x20(11); stw 0,0x14(11); lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s80224064_0();
extern "C" void f_80224064() {}
