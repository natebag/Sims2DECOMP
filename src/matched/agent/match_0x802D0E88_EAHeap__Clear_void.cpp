// 0x802D0E88 EAHeap::Clear(void) (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; li 0,0; li 4,2; li 5,0; stw 0,0x534(30); bl _s802D0E88_0; mr 3,30; li 4,10; li 5,0; bl _s802D0E88_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802D0E88_0();
extern "C" void _s802D0E88_1();
extern "C" void f_802D0E88() {}
