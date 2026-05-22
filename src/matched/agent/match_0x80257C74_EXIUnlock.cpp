// 0x80257C74 EXIUnlock (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); stw 29,0x14(1); stw 28,0x10(1); addi 28,3,0; rlwinm 4,3,6,0,25; lis 3,-32694; addi 0,3,-22064; add 31,0,4; bl _s80257C74_0; mr 30,3; lwz 0,0xc(31); rlwinm. 0,0,0,27,27; bne 0f; mr 3,30; bl _s80257C74_1; li 3,0; b 3f; 0:; lwz 0,0xc(31); rlwinm 0,0,0,28,26; stw 0,0xc(31); addi 3,28,0; addi 4,31,0; bl _s80257C74_2; lwz 3,0x24(31); cmpwi 3,0; ble 2f; lwz 29,0x2c(31); addic. 0,3,-1; stw 0,0x24(31); ble 1f; addi 3,31,40; addi 4,31,48; lwz 0,0x24(31); rlwinm 5,0,3,0,28; bl _s80257C74_3; 1:; addi 3,28,0; li 4,0; addi 12,29,0; mtspr 8,12; blrl; 2:; mr 3,30; bl _s80257C74_4; li 3,1; 3:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); lwz 28,0x10(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80257C74_0();
extern "C" void _s80257C74_1();
extern "C" void _s80257C74_2();
extern "C" void _s80257C74_3();
extern "C" void _s80257C74_4();
extern "C" void f_80257C74() {}
