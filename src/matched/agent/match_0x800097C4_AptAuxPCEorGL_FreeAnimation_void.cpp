// 0x800097C4 AptAuxPCEorGL_FreeAnimation(void (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 29,0x2c(1); stw 0,0x3c(1); li 29,0; addi 30,1,8; stw 29,0x8(1); addi 8,30,8; stw 29,0x4(30); mr 31,3; stw 29,0x4(8); addi 7,31,20; lwz 9,0xc(31); lwz 0,0x10(31); lwz 11,0x8(1); lwz 10,0xc(1); stw 9,0x8(1); stw 0,0xc(1); stw 11,0xc(31); stw 10,0x10(31); stw 29,0x0(31); lwz 0,0x4(7); stw 0,0x24(1); lwz 9,0x8(30); lwz 0,0x4(8); stw 9,0x14(31); stw 0,0x4(7); lwz 0,0x20(1); lwz 3,0x4(31); lwz 9,0x24(1); stw 0,0x8(30); cmpwi 3,0; stw 9,0x4(8); beq 0f; li 4,3; bl _s800097C4_0; stw 29,0x4(31); 0:; lwz 9,0x8(1); lwz 0,0x4(30); mr 3,9; cmpw 9,0; beq 2f; 1:; addi 9,9,8; cmpw 9,0; bne 1b; 2:; cmpwi 3,0; beq 4f; lwz 0,0xc(30); subf 0,3,0; rlwinm 4,0,0,0,28; cmplwi 4,128; ble 3f; bl _s800097C4_1; b 4f; 3:; bl _s800097C4_2; 4:; lwz 0,0x3c(1); mtspr 8,0; lmw 29,0x2c(1); addi 1,1,56"
extern "C" void _s800097C4_0();
extern "C" void _s800097C4_1();
extern "C" void _s800097C4_2();
extern "C" void f_800097C4() {}
