// 0x8025F0FC DVDChangeDisk (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stw 31,0x24(1); stw 30,0x20(1); mr 30,4; stw 29,0x1c(1); addi 29,3,0; lbz 0,0x4(4); extsb. 0,0; bne 0f; lis 3,-32700; crxor 6,6,6; addi 3,3,-14360; bl _s8025F0FC_0; crxor 6,6,6; addi 3,13,-27780; li 4,2902; addi 5,13,-27768; bl _s8025F0FC_1; 0:; li 0,3; stw 0,0x8(29); lis 3,-32730; addi 0,3,-3584; stw 30,0x24(29); stw 0,0x28(29); lwz 4,-23472(13); lwz 3,0x38(4); lwz 4,0x3c(4); bl _s8025F0FC_2; li 3,2; addi 4,29,0; bl _s8025F0FC_3; cmpwi 3,0; bne 1f; li 3,-1; b 7f; 1:; bl _s8025F0FC_4; mr 31,3; 2:; lwz 0,0xc(29); cmpwi 0,0; bne 3f; li 30,0; b 6f; 3:; cmpwi 0,-1; bne 4f; li 30,-1; b 6f; 4:; cmpwi 0,10; bne 5f; li 30,-3; b 6f; 5:; addi 3,13,-23488; bl _s8025F0FC_5; b 2b; 6:; mr 3,31; bl _s8025F0FC_6; mr 3,30; 7:; lwz 0,0x2c(1); lwz 31,0x24(1); lwz 30,0x20(1); lwz 29,0x1c(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s8025F0FC_0();
extern "C" void _s8025F0FC_1();
extern "C" void _s8025F0FC_2();
extern "C" void _s8025F0FC_3();
extern "C" void _s8025F0FC_4();
extern "C" void _s8025F0FC_5();
extern "C" void _s8025F0FC_6();
extern "C" void f_8025F0FC() {}
