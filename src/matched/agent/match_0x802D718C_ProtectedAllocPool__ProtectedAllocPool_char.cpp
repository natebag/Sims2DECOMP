// 0x802D718C ProtectedAllocPool::ProtectedAllocPool(char (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s802D718C_0; lis 9,-32697; addi 3,30,24; addi 9,9,-23872; stw 9,0x14(30); bl _s802D718C_1; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802D718C_0();
extern "C" void _s802D718C_1();
extern "C" void f_802D718C() {}
