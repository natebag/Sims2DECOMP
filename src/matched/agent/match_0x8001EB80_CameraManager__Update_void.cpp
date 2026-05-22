// 0x8001EB80 CameraManager::Update(void) (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lis 9,-32697; lwz 0,0x0(31); addi 30,9,24012; lwz 29,0xe0(30); cmpwi 0,0; beq 0f; lwz 4,0x118(30); mr 3,30; bl _s8001EB80_0; lwz 11,0x0(31); lwz 9,0x56c(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; lwz 9,0x0(31); lfs f0,0x44c(9); stfs f0,0x164(30); 0:; lwz 0,0x4(31); cmpwi 0,0; beq 1f; lis 3,-32697; li 4,1; addi 3,3,23428; bl _s8001EB80_1; cmpwi 3,0; beq 1f; mr 3,30; lwz 4,0x11c(3); bl _s8001EB80_2; lwz 3,0x4(31); lwz 9,0x56c(3); lha 0,0x10(9); lwz 9,0x14(9); add 3,3,0; mtspr 8,9; blrl; 1:; lis 3,-32697; mr 4,29; addi 3,3,24012; bl _s8001EB80_3; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8001EB80_0();
extern "C" void _s8001EB80_1();
extern "C" void _s8001EB80_2();
extern "C" void _s8001EB80_3();
extern "C" void f_8001EB80() {}
