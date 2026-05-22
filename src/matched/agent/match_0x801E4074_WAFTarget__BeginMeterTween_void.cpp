// 0x801E4074 WAFTarget::BeginMeterTween(void) (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stfd f31,0x10(1); stw 31,0xc(1); stw 0,0x1c(1); mr 31,3; lwz 0,0x268(31); cmpwi 0,1; bne 1f; lis 9,-32705; lfs f0,0x274(31); lfs f13,0x6490(9); fcmpu 0,f0,f13; ble 0f; lfs f0,0x278(31); fcmpu 0,f0,f13; bge 4f; bl _s801E4074_0; b 6f; 0:; lfs f0,0x278(31); fcmpu 0,f0,f13; bgt 4f; mr 3,31; bl _s801E4074_1; b 6f; 1:; lis 9,-32705; lfs f0,0x278(31); lfs f31,0x6490(9); fcmpu 0,f0,f31; bne 3f; lfs f0,0x274(31); fcmpu 0,f0,f31; bge 2f; mr 3,31; bl _s801E4074_2; 2:; lfs f0,0x274(31); fcmpu 0,f0,f31; ble 6f; b 4f; 3:; ble 5f; 4:; mr 3,31; bl _s801E4074_3; b 6f; 5:; mr 3,31; bl _s801E4074_4; 6:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0xc(1); lfd f31,0x10(1); addi 1,1,24"
extern "C" void _s801E4074_0();
extern "C" void _s801E4074_1();
extern "C" void _s801E4074_2();
extern "C" void _s801E4074_3();
extern "C" void _s801E4074_4();
extern "C" void f_801E4074() {}
