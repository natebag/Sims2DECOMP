// 0x8034D3A4 ENgcSFXStreamer::SetRightVolume(unsigned (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stfd f31,0x18(1); stmw 30,0x10(1); stw 0,0x24(1); mr 30,4; fmr f31,f1; cmpwi 30,-1; beq 1f; bl _s8034D3A4_0; mulli 0,30,68; lis 9,-32690; addi 9,9,-19244; add 4,0,9; lwz 10,0x38(4); cmpwi 10,0; beq 0f; lis 11,-32702; lfs f0,0x20bc(11); fmuls f0,f31,f0; fctiwz f13,f0; stfd f13,0x8(1); lwz 9,0xc(1); stb 9,0x30(10); lwz 11,0x38(4); lbz 3,0x30(11); lwz 30,0x0(11); bl _s8034D3A4_1; mr 4,3; mr 3,30; bl _s8034D3A4_2; 0:; bl _s8034D3A4_3; 1:; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x10(1); lfd f31,0x18(1); addi 1,1,32"
extern "C" void _s8034D3A4_0();
extern "C" void _s8034D3A4_1();
extern "C" void _s8034D3A4_2();
extern "C" void _s8034D3A4_3();
extern "C" void f_8034D3A4() {}
