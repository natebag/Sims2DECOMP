// 0x80259CF8 SITransfer (364 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-96(1); stmw 19,0x2c(1); addi 24,3,0; lis 3,-32694; addi 23,3,-21872; rlwinm 0,24,5,0,26; addi 25,4,0; addi 26,5,0; addi 27,6,0; addi 28,7,0; addi 29,8,0; addi 31,9,0; addi 30,10,0; add 22,23,0; bl _s80259CF8_0; lwz 0,0x0(22); addi 21,3,0; cmpwi 0,-1; bne 0f; lis 3,-32700; lwz 0,-15972(3); cmpw 0,24; bne 1f; 0:; mr 3,21; bl _s80259CF8_1; li 3,0; b 6f; 1:; bl _s80259CF8_2; li 0,0; xor 5,30,0; xor 0,31,0; or. 0,5,0; bne 2f; addi 19,4,0; addi 20,3,0; b 3f; 2:; rlwinm 0,24,3,0,28; add 6,23,0; lwz 5,0x144(6); lwz 0,0x140(6); addc 19,30,5; adde 20,31,0; 3:; xoris 6,3,32768; xoris 5,20,32768; subfc 0,19,4; subfe 5,5,6; subfe 5,6,6; neg. 5,5; beq 4f; mulli 0,24,40; subfc 30,4,19; subfe 31,3,20; lis 4,-32730; add 3,23,0; addi 7,4,-25492; addi 6,30,0; addi 5,31,0; addi 3,3,128; bl _s80259CF8_3; b 5f; 4:; addi 3,24,0; addi 4,25,0; addi 5,26,0; addi 6,27,0; addi 7,28,0; addi 8,29,0; bl _s80259CF8_4; cmpwi 3,0; beq 5f; mr 3,21; bl _s80259CF8_5; li 3,1; b 6f; 5:; stw 24,0x0(22); mr 3,21; stw 25,0x4(22); stw 26,0x8(22); stw 27,0xc(22); stw 28,0x10(22); stw 29,0x14(22); stw 19,0x1c(22); stw 20,0x18(22); bl _s80259CF8_6; li 3,1; 6:; lmw 19,0x2c(1); lwz 0,0x64(1); addi 1,1,96; mtspr 8,0"
extern "C" void _s80259CF8_0();
extern "C" void _s80259CF8_1();
extern "C" void _s80259CF8_2();
extern "C" void _s80259CF8_3();
extern "C" void _s80259CF8_4();
extern "C" void _s80259CF8_5();
extern "C" void _s80259CF8_6();
extern "C" void f_80259CF8() {}
