// 0x803CA150 TArray<TArray<SndEvtHitPatch, (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 3,0x0(30); lwz 4,0x4(30); bl _s803CA150_0; lis 3,-32692; lwz 4,0x0(30); addi 3,3,-14084; bl _s803CA150_1; mr 3,30; bl _s803CA150_2; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s803CA150_0();
extern "C" void _s803CA150_1();
extern "C" void _s803CA150_2();
extern "C" void f_803CA150() {}
