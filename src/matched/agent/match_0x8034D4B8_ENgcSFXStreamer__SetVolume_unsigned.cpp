// 0x8034D4B8 ENgcSFXStreamer::SetVolume(unsigned (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stfd f31,0x20(1); stw 31,0x1c(1); stw 0,0x2c(1); mr 31,4; fmr f31,f1; cmpwi 31,-1; beq 1f; bl _s8034D4B8_0; lis 9,-32702; mulli 0,31,68; lfs f0,0x20c0(9); lis 11,-32690; addi 11,11,-19244; fmuls f0,f31,f0; add 10,0,11; fctiwz f13,f0; stfd f13,0x10(1); lwz 9,0x14(1); stb 9,0x30(10); mr 3,9; lwzx 31,11,0; cmpwi 31,0; beq 0f; rlwinm 3,3,0,24,31; bl _s8034D4B8_1; mr 4,3; mr 3,31; bl _s8034D4B8_2; 0:; bl _s8034D4B8_3; 1:; lwz 0,0x2c(1); mtspr 8,0; lwz 31,0x1c(1); lfd f31,0x20(1); addi 1,1,40"
extern "C" void _s8034D4B8_0();
extern "C" void _s8034D4B8_1();
extern "C" void _s8034D4B8_2();
extern "C" void _s8034D4B8_3();
extern "C" void f_8034D4B8() {}
