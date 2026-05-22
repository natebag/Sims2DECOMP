// 0x803A0F54 StartScreenStartState::Startup(void) (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lis 3,-32693; addi 3,3,6104; bl _s803A0F54_0; lwz 9,-24644(13); lis 11,-32706; lfs f0,-30720(11); li 0,1; lfs f13,0x34(9); stw 0,0x2c(9); fcmpu 0,f13,f0; stfs f0,0x0(9); stw 0,0xc(9); stfs f0,0x8(9); bne 0f; lis 9,-32697; addi 9,9,23428; lwz 0,0x114(9); rlwinm 0,0,0,31,27; ori 0,0,1; stw 0,0x114(9); 0:; lis 30,-32692; lis 4,32602; ori 4,4,48173; addi 3,30,-17444; bl _s803A0F54_1; stw 3,0x1c(31); lis 3,-32697; addi 3,3,23428; bl _s803A0F54_2; mr 4,3; addi 3,30,-17444; bl _s803A0F54_3; stw 3,0x20(31); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s803A0F54_0();
extern "C" void _s803A0F54_1();
extern "C" void _s803A0F54_2();
extern "C" void _s803A0F54_3();
extern "C" void f_803A0F54() {}
