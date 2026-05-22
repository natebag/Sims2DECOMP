// 0x8001DB94 CameraDirector::UpdateAnimNoteTrack(void) (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s8001DB94_0; lwz 0,0x31c(31); andi. 9,0,1; beq 0f; lwz 11,-21496(13); lwz 9,0x0(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; lfs f13,-26800(13); lis 9,-32707; lfs f0,-6740(9); fmuls f13,f13,f1; fcmpu 0,f13,f0; ble 0f; lfs f0,0x2d4(31); mr 3,31; fadds f0,f0,f13; stfs f0,0x2d4(31); bl _s8001DB94_1; 0:; lwz 0,0x31c(31); andi. 9,0,2; beq 1f; lwz 11,-21496(13); lwz 9,0x0(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; lfs f13,-26800(13); lis 9,-32707; lfs f0,-6740(9); fmuls f13,f13,f1; fcmpu 0,f13,f0; ble 1f; lfs f0,0x2d8(31); mr 3,31; fadds f0,f0,f13; stfs f0,0x2d8(31); bl _s8001DB94_2; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8001DB94_0();
extern "C" void _s8001DB94_1();
extern "C" void _s8001DB94_2();
extern "C" void f_8001DB94() {}
