// 0x8032C970 ENgcAudio::SetVoiceState(EVoice (304 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stfd f31,0x10(1); stmw 30,0x8(1); stw 0,0x1c(1); mr 30,4; mr 31,5; lwz 0,0x1c(30); cmpwi 0,0; bne 9f; lwz 0,0x0(31); andi. 9,0,8; beq 1f; lwz 0,0x10(31); cmpwi 0,0; beq 0f; lwz 3,-26556(13); lwz 4,0x8(30); lwz 5,0x4(30); bl _s8032C970_0; b 1f; 0:; lwz 3,-26556(13); lwz 4,0x8(30); bl _s8032C970_1; 1:; lwz 0,0x0(31); andi. 9,0,4; beq 2f; lwz 3,-26556(13); lwz 4,0x8(30); lfs f1,0xc(31); bl _s8032C970_2; 2:; lwz 0,0x0(31); andi. 9,0,1; beq 9f; lis 9,-32702; lfs f11,0x4(31); lfs f1,0x14fc(9); fcmpu 0,f11,f1; bge 3f; fneg f11,f11; 3:; lfs f12,0x8(31); fcmpu 0,f12,f1; bge 4f; fneg f12,f12; 4:; fcmpu 0,f12,f11; ble 5f; fdivs f0,f11,f12; lis 9,-32702; lfs f13,0x1500(9); fsubs f31,f13,f0; b 7f; 5:; fcmpu 0,f11,f12; ble 6f; fdivs f0,f12,f11; lis 9,-32702; lfs f13,0x1504(9); fadds f31,f0,f13; b 7f; 6:; fmr f31,f1; 7:; fmr f1,f12; fcmpu 0,f11,f12; ble 8f; fmr f1,f11; 8:; lwz 3,-26556(13); lwz 4,0x8(30); bl _s8032C970_3; lwz 4,0x8(30); fmr f1,f31; lwz 3,-26556(13); bl _s8032C970_4; 9:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x8(1); lfd f31,0x10(1); addi 1,1,24"
extern "C" void _s8032C970_0();
extern "C" void _s8032C970_1();
extern "C" void _s8032C970_2();
extern "C" void _s8032C970_3();
extern "C" void _s8032C970_4();
extern "C" void f_8032C970() {}
