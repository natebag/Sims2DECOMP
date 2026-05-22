// 0x8025ECF0 DVDGetStreamLengthAsync (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); li 0,12; stwu 1,-32(1); stw 31,0x1c(1); addi 31,3,0; stw 30,0x18(1); stw 0,0x8(3); stw 4,0x28(3); lwz 0,-27788(13); cmpwi 0,0; beq 1f; lwz 3,0x8(31); cmplwi 3,1; beq 0f; addi 0,3,-4; cmplwi 0,1; ble 0f; cmplwi 3,14; bne 1f; 0:; lwz 3,0x18(31); lwz 4,0x14(31); bl _s8025ECF0_0; 1:; bl _s8025ECF0_1; li 0,2; stw 0,0xc(31); addi 30,3,0; addi 4,31,0; li 3,1; bl _s8025ECF0_2; lwz 0,-23480(13); addi 31,3,0; cmplwi 0,0; bne 2f; lwz 0,-23468(13); cmpwi 0,0; bne 2f; bl _s8025ECF0_3; 2:; mr 3,30; bl _s8025ECF0_4; mr 3,31; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s8025ECF0_0();
extern "C" void _s8025ECF0_1();
extern "C" void _s8025ECF0_2();
extern "C" void _s8025ECF0_3();
extern "C" void _s8025ECF0_4();
extern "C" void f_8025ECF0() {}
