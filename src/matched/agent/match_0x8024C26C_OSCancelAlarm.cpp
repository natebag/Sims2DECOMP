// 0x8024C26C OSCancelAlarm (284 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); mr 30,3; stw 29,0x14(1); bl _s8024C26C_0; lwz 0,0x0(30); addi 31,3,0; cmplwi 0,0; bne 0f; mr 3,31; bl _s8024C26C_1; b 7f; 0:; lwz 29,0x14(30); cmplwi 29,0; bne 1f; lwz 0,0x10(30); addi 3,13,-23688; stw 0,0x4(3); b 2f; 1:; lwz 0,0x10(30); stw 0,0x10(29); 2:; lwz 3,0x10(30); cmplwi 3,0; beq 3f; stw 29,0x14(3); b 6f; 3:; cmplwi 29,0; stw 29,-23688(13); beq 6f; bl _s8024C26C_2; lwz 6,0xc(29); li 7,0; lwz 0,0x8(29); xoris 5,7,32768; subfc 8,4,6; subfe 0,3,0; xoris 6,0,32768; subfc 0,7,8; subfe 5,5,6; subfe 5,6,6; neg. 5,5; beq 4f; li 3,0; bl _s8024C26C_3; b 6f; 4:; lis 4,-32768; xoris 3,7,32768; subfc 0,4,8; subfe 3,3,6; subfe 3,6,6; neg. 3,3; beq 5f; mr 3,8; bl _s8024C26C_4; b 6f; 5:; addi 3,4,-1; bl _s8024C26C_5; 6:; li 0,0; stw 0,0x0(30); mr 3,31; bl _s8024C26C_6; 7:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s8024C26C_0();
extern "C" void _s8024C26C_1();
extern "C" void _s8024C26C_2();
extern "C" void _s8024C26C_3();
extern "C" void _s8024C26C_4();
extern "C" void _s8024C26C_5();
extern "C" void _s8024C26C_6();
extern "C" void f_8024C26C() {}
