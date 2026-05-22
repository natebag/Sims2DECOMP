// 0x8025F488 DVDInquiry (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; li 6,32; stw 0,0x4(1); li 0,14; li 5,0; stwu 1,-40(1); stw 31,0x24(1); stw 30,0x20(1); addi 30,3,0; stw 0,0x8(3); lis 3,-32730; addi 0,3,-2736; stw 4,0x18(30); addi 4,30,0; li 3,2; stw 6,0x14(30); stw 5,0x20(30); stw 0,0x28(30); bl _s8025F488_0; cmpwi 3,0; bne 0f; li 3,-1; b 6f; 0:; bl _s8025F488_1; mr 31,3; 1:; lwz 0,0xc(30); cmpwi 0,0; bne 2f; lwz 30,0x20(30); b 5f; 2:; cmpwi 0,-1; bne 3f; li 30,-1; b 5f; 3:; cmpwi 0,10; bne 4f; li 30,-3; b 5f; 4:; addi 3,13,-23488; bl _s8025F488_2; b 1b; 5:; mr 3,31; bl _s8025F488_3; mr 3,30; 6:; lwz 0,0x2c(1); lwz 31,0x24(1); lwz 30,0x20(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s8025F488_0();
extern "C" void _s8025F488_1();
extern "C" void _s8025F488_2();
extern "C" void _s8025F488_3();
extern "C" void f_8025F488() {}
