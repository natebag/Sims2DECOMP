// 0x80371840 OSJamMessage (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stw 31,0x24(1); addi 31,3,0; stw 30,0x20(1); addi 30,5,0; stw 29,0x1c(1); stw 28,0x18(1); addi 28,4,0; bl _s80371840_0; addi 29,3,0; rlwinm 30,30,0,31,31; b 2f; 0:; cmpwi 30,0; bne 1f; mr 3,29; bl _s80371840_1; li 3,0; b 3f; 1:; mr 3,31; bl _s80371840_2; 2:; lwz 5,0x14(31); lwz 0,0x1c(31); cmpw 5,0; ble 0b; lwz 4,0x18(31); addi 0,5,-1; addi 3,31,8; add 4,4,0; divw 0,4,5; mullw 0,0,5; subf 0,0,4; stw 0,0x18(31); lwz 0,0x18(31); lwz 4,0x10(31); rlwinm 0,0,2,0,29; stwx 28,4,0; lwz 4,0x1c(31); addi 0,4,1; stw 0,0x1c(31); bl _s80371840_3; mr 3,29; bl _s80371840_4; li 3,1; 3:; lwz 0,0x2c(1); lwz 31,0x24(1); lwz 30,0x20(1); lwz 29,0x1c(1); lwz 28,0x18(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s80371840_0();
extern "C" void _s80371840_1();
extern "C" void _s80371840_2();
extern "C" void _s80371840_3();
extern "C" void _s80371840_4();
extern "C" void f_80371840() {}
