// 0x8025E14C DVDReadAbsAsyncPrio (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); li 0,1; stwu 1,-56(1); stw 31,0x34(1); addi 31,8,0; stw 30,0x30(1); stw 29,0x2c(1); addi 29,3,0; stw 0,0x8(3); li 0,0; stw 4,0x18(3); stw 5,0x14(3); stw 6,0x10(3); stw 0,0x20(3); stw 7,0x28(3); lwz 0,-27788(13); cmpwi 0,0; beq 1f; lwz 3,0x8(29); cmplwi 3,1; beq 0f; addi 0,3,-4; cmplwi 0,1; ble 0f; cmplwi 3,14; bne 1f; 0:; lwz 3,0x18(29); lwz 4,0x14(29); bl _s8025E14C_0; 1:; bl _s8025E14C_1; li 0,2; stw 0,0xc(29); addi 30,3,0; addi 3,31,0; addi 4,29,0; bl _s8025E14C_2; lwz 0,-23480(13); addi 31,3,0; cmplwi 0,0; bne 2f; lwz 0,-23468(13); cmpwi 0,0; bne 2f; bl _s8025E14C_3; 2:; mr 3,30; bl _s8025E14C_4; mr 3,31; lwz 0,0x3c(1); lwz 31,0x34(1); lwz 30,0x30(1); lwz 29,0x2c(1); addi 1,1,56; mtspr 8,0"
extern "C" void _s8025E14C_0();
extern "C" void _s8025E14C_1();
extern "C" void _s8025E14C_2();
extern "C" void _s8025E14C_3();
extern "C" void _s8025E14C_4();
extern "C" void f_8025E14C() {}
