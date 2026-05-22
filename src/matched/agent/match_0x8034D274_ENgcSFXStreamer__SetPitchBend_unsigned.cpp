// 0x8034D274 ENgcSFXStreamer::SetPitchBend(unsigned (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stfd f31,0x18(1); stmw 30,0x10(1); stw 0,0x24(1); fmr f31,f1; cmpwi 4,-1; beq 0f; mulli 31,4,68; lis 9,-32690; addi 30,9,-19244; lwzx 0,30,31; cmpwi 0,0; beq 0f; bl _s8034D274_0; addi 9,30,36; lwzx 8,9,31; lis 7,17200; lis 9,-32702; lis 10,-32702; lwz 0,0x8(8); lfd f0,0x20b0(9); stw 0,0xc(1); lfs f13,0x20b8(10); stw 7,0x8(1); lwzx 3,30,31; lfd f1,0x8(1); fsub f1,f1,f0; frsp f1,f1; fmuls f1,f1,f31; fdivs f1,f1,f13; bl _s8034D274_1; bl _s8034D274_2; 0:; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x10(1); lfd f31,0x18(1); addi 1,1,32"
extern "C" void _s8034D274_0();
extern "C" void _s8034D274_1();
extern "C" void _s8034D274_2();
extern "C" void f_8034D274() {}
