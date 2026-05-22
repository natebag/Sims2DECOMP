// 0x80052154 ISimsCounterTopObject::Create(cXObject (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; stw 4,0x328(30); stw 5,0x3c8(30); bl _s80052154_0; mr 3,30; bl _s80052154_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80052154_0();
extern "C" void _s80052154_1();
extern "C" void f_80052154() {}
