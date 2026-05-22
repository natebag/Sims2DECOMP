// 0x803577B8 FrameEffectsManager::Init(void) (248 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; li 3,56; bl _s803577B8_0; lis 11,-32702; lis 8,-32702; lfs f11,0x2b54(11); lis 9,-32702; lis 10,-32702; lfs f13,0x2b5c(9); lfs f12,0x2b58(8); lis 11,-32697; lfs f0,0x2b60(10); mr 9,3; li 10,1; addi 11,11,-10488; stw 11,0x10(9); addi 7,9,20; stfs f11,0x4(9); li 0,0; stfs f12,0x8(9); addi 8,9,32; stw 10,0xc(9); addi 6,9,44; stfs f11,0x0(9); lis 11,-32697; stfs f13,0x14(9); addi 11,11,-10232; stw 0,0x8(7); li 3,152; stfs f0,0x4(7); stfs f13,0x20(9); stw 0,0x8(8); stfs f0,0x4(8); stfs f13,0x2c(9); stw 0,0x8(6); stfs f0,0x4(6); stw 11,0x10(9); stw 9,0x0(29); bl _s803577B8_1; mr 30,3; bl _s803577B8_2; lis 9,-32697; stw 30,0x4(29); addi 9,9,-10296; li 3,80; stw 9,0x10(30); bl _s803577B8_3; mr 30,3; bl _s803577B8_4; lis 9,-32697; stw 30,0x8(29); addi 9,9,-10360; stw 9,0x10(30); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s803577B8_0();
extern "C" void _s803577B8_1();
extern "C" void _s803577B8_2();
extern "C" void _s803577B8_3();
extern "C" void _s803577B8_4();
extern "C" void f_803577B8() {}
