// 0x8025F9D0 DVDCancel (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 4,-32730; stw 0,0x4(1); addi 4,4,-1412; stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); addi 30,3,0; bl _s8025F9D0_0; cmpwi 3,0; bne 0f; li 3,-1; b 4f; 0:; bl _s8025F9D0_1; mr 31,3; 1:; lwz 3,0xc(30); addi 0,3,1; cmplwi 0,1; ble 3f; cmpwi 3,10; beq 3f; cmpwi 3,3; bne 2f; lwz 3,0x8(30); addi 0,3,-4; cmplwi 0,1; ble 3f; cmplwi 3,13; beq 3f; cmplwi 3,15; beq 3f; 2:; addi 3,13,-23488; bl _s8025F9D0_2; b 1b; 3:; mr 3,31; bl _s8025F9D0_3; li 3,0; 4:; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8025F9D0_0();
extern "C" void _s8025F9D0_1();
extern "C" void _s8025F9D0_2();
extern "C" void _s8025F9D0_3();
extern "C" void f_8025F9D0() {}
