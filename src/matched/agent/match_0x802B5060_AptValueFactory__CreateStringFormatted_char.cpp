// 0x802B5060 AptValueFactory::CreateStringFormatted(char (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-160(1); mfspr 0,8; stmw 29,0x94(1); stw 0,0xa4(1); lis 0,256; addi 11,1,168; addi 30,1,8; stw 0,0x80(1); stw 11,0x84(1); stw 30,0x88(1); stw 4,0xc(1); stw 5,0x10(1); stw 6,0x14(1); stw 7,0x18(1); stw 8,0x1c(1); stw 9,0x20(1); stw 10,0x24(1); bne cr1,0f; stfd f1,0x28(1); stfd f2,0x30(1); stfd f3,0x38(1); stfd f4,0x40(1); stfd f5,0x48(1); stfd f6,0x50(1); stfd f7,0x58(1); stfd f8,0x60(1); 0:; mr 29,3; lis 3,-32703; addi 3,3,11072; bl _s802B5060_0; lwz 10,0x80(1); addi 11,1,128; lwz 8,0x8(11); addi 9,1,112; lwz 0,0x4(11); mr 30,3; stw 10,0x70(1); addi 3,30,12; mr 4,29; stw 0,0x4(9); mr 5,9; stw 8,0x8(9); bl _s802B5060_1; mr 3,30; lwz 0,0xa4(1); mtspr 8,0; lmw 29,0x94(1); addi 1,1,160"
extern "C" void _s802B5060_0();
extern "C" void _s802B5060_1();
extern "C" void f_802B5060() {}
