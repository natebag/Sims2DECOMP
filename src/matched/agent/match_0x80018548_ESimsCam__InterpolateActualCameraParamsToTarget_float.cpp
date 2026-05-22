// 0x80018548 ESimsCam::InterpolateActualCameraParamsToTarget(float) (672 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stfd f31,0x38(1); stmw 27,0x24(1); stw 0,0x44(1); mr 31,3; fmr f31,f1; lwz 0,0x46c(31); cmpwi 0,0; bne 0f; bl _s80018548_0; lis 9,-32707; li 0,1; lfs f0,-7272(9); stw 0,0x46c(31); stfs f0,0x470(31); b 16f; 0:; lfs f0,0x454(31); addi 28,31,1108; lwz 11,0x0(31); addi 9,1,8; stfs f0,0x8(1); mr 27,9; lfs f0,0x4(28); stfs f0,0x4(9); lwz 0,0x4(11); cmpwi 0,0; bne 1f; mr 3,31; bl _s80018548_1; b 13f; 1:; mr 3,31; addi 30,31,1084; bl _s80018548_2; addi 29,31,1120; mr 4,30; fmr f2,f31; mr 3,28; addi 30,31,1096; bl _s80018548_3; mr 3,31; bl _s80018548_4; mr 3,29; mr 4,30; fmr f2,f31; bl _s80018548_5; lfs f13,0x464(31); lis 9,-32707; lfs f12,0x44c(31); lfs f11,-7268(9); fsubs f0,f13,f12; fcmpu 0,f0,f11; ble 2f; lis 9,-32707; lfs f0,-7264(9); fsubs f0,f13,f0; b 3f; 2:; fsubs f0,f12,f13; fcmpu 0,f0,f11; ble 4f; lis 9,-32707; lfs f0,-7264(9); fadds f0,f13,f0; 3:; stfs f0,0x464(31); 4:; mr 3,31; addi 30,31,1124; bl _s80018548_6; addi 4,31,1100; mr 3,30; fmr f2,f31; bl _s80018548_7; lis 9,-32707; lfs f13,0x464(31); lfs f12,-7264(9); fcmpu 0,f13,f12; ble 5f; fsubs f0,f13,f12; b 6f; 5:; lis 9,-32707; lfs f0,-7272(9); fcmpu 0,f13,f0; bge 7f; fadds f0,f13,f12; 6:; stfs f0,0x464(31); 7:; lfs f13,0x468(31); lis 9,-32707; lfs f12,0x450(31); lfs f11,-7268(9); fsubs f0,f13,f12; fcmpu 0,f0,f11; ble 8f; lis 9,-32707; lfs f0,-7264(9); fsubs f0,f13,f0; b 9f; 8:; fsubs f0,f12,f13; fcmpu 0,f0,f11; ble 10f; lis 9,-32707; lfs f0,-7264(9); fadds f0,f13,f0; 9:; stfs f0,0x468(31); 10:; mr 3,31; addi 30,31,1128; bl _s80018548_8; addi 4,31,1104; mr 3,30; fmr f2,f31; bl _s80018548_9; lis 9,-32707; lfs f13,0x468(31); lfs f12,-7264(9); fcmpu 0,f13,f12; ble 11f; fsubs f0,f13,f12; b 12f; 11:; lis 9,-32707; lfs f0,-7272(9); fcmpu 0,f13,f0; bge 13f; fadds f0,f13,f12; 12:; stfs f0,0x468(31); 13:; lwz 0,0x564(31); cmpwi 0,0; bne 14f; lwz 0,0x568(31); cmpwi 0,0; beq 15f; 14:; lfs f0,0x460(31); lis 9,-32707; lfs f13,0x448(31); lfs f12,-7260(9); fsubs f0,f0,f13; fabs f0,f0; fcmpu 0,f0,f12; bge 15f; li 11,0; lwz 0,0x4(31); lis 9,-32697; stw 11,0x568(31); addi 9,9,24012; stw 11,0x564(31); rlwinm 0,0,2,0,29; addi 9,9,280; lwzx 3,9,0; bl _s80018548_10; bl _s80018548_11; 15:; lfs f13,0x4(27); lfs f11,0x458(31); lfs f0,0x454(31); lfs f12,0x8(1); fsubs f13,f11,f13; stfs f0,0x10(1); fmuls f1,f13,f13; fsubs f0,f0,f12; stfs f11,0x14(1); fmadds f1,f0,f0,f1; stfs f0,0x18(1); stfs f13,0x1c(1); bl _s80018548_12; fdivs f1,f1,f31; stfs f1,0x470(31); 16:; lwz 0,0x44(1); mtspr 8,0; lmw 27,0x24(1); lfd f31,0x38(1); addi 1,1,64"
extern "C" void _s80018548_0();
extern "C" void _s80018548_1();
extern "C" void _s80018548_2();
extern "C" void _s80018548_3();
extern "C" void _s80018548_4();
extern "C" void _s80018548_5();
extern "C" void _s80018548_6();
extern "C" void _s80018548_7();
extern "C" void _s80018548_8();
extern "C" void _s80018548_9();
extern "C" void _s80018548_10();
extern "C" void _s80018548_11();
extern "C" void _s80018548_12();
extern "C" void f_80018548() {}
