// 0x8032C3A8 ENgcAudio::SetMusicVolume(float) (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stfd f31,0x28(1); stmw 29,0x1c(1); stw 0,0x34(1); lis 9,-32702; mr 30,3; lfs f0,0x14dc(9); fcmpu 0,f1,f0; ble 0f; fmr f1,f0; 0:; lis 9,-32702; lfs f0,0x14e0(9); fcmpu 0,f1,f0; bge 1f; fmr f1,f0; 1:; lwz 0,-26576(13); stfs f1,0x4(30); cmpwi 0,0; beq 4f; lis 11,-32692; lis 9,-32702; addi 31,11,9696; lfs f31,0x14e4(9); addi 29,31,4284; 2:; lwz 0,0x0(31); cmpwi 0,-1; beq 3f; lwz 4,0x40(31); cmpwi 4,-1; beq 3f; lfs f0,0x4(30); lwz 3,-26560(13); fmuls f0,f0,f31; fctiwz f13,f0; stfd f13,0x10(1); lwz 5,0x14(1); rlwinm 5,5,0,24,31; bl _s8032C3A8_0; 3:; addi 31,31,68; cmplw 31,29; ble 2b; 4:; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x1c(1); lfd f31,0x28(1); addi 1,1,48"
extern "C" void _s8032C3A8_0();
extern "C" void f_8032C3A8() {}
