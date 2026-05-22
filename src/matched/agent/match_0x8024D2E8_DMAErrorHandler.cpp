// 0x8024D2E8 DMAErrorHandler (352 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-128(1); stw 31,0x7c(1); stw 30,0x78(1); stw 29,0x74(1); bne cr1,0f; stfd f1,0x28(1); stfd f2,0x30(1); stfd f3,0x38(1); stfd f4,0x40(1); stfd f5,0x48(1); stfd f6,0x50(1); stfd f7,0x58(1); stfd f8,0x60(1); 0:; stw 3,0x8(1); stw 4,0xc(1); stw 5,0x10(1); stw 6,0x14(1); stw 7,0x18(1); stw 8,0x1c(1); stw 9,0x20(1); stw 10,0x24(1); mr 29,4; lis 3,-32700; addi 31,3,-20544; bl _s8024D2E8_0; mr 30,3; crxor 6,6,6; addi 3,31,44; bl _s8024D2E8_1; lwz 5,0x19c(29); mr 4,30; addi 3,31,68; crxor 6,6,6; bl _s8024D2E8_2; rlwinm 0,30,0,8,11; cmplwi 0,0; beq 1f; lwz 0,0x19c(29); rlwinm 0,0,0,10,10; cmplwi 0,0; bne 2f; 1:; addi 3,31,96; crxor 6,6,6; bl _s8024D2E8_3; mr 3,29; bl _s8024D2E8_4; bl _s8024D2E8_5; 2:; addi 3,31,144; crxor 6,6,6; bl _s8024D2E8_6; addi 3,31,204; crxor 6,6,6; bl _s8024D2E8_7; rlwinm 0,30,0,8,8; cmplwi 0,0; beq 3f; addi 3,31,260; crxor 6,6,6; bl _s8024D2E8_8; 3:; rlwinm 0,30,0,9,9; cmplwi 0,0; beq 4f; addi 3,31,324; crxor 6,6,6; bl _s8024D2E8_9; 4:; rlwinm 0,30,0,10,10; cmplwi 0,0; beq 5f; addi 3,31,368; crxor 6,6,6; bl _s8024D2E8_10; 5:; rlwinm 0,30,0,11,11; cmplwi 0,0; beq 6f; addi 3,31,400; crxor 6,6,6; bl _s8024D2E8_11; 6:; mr 3,30; bl _s8024D2E8_12; lwz 0,0x84(1); lwz 31,0x7c(1); lwz 30,0x78(1); lwz 29,0x74(1); addi 1,1,128; mtspr 8,0"
extern "C" void _s8024D2E8_0();
extern "C" void _s8024D2E8_1();
extern "C" void _s8024D2E8_2();
extern "C" void _s8024D2E8_3();
extern "C" void _s8024D2E8_4();
extern "C" void _s8024D2E8_5();
extern "C" void _s8024D2E8_6();
extern "C" void _s8024D2E8_7();
extern "C" void _s8024D2E8_8();
extern "C" void _s8024D2E8_9();
extern "C" void _s8024D2E8_10();
extern "C" void _s8024D2E8_11();
extern "C" void _s8024D2E8_12();
extern "C" void f_8024D2E8() {}
