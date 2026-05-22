// 0x801410EC cSimulatorImpl::SetSpeed(SimSpeed) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; sth 4,0x34(30); bl _s801410EC_0; lis 9,-32706; li 3,189; lfs f0,-10676(9); li 4,0; stfs f0,0xa0(30); bl _s801410EC_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801410EC_0();
extern "C" void _s801410EC_1();
extern "C" void f_801410EC() {}
