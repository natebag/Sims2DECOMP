// 0x80097090 TheSimsMemCardCheckState::Startup(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32697; mr 30,3; li 0,1; lwz 3,0x5e80(9); li 4,1; stw 0,-28404(13); stw 0,-28408(13); bl _s80097090_0; lis 9,-32706; mr 3,30; lfs f1,-29824(9); li 4,2; bl _s80097090_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80097090_0();
extern "C" void _s80097090_1();
extern "C" void f_80097090() {}
