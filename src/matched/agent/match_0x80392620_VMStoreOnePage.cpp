// 0x80392620 VMStoreOnePage (296 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 0,0x24(1); stw 31,0x1c(1); stw 30,0x18(1); stw 29,0x14(1); li 29,0; stw 28,0x10(1); b 5f; 0:; lwz 3,-21872(13); addi 0,3,1; stw 0,-21872(13); bl _s80392620_0; lwz 4,-21872(13); mr 28,3; lwz 0,-21884(13); cmplw 4,0; blt 1f; stw 31,-21872(13); 1:; cmplwi 28,0; beq 6f; mr 3,28; bl _s80392620_1; cmpwi 3,0; beq 6f; mr 3,28; bl _s80392620_2; mr 29,3; bl _s80392620_3; mr 31,3; 2:; bl _s80392620_4; cmplwi 3,0; bne 2b; bl _s80392620_5; rlwinm 30,3,0,16,31; mr 3,29; li 4,4096; bl _s80392620_6; mr 3,28; bl _s80392620_7; mr 5,3; mr 4,29; li 3,0; li 6,4096; bl _s80392620_8; 3:; bl _s80392620_9; cmplwi 3,0; bne 3b; cmpwi 30,0; bne 4f; bl _s80392620_10; 4:; mr 3,31; bl _s80392620_11; mr 3,28; bl _s80392620_12; mr 3,28; li 4,0; bl _s80392620_13; li 3,1; b 7f; 5:; li 31,0; 6:; lwz 0,-21884(13); cmplw 29,0; addi 29,29,1; ble 0b; li 3,0; 7:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); lwz 28,0x10(1); mtspr 8,0; addi 1,1,32"
extern "C" void _s80392620_0();
extern "C" void _s80392620_1();
extern "C" void _s80392620_2();
extern "C" void _s80392620_3();
extern "C" void _s80392620_4();
extern "C" void _s80392620_5();
extern "C" void _s80392620_6();
extern "C" void _s80392620_7();
extern "C" void _s80392620_8();
extern "C" void _s80392620_9();
extern "C" void _s80392620_10();
extern "C" void _s80392620_11();
extern "C" void _s80392620_12();
extern "C" void _s80392620_13();
extern "C" void f_80392620() {}
