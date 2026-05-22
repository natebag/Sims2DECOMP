// 0x80141350 cSimulatorImpl::SetCurrentHour(int) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 0,0; sth 4,0x14(31); li 3,215; li 4,0; sth 0,0x1e(31); bl _s80141350_0; lwz 9,0x0(31); lwz 0,0xf4(9); lha 3,0xf0(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x0(31); mr 30,3; lha 3,0x190(9); lwz 0,0x194(9); add 3,31,3; mtspr 8,0; blrl; cmpw 3,30; beq 0f; sth 3,0x1c(31); li 4,0; li 3,217; bl _s80141350_1; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80141350_0();
extern "C" void _s80141350_1();
extern "C" void f_80141350() {}
