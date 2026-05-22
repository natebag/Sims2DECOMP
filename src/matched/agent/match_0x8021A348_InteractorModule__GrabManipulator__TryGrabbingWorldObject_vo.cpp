// 0x8021A348 InteractorModule::GrabManipulator::TryGrabbingWorldObject(void) (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); addi 30,1,8; li 9,0; stw 9,0x4(30); li 0,1; stw 9,0x8(1); mr 31,3; mr 3,30; stw 0,0x8(30); bl _s8021A348_0; mr 29,30; lis 9,-32697; lwz 4,0x0(31); lwz 11,0x5e94(9); mr 5,30; lwz 3,0x4(11); bl _s8021A348_1; lwz 3,0x8(1); cmpwi 3,0; beq 0f; lwz 0,0x4(29); cmpw 3,0; bne 0f; lwz 3,0x0(3); bl _s8021A348_2; lwz 9,0x4(3); lha 0,0x328(9); lwz 9,0x32c(9); add 3,3,0; mtspr 8,9; blrl; mr 4,3; mr 3,31; bl _s8021A348_3; b 1f; 0:; lwz 0,0x8(1); cmpwi 0,0; beq 1f; lwz 9,0x5c(31); lha 3,0x78(9); lwz 0,0x7c(9); add 3,31,3; mtspr 8,0; blrl; lis 9,-32697; lwz 3,0x5bf8(9); cmpwi 3,0; beq 1f; mr 4,29; bl _s8021A348_4; 1:; mr 3,29; bl _s8021A348_5; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s8021A348_0();
extern "C" void _s8021A348_1();
extern "C" void _s8021A348_2();
extern "C" void _s8021A348_3();
extern "C" void _s8021A348_4();
extern "C" void _s8021A348_5();
extern "C" void f_8021A348() {}
