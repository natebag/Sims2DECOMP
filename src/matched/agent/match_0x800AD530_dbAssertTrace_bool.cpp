// 0x800AD530 dbAssertTrace(bool, (248 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-4256(1); mfspr 0,8; stmw 29,0x1094(1); stw 0,0x10a4(1); lis 30,512; addi 0,1,4264; addi 11,1,8; stw 0,0x1084(1); stw 11,0x1088(1); mr 31,3; stw 5,0x10(1); stw 6,0x14(1); stw 7,0x18(1); stw 8,0x1c(1); stw 9,0x20(1); stw 10,0x24(1); stw 30,0x1080(1); bne cr1,0f; stfd f1,0x28(1); stfd f2,0x30(1); stfd f3,0x38(1); stfd f4,0x40(1); stfd f5,0x48(1); stfd f6,0x50(1); stfd f7,0x58(1); stfd f8,0x60(1); 0:; cmpwi 31,0; beq 1f; li 3,0; b 4f; 1:; addi 11,1,4224; lwz 29,-24512(13); lwz 0,0x4(11); addi 9,1,112; lwz 10,0x8(11); mr 5,9; stw 30,0x70(1); addi 30,1,128; stw 0,0x4(9); stw 10,0x8(9); mr 3,30; stw 31,-24512(13); bl _s800AD530_0; li 0,1; stw 30,-24516(13); stw 0,-32116(13); mr 3,29; stw 0,-32120(13); bl _s800AD530_1; cmpwi 3,0; beq 3f; bl _s800AD530_2; cmpwi 3,0; beq 2f; stw 31,0x0(31); 2:; .long 0x00000001; 3:; li 3,1; 4:; lwz 0,0x10a4(1); mtspr 8,0; lmw 29,0x1094(1); addi 1,1,4256"
extern "C" void _s800AD530_0();
extern "C" void _s800AD530_1();
extern "C" void _s800AD530_2();
extern "C" void f_800AD530() {}
