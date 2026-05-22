// 0x803657EC PoolCreate (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 29,6; mr 28,5; addi 30,29,16; mr 27,3; mullw 30,30,28; addi 30,30,32; bl _s803657EC_0; li 6,0; li 7,0; mr 4,30; li 5,16; bl _s803657EC_1; mr 31,3; mr 5,30; li 4,0; bl _s803657EC_2; cmpwi 31,0; bne 0f; li 3,-1; b 3f; 0:; mr 8,31; cmpwi 28,0; addi 31,8,32; stw 29,0x0(8); ble 2f; mtspr 9,28; mr 7,31; li 6,0; 1:; lwz 0,0xc(8); addi 10,7,16; addi 11,6,16; stwx 0,6,31; stw 7,0xc(8); add 6,29,11; lwz 9,0x4(8); add 7,29,10; addi 9,9,1; stw 9,0x4(8); bdnz 1b; 2:; stw 8,0x0(27); li 3,0; 3:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s803657EC_0();
extern "C" void _s803657EC_1();
extern "C" void _s803657EC_2();
extern "C" void f_803657EC() {}
