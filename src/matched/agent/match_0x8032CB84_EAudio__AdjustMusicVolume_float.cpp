// 0x8032CB84 EAudio::AdjustMusicVolume(float) (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stfd f31,0x10(1); stmw 30,0x8(1); stw 0,0x1c(1); mr 31,3; fmr f31,f1; lwz 9,0x0(31); li 30,0; lha 3,0x68(9); lwz 0,0x6c(9); add 3,31,3; mtspr 8,0; blrl; lis 9,-32702; fadds f1,f1,f31; lfs f0,0x1508(9); fcmpu 0,f1,f0; bgt 0f; lis 9,-32702; lfs f0,0x150c(9); fcmpu 0,f1,f0; bge 1f; 0:; fmr f1,f0; li 30,1; 1:; lwz 9,0x0(31); lha 3,0x60(9); lwz 0,0x64(9); add 3,31,3; mtspr 8,0; blrl; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x8(1); lfd f31,0x10(1); addi 1,1,24"
extern "C" void f_8032CB84() {}
