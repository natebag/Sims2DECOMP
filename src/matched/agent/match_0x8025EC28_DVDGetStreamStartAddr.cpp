// 0x8025EC28 DVDGetStreamStartAddr (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); li 0,11; stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); addi 30,3,0; lis 3,-32730; stw 0,0x8(30); addi 0,3,-4920; addi 4,30,0; stw 0,0x28(30); li 3,1; bl _s8025EC28_0; cmpwi 3,0; bne 0f; li 3,-1; b 5f; 0:; bl _s8025EC28_1; mr 31,3; 1:; lwz 3,0xc(30); addi 0,3,1; cmplwi 0,1; ble 2f; cmpwi 3,10; bne 3f; 2:; lwz 30,0x20(30); b 4f; 3:; addi 3,13,-23488; bl _s8025EC28_2; b 1b; 4:; mr 3,31; bl _s8025EC28_3; mr 3,30; 5:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s8025EC28_0();
extern "C" void _s8025EC28_1();
extern "C" void _s8025EC28_2();
extern "C" void _s8025EC28_3();
extern "C" void f_8025EC28() {}
