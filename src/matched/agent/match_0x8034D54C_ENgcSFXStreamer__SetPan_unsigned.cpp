// 0x8034D54C ENgcSFXStreamer::SetPan(unsigned (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stfd f31,0x20(1); stw 31,0x1c(1); stw 0,0x2c(1); mr 31,4; fmr f31,f1; cmpwi 31,-1; beq 1f; bl _s8034D54C_0; lis 9,-32702; lis 11,-32702; lfs f0,0x20c4(9); mulli 0,31,68; lfs f13,0x20c8(11); lis 11,-32690; fmadds f0,f31,f0,f13; addi 11,11,-19244; add 10,0,11; fctiwz f12,f0; stfd f12,0x10(1); lwz 9,0x14(1); stb 9,0x31(10); mr 4,9; lwzx 3,11,0; cmpwi 3,0; beq 0f; rlwinm 4,4,0,24,31; bl _s8034D54C_1; 0:; bl _s8034D54C_2; 1:; lwz 0,0x2c(1); mtspr 8,0; lwz 31,0x1c(1); lfd f31,0x20(1); addi 1,1,40"
extern "C" void _s8034D54C_0();
extern "C" void _s8034D54C_1();
extern "C" void _s8034D54C_2();
extern "C" void f_8034D54C() {}
