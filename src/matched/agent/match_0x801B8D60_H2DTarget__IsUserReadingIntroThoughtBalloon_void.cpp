// 0x801B8D60 H2DTarget::IsUserReadingIntroThoughtBalloon(void) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 3,0xc4(3); li 31,0; cmpwi 3,0; beq 0f; bl _s801B8D60_0; lis 9,-32705; lfs f0,0x1424(9); fcmpu 0,f1,f0; ble 0f; li 31,1; 0:; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s801B8D60_0();
extern "C" void f_801B8D60() {}
