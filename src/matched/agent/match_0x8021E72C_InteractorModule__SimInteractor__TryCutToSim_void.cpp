// 0x8021E72C InteractorModule::SimInteractor::TryCutToSim(void) (356 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 29,0x3c(1); stw 0,0x4c(1); mr 31,3; lis 9,-32697; lwz 0,0x0(31); addi 9,9,24012; lwz 11,0x19c(31); addi 9,9,188; rlwinm 0,0,2,0,29; lwzx 4,9,0; cmpwi 11,0; beq 2f; cmpwi 4,0; beq 2f; addi 29,1,24; li 5,1; mr 3,29; li 6,0; bl _s8021E72C_0; lwz 9,0x19c(31); addi 8,1,40; lfs f12,0x18(1); addi 10,1,8; lfs f13,0x0(9); mr 3,10; lfs f10,0x8(9); fsubs f12,f12,f13; lfs f11,0x4(9); lfs f0,0x1c(1); lfs f13,0x20(1); stfs f12,0x28(1); fsubs f0,f0,f11; fsubs f13,f13,f10; stfs f0,0x2c(1); stfs f13,0x30(1); lwz 9,0x28(1); lwz 11,0x8(8); lwz 0,0x4(8); stw 9,0x8(1); stw 0,0x4(10); stw 11,0x8(10); bl _s8021E72C_1; lis 9,-32704; lfs f0,-8936(9); fcmpu 0,f1,f0; cror 3,2,0; bns 1f; lwz 10,0x18(1); addi 30,31,8; lwz 9,0x19c(31); lwz 0,0x20(1); lwz 8,0x1c(1); addi 11,9,296; stw 10,0x128(9); stw 8,0x4(11); stw 0,0x8(11); lwz 11,0x18(1); lwz 0,0x20(1); lwz 10,0x1c(1); lwz 9,0x19c(31); stw 10,0x4(9); stw 11,0x0(9); stw 0,0x8(9); lwz 11,0x18(1); lwz 9,0x8(29); lwz 0,0x4(29); stw 11,0x8(31); stw 0,0x4(30); stw 9,0x8(30); bl _s8021E72C_2; lwz 4,0x0(31); bl _s8021E72C_3; mr. 3,3; beq 0f; mr 4,30; bl _s8021E72C_4; 0:; mr 3,31; bl _s8021E72C_5; b 2f; 1:; lwz 3,0x19c(31); li 4,3; bl _s8021E72C_6; 2:; lwz 0,0x4c(1); mtspr 8,0; lmw 29,0x3c(1); addi 1,1,72"
extern "C" void _s8021E72C_0();
extern "C" void _s8021E72C_1();
extern "C" void _s8021E72C_2();
extern "C" void _s8021E72C_3();
extern "C" void _s8021E72C_4();
extern "C" void _s8021E72C_5();
extern "C" void _s8021E72C_6();
extern "C" void f_8021E72C() {}
