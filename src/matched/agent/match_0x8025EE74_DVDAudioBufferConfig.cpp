// 0x8025EE74 __DVDAudioBufferConfig (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); li 0,13; stwu 1,-48(1); stw 31,0x2c(1); stw 30,0x28(1); addi 30,3,0; stw 0,0x8(3); stw 4,0x10(3); stw 5,0x14(3); stw 6,0x28(3); lwz 0,-27788(13); cmpwi 0,0; beq 1f; lwz 3,0x8(30); cmplwi 3,1; beq 0f; addi 0,3,-4; cmplwi 0,1; ble 0f; cmplwi 3,14; bne 1f; 0:; lwz 3,0x18(30); lwz 4,0x14(30); bl _s8025EE74_0; 1:; bl _s8025EE74_1; li 0,2; stw 0,0xc(30); addi 31,3,0; addi 4,30,0; li 3,2; bl _s8025EE74_2; lwz 0,-23480(13); cmplwi 0,0; bne 2f; lwz 0,-23468(13); cmpwi 0,0; bne 2f; bl _s8025EE74_3; 2:; mr 3,31; bl _s8025EE74_4; lwz 0,0x34(1); lwz 31,0x2c(1); lwz 30,0x28(1); addi 1,1,48; mtspr 8,0"
extern "C" void _s8025EE74_0();
extern "C" void _s8025EE74_1();
extern "C" void _s8025EE74_2();
extern "C" void _s8025EE74_3();
extern "C" void _s8025EE74_4();
extern "C" void f_8025EE74() {}
