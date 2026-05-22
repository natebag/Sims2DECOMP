// 0x8025C0C4 DVDPrepareStream (324 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-48(1); stmw 27,0x1c(1); addi 29,5,0; mr 27,3; addi 28,4,0; lwz 6,0x30(3); lis 3,-32700; addi 31,3,-15584; add 5,6,29; rlwinm. 0,5,0,17,31; addi 30,5,0; beq 0f; crxor 6,6,6; addi 7,29,0; addi 5,31,740; addi 3,13,-27800; li 4,1288; bl _s8025C0C4_0; 0:; cmplwi 28,0; bne 1f; lwz 0,0x34(27); subf 28,29,0; 1:; rlwinm. 0,28,0,17,31; beq 2f; addi 6,28,0; crxor 6,6,6; addi 5,31,840; addi 3,13,-27800; li 4,1298; bl _s8025C0C4_1; 2:; lwz 3,0x34(27); cmplw 29,3; bgt 3f; add 0,29,28; cmplw 0,3; ble 4f; 3:; addi 6,29,0; crxor 6,6,6; addi 7,28,0; addi 5,31,920; addi 3,13,-27800; li 4,1306; bl _s8025C0C4_2; 4:; lis 4,-32730; addi 6,4,-15864; addi 3,27,0; addi 4,28,0; addi 5,30,0; bl _s8025C0C4_3; cmpwi 3,0; bne 5f; li 3,-1; b 11f; 5:; bl _s8025C0C4_4; mr 31,3; 6:; lwz 0,0xc(27); cmpwi 0,0; bne 7f; li 30,0; b 10f; 7:; cmpwi 0,-1; bne 8f; li 30,-1; b 10f; 8:; cmpwi 0,10; bne 9f; li 30,-3; b 10f; 9:; addi 3,13,-23488; bl _s8025C0C4_5; b 6b; 10:; mr 3,31; bl _s8025C0C4_6; mr 3,30; 11:; lmw 27,0x1c(1); lwz 0,0x34(1); addi 1,1,48; mtspr 8,0"
extern "C" void _s8025C0C4_0();
extern "C" void _s8025C0C4_1();
extern "C" void _s8025C0C4_2();
extern "C" void _s8025C0C4_3();
extern "C" void _s8025C0C4_4();
extern "C" void _s8025C0C4_5();
extern "C" void _s8025C0C4_6();
extern "C" void f_8025C0C4() {}
