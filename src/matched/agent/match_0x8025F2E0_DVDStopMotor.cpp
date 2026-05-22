// 0x8025F2E0 DVDStopMotor (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); li 0,16; stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); addi 30,3,0; lis 3,-32730; stw 0,0x8(30); addi 0,3,-3180; addi 4,30,0; stw 0,0x28(30); li 3,2; bl _s8025F2E0_0; cmpwi 3,0; bne 0f; li 3,-1; b 6f; 0:; bl _s8025F2E0_1; mr 31,3; 1:; lwz 0,0xc(30); cmpwi 0,0; bne 2f; li 30,0; b 5f; 2:; cmpwi 0,-1; bne 3f; li 30,-1; b 5f; 3:; cmpwi 0,10; bne 4f; li 30,-3; b 5f; 4:; addi 3,13,-23488; bl _s8025F2E0_2; b 1b; 5:; mr 3,31; bl _s8025F2E0_3; mr 3,30; 6:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s8025F2E0_0();
extern "C" void _s8025F2E0_1();
extern "C" void _s8025F2E0_2();
extern "C" void _s8025F2E0_3();
extern "C" void f_8025F2E0() {}
