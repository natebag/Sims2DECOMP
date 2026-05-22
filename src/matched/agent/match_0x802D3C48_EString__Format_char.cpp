// 0x802D3C48 EString::Format(char (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-160(1); mfspr 0,8; stmw 28,0x90(1); stw 0,0xa4(1); lis 12,512; addi 0,1,168; addi 11,1,8; stw 0,0x84(1); stw 11,0x88(1); mr 31,3; stw 5,0x10(1); stw 6,0x14(1); stw 7,0x18(1); stw 8,0x1c(1); stw 9,0x20(1); stw 10,0x24(1); stw 12,0x80(1); bne cr1,0f; stfd f1,0x28(1); stfd f2,0x30(1); stfd f3,0x38(1); stfd f4,0x40(1); stfd f5,0x48(1); stfd f6,0x50(1); stfd f7,0x58(1); stfd f8,0x60(1); 0:; addi 29,1,128; addi 30,1,112; lwz 0,0x4(29); mr 28,4; lwz 9,0x8(29); mr 5,28; stw 12,0x70(1); mr 6,30; stw 0,0x4(30); li 4,0; stw 9,0x8(30); li 3,0; bl _s802D3C48_0; mr 4,3; mr 3,31; bl _s802D3C48_1; lwz 9,0x80(1); mr 4,28; lwz 11,0x8(29); mr 5,30; lwz 0,0x4(29); stw 9,0x70(1); lwz 3,0x0(31); stw 0,0x4(30); stw 11,0x8(30); bl _s802D3C48_2; lwz 0,0xa4(1); mtspr 8,0; lmw 28,0x90(1); addi 1,1,160"
extern "C" void _s802D3C48_0();
extern "C" void _s802D3C48_1();
extern "C" void _s802D3C48_2();
extern "C" void f_802D3C48() {}
