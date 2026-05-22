// 0x803842F8 CARDReadAsync (324 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); rlwinm. 0,6,0,23,31; stwu 1,-48(1); stw 31,0x2c(1); addi 31,5,0; stw 30,0x28(1); addi 30,4,0; stw 29,0x24(1); addi 29,3,0; stw 28,0x20(1); addi 28,7,0; bne 0f; rlwinm. 0,31,0,23,31; beq 1f; 0:; li 3,-128; b 8f; 1:; addi 3,29,0; addi 4,31,0; addi 5,6,0; addi 6,1,28; bl _s803842F8_0; cmpwi 3,0; bge 2f; b 8f; 2:; lwz 3,0x1c(1); bl _s803842F8_1; lwz 0,0x4(29); rlwinm 0,0,6,0,25; add 4,3,0; lwz 3,0x1c(1); bl _s803842F8_2; mr. 4,3; bge 3f; lwz 3,0x1c(1); bl _s803842F8_3; b 8f; 3:; addi 3,30,0; addi 4,31,0; bl _s803842F8_4; cmplwi 28,0; beq 4f; mr 0,28; b 5f; 4:; lis 3,-32712; addi 0,3,-4304; 5:; lwz 3,0x1c(1); stw 0,0xd0(3); lwz 3,0x1c(1); lwz 4,0x8(29); lwz 5,0xc(3); addi 0,5,-1; and 8,4,0; subf 3,8,5; cmpw 31,3; bge 6f; mr 3,31; 6:; lhz 0,0x10(29); lis 4,-32712; addi 31,3,0; lwz 3,0x0(29); mullw 0,5,0; addi 7,4,16840; addi 5,31,0; addi 6,30,0; add 4,8,0; bl _s803842F8_5; mr. 29,3; bge 7f; lwz 3,0x1c(1); mr 4,29; bl _s803842F8_6; 7:; mr 3,29; 8:; lwz 0,0x34(1); lwz 31,0x2c(1); lwz 30,0x28(1); lwz 29,0x24(1); lwz 28,0x20(1); addi 1,1,48; mtspr 8,0"
extern "C" void _s803842F8_0();
extern "C" void _s803842F8_1();
extern "C" void _s803842F8_2();
extern "C" void _s803842F8_3();
extern "C" void _s803842F8_4();
extern "C" void _s803842F8_5();
extern "C" void _s803842F8_6();
extern "C" void f_803842F8() {}
