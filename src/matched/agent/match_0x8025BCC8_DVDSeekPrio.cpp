// 0x8025BCC8 DVDSeekPrio (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 7,-32730; stw 0,0x4(1); addi 6,5,0; addi 5,7,-17036; stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); addi 30,3,0; lwz 0,0x30(3); add 4,0,4; bl _s8025BCC8_0; cmpwi 3,0; bne 0f; li 3,-1; b 6f; 0:; bl _s8025BCC8_1; mr 31,3; 1:; lwz 0,0xc(30); cmpwi 0,0; bne 2f; li 30,0; b 5f; 2:; cmpwi 0,-1; bne 3f; li 30,-1; b 5f; 3:; cmpwi 0,10; bne 4f; li 30,-3; b 5f; 4:; addi 3,13,-23488; bl _s8025BCC8_2; b 1b; 5:; mr 3,31; bl _s8025BCC8_3; mr 3,30; 6:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s8025BCC8_0();
extern "C" void _s8025BCC8_1();
extern "C" void _s8025BCC8_2();
extern "C" void _s8025BCC8_3();
extern "C" void f_8025BCC8() {}
