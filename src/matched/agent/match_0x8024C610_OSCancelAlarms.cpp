// 0x8024C610 OSCancelAlarms (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); stw 29,0x14(1); mr 29,3; cmplwi 29,0; beq 9f; bl _s8024C610_0; lwz 0,-23688(13); mr 31,3; cmplwi 0,0; mr 3,0; beq 0f; lwz 0,0x14(3); b 1f; 0:; li 0,0; 1:; mr 30,0; b 2f; 2:; b 3f; 3:; b 8f; 4:; lwz 0,0x4(3); cmplw 0,29; bne 5f; bl _s8024C610_1; 5:; cmplwi 30,0; mr 3,30; beq 6f; lwz 0,0x14(30); b 7f; 6:; li 0,0; 7:; mr 30,0; 8:; cmplwi 3,0; bne 4b; mr 3,31; bl _s8024C610_2; 9:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s8024C610_0();
extern "C" void _s8024C610_1();
extern "C" void _s8024C610_2();
extern "C" void f_8024C610() {}
