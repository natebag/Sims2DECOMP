// 0x8032C470 ENgcAudio::SetMusicPan(float) (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); lis 9,-32702; lfs f0,0x14e8(9); fcmpu 0,f1,f0; bge 0f; lis 9,-32702; lfs f0,0x14ec(9); b 1f; 0:; lis 9,-32702; lfs f0,0x14f0(9); fcmpu 0,f1,f0; ble 2f; lis 9,-32702; lfs f0,0x14f4(9); 1:; fsubs f1,f0,f1; 2:; lwz 0,-26576(13); stfs f1,0x8(3); cmpwi 0,0; beq 5f; lis 11,-32702; lfs f0,0x14f8(11); lis 11,-32692; fmadds f0,f1,f0,f0; addi 31,11,9696; addi 29,31,4284; fctiwz f13,f0; stfd f13,0x10(1); lwz 9,0x14(1); rlwinm 30,9,0,24,31; 3:; lwz 0,0x0(31); cmpwi 0,-1; beq 4f; lwz 4,0x40(31); cmpwi 4,-1; beq 4f; lwz 3,-26560(13); mr 5,30; bl _s8032C470_0; 4:; addi 31,31,68; cmplw 31,29; ble 3b; 5:; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s8032C470_0();
extern "C" void f_8032C470() {}
