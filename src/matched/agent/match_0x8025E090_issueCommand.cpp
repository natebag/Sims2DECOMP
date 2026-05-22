// 0x8025E090 issueCommand (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); addi 30,4,0; stw 29,0x14(1); addi 29,3,0; lwz 0,-27788(13); cmpwi 0,0; beq 1f; lwz 3,0x8(30); cmplwi 3,1; beq 0f; addi 0,3,-4; cmplwi 0,1; ble 0f; cmplwi 3,14; bne 1f; 0:; lwz 3,0x18(30); lwz 4,0x14(30); bl _s8025E090_0; 1:; bl _s8025E090_1; li 0,2; stw 0,0xc(30); addi 31,3,0; addi 3,29,0; addi 4,30,0; bl _s8025E090_2; lwz 0,-23480(13); addi 30,3,0; cmplwi 0,0; bne 2f; lwz 0,-23468(13); cmpwi 0,0; bne 2f; bl _s8025E090_3; 2:; mr 3,31; bl _s8025E090_4; mr 3,30; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s8025E090_0();
extern "C" void _s8025E090_1();
extern "C" void _s8025E090_2();
extern "C" void _s8025E090_3();
extern "C" void _s8025E090_4();
extern "C" void f_8025E090() {}
