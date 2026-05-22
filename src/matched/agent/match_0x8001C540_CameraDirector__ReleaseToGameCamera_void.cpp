// 0x8001C540 CameraDirector::ReleaseToGameCamera(void) (348 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 29,0x4c(1); stw 0,0x5c(1); mr 31,3; lwz 0,0x238(31); cmpwi 0,2; beq 0f; lwz 0,0x240(31); xori 0,0,1; andi. 9,0,1; bne 1f; 0:; li 3,0; b 4f; 1:; mr 3,31; bl _s8001C540_0; bl _s8001C540_1; lwz 11,0x170(31); cmpwi 11,0; beq 2f; lis 9,-32707; lfs f0,0x324(31); lfs f13,-6812(9); fcmpu 0,f0,f13; ble 2f; lwz 9,0x0(11); lfs f0,0x328(31); stfs f0,0x2c(9); lwz 11,0x170(31); lfs f0,0x324(31); lwz 9,0x0(11); stfs f0,0x28(9); stfs f13,0x324(31); stfs f13,0x328(31); 2:; mr 3,31; li 4,0; bl _s8001C540_2; lwz 0,0x320(31); cmpwi 0,0; beq 3f; lwz 3,0x170(31); cmpwi 3,0; beq 3f; addi 30,1,40; addi 29,1,24; addi 4,1,8; mr 5,29; mr 6,30; bl _s8001C540_3; lis 11,-32707; lis 10,-32707; lfs f0,-6812(11); addi 9,1,56; lfs f13,-6808(10); mr 3,31; stfs f0,0x38(1); stfs f0,0x4(9); stfs f13,0x8(9); lwz 10,0x4(9); lwz 0,0x38(1); lwz 11,0x8(9); stw 0,0x28(1); stw 11,0x8(30); stw 10,0x4(30); bl _s8001C540_4; lwz 3,0x170(31); mr 5,29; mr 6,30; addi 4,1,8; bl _s8001C540_5; lwz 3,0x170(31); lwz 9,0x0(3); lfs f1,0x28(9); bl _s8001C540_6; lwz 11,0x170(31); li 0,1; li 9,0; stw 0,0x568(11); stw 9,0x320(31); 3:; mr 3,31; bl _s8001C540_7; li 3,1; 4:; lwz 0,0x5c(1); mtspr 8,0; lmw 29,0x4c(1); addi 1,1,88"
extern "C" void _s8001C540_0();
extern "C" void _s8001C540_1();
extern "C" void _s8001C540_2();
extern "C" void _s8001C540_3();
extern "C" void _s8001C540_4();
extern "C" void _s8001C540_5();
extern "C" void _s8001C540_6();
extern "C" void _s8001C540_7();
extern "C" void f_8001C540() {}
