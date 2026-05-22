// 0x8037169C OSSendMessage (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stw 31,0x24(1); addi 31,5,0; stw 30,0x20(1); stw 29,0x1c(1); addi 29,4,0; stw 28,0x18(1); addi 28,3,0; bl _s8037169C_0; addi 30,3,0; rlwinm 31,31,0,31,31; b 2f; 0:; cmpwi 31,0; bne 1f; mr 3,30; bl _s8037169C_1; li 3,0; b 3f; 1:; mr 3,28; bl _s8037169C_2; 2:; lwz 6,0x14(28); lwz 4,0x1c(28); cmpw 6,4; ble 0b; lwz 0,0x18(28); addi 3,28,8; lwz 5,0x10(28); add 4,0,4; divw 0,4,6; mullw 0,0,6; subf 0,0,4; rlwinm 0,0,2,0,29; stwx 29,5,0; lwz 4,0x1c(28); addi 0,4,1; stw 0,0x1c(28); bl _s8037169C_3; mr 3,30; bl _s8037169C_4; li 3,1; 3:; lwz 0,0x2c(1); lwz 31,0x24(1); lwz 30,0x20(1); lwz 29,0x1c(1); lwz 28,0x18(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s8037169C_0();
extern "C" void _s8037169C_1();
extern "C" void _s8037169C_2();
extern "C" void _s8037169C_3();
extern "C" void _s8037169C_4();
extern "C" void f_8037169C() {}
