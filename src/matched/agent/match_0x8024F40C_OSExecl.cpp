// 0x8024F40C OSExecl (324 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-200(1); stw 31,0xc4(1); stw 30,0xc0(1); stw 29,0xbc(1); stw 28,0xb8(1); bne cr1,0f; stfd f1,0x28(1); stfd f2,0x30(1); stfd f3,0x38(1); stfd f4,0x40(1); stfd f5,0x48(1); stfd f6,0x50(1); stfd f7,0x58(1); stfd f8,0x60(1); 0:; stw 3,0x8(1); stw 4,0xc(1); stw 5,0x10(1); stw 6,0x14(1); stw 7,0x18(1); stw 8,0x1c(1); stw 9,0x20(1); stw 10,0x24(1); mr 28,3; mr 29,4; bl _s8024F40C_0; li 3,0; bl _s8024F40C_1; bl _s8024F40C_2; lis 3,-32472; bl _s8024F40C_3; lis 3,-32465; bl _s8024F40C_4; li 3,4; li 4,4096; bl _s8024F40C_5; lis 0,512; stw 0,0xac(1); addi 0,1,208; mr 30,3; stw 0,0xb0(1); addi 0,1,8; li 31,1; stw 0,0xb4(1); stw 29,0x0(30); b 1f; 1:; b 2f; 2:; addi 3,1,172; li 4,1; bl _s8024F40C_6; lwz 3,0x0(3); mr 0,31; rlwinm 0,0,2,0,29; cmplwi 3,0; stwx 3,30,0; addi 31,31,1; bne 2b; lbz 0,0x0(28); extsb 0,0; cmpwi 0,0; bne 3f; li 3,0; b 4f; 3:; mr 3,28; addi 4,1,112; bl _s8024F40C_7; cmpwi 3,0; beq 5f; lwz 3,0xa0(1); 4:; mr 5,30; lis 4,-16384; bl _s8024F40C_8; 5:; lwz 0,0xcc(1); lwz 31,0xc4(1); lwz 30,0xc0(1); lwz 29,0xbc(1); lwz 28,0xb8(1); addi 1,1,200; mtspr 8,0"
extern "C" void _s8024F40C_0();
extern "C" void _s8024F40C_1();
extern "C" void _s8024F40C_2();
extern "C" void _s8024F40C_3();
extern "C" void _s8024F40C_4();
extern "C" void _s8024F40C_5();
extern "C" void _s8024F40C_6();
extern "C" void _s8024F40C_7();
extern "C" void _s8024F40C_8();
extern "C" void f_8024F40C() {}
