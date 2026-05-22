// 0x80224180 InteractorModule::WallPainter::OnCreate(void) (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s80224180_0; mr 4,30; bl _s80224180_1; lis 9,-32704; lis 11,-32704; lfs f0,-7472(9); lfs f13,-7468(11); stfs f0,0x50(30); stfs f13,0x54(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80224180_0();
extern "C" void _s80224180_1();
extern "C" void f_80224180() {}
