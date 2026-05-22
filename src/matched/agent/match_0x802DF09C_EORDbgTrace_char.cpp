// 0x802DF09C EORDbgTrace(char (316 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-168(1); mfspr 0,8; stmw 30,0xa0(1); stw 0,0xac(1); lis 0,256; addi 11,1,176; addi 30,1,8; stw 0,0x90(1); stw 11,0x94(1); stw 30,0x98(1); stw 4,0xc(1); stw 5,0x10(1); stw 6,0x14(1); stw 7,0x18(1); stw 8,0x1c(1); stw 9,0x20(1); stw 10,0x24(1); bne cr1,0f; stfd f1,0x28(1); stfd f2,0x30(1); stfd f3,0x38(1); stfd f4,0x40(1); stfd f5,0x48(1); stfd f6,0x50(1); stfd f7,0x58(1); stfd f8,0x60(1); 0:; lwz 0,-22776(13); mr 30,3; cmpwi 0,0; bne 1f; lis 3,-32693; addi 3,3,-12936; bl _s802DF09C_0; li 0,1; lis 3,-32722; stw 0,-22776(13); addi 3,3,-3984; bl _s802DF09C_1; 1:; lis 4,-32693; addi 3,1,112; addi 4,4,-12936; li 5,1; li 6,1; bl _s802DF09C_2; li 3,0; cmpwi 30,0; beq 2f; lwz 11,0x90(1); addi 9,1,144; lwz 10,0x8(9); addi 5,1,128; lwz 0,0x4(9); lis 3,-32693; stw 11,0x80(1); addi 3,3,-23176; stw 0,0x4(5); mr 4,30; stw 10,0x8(5); bl _s802DF09C_3; 2:; cmpwi 3,0; bgt 3f; addi 3,1,112; li 4,2; bl _s802DF09C_4; b 4f; 3:; lis 3,-32702; lis 4,-32693; addi 4,4,-23176; addi 3,3,-6488; crxor 6,6,6; bl _s802DF09C_5; addi 3,1,112; li 4,2; bl _s802DF09C_6; 4:; lwz 0,0xac(1); mtspr 8,0; lmw 30,0xa0(1); addi 1,1,168"
extern "C" void _s802DF09C_0();
extern "C" void _s802DF09C_1();
extern "C" void _s802DF09C_2();
extern "C" void _s802DF09C_3();
extern "C" void _s802DF09C_4();
extern "C" void _s802DF09C_5();
extern "C" void _s802DF09C_6();
extern "C" void f_802DF09C() {}
