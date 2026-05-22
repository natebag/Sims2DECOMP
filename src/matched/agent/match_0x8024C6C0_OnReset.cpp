// 0x8024C6C0 OnReset (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); cmpwi 3,0; beq 9f; lwz 0,-23688(13); cmplwi 0,0; mr 31,0; beq 0f; lwz 0,0x14(31); b 1f; 0:; li 0,0; 1:; mr 30,0; b 2f; 2:; b 3f; 3:; b 8f; 4:; mr 3,31; bl _s8024C6C0_0; cmpwi 3,0; bne 5f; mr 3,31; bl _s8024C6C0_1; 5:; cmplwi 30,0; mr 31,30; beq 6f; lwz 0,0x14(30); b 7f; 6:; li 0,0; 7:; mr 30,0; 8:; cmplwi 31,0; bne 4b; 9:; li 3,1; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8024C6C0_0();
extern "C" void _s8024C6C0_1();
extern "C" void f_8024C6C0() {}
