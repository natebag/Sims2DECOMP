// 0x80325AD8 EResourceManager::CalcPath(void) (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 29,0x24(1); stw 0,0x34(1); mr 29,3; addi 31,1,8; addi 30,29,68; lwz 4,0x40(29); mr 3,30; bl _s80325AD8_0; mr 3,30; bl _s80325AD8_1; cmpwi 3,8; ble 0f; mr 3,31; li 5,8; mr 4,30; bl _s80325AD8_2; lwz 4,0x8(1); mr 3,30; bl _s80325AD8_3; lwz 4,0x8(1); mr 3,31; bl _s80325AD8_4; 0:; mr 3,31; bl _s80325AD8_5; lis 4,-32702; mr 3,31; addi 4,4,4056; bl _s80325AD8_6; lwz 4,0x8(1); addi 3,1,24; lwz 5,0x44(29); bl _s80325AD8_7; lwz 4,0x18(1); lis 5,-32702; addi 5,5,4064; addi 3,1,16; bl _s80325AD8_8; lwz 4,0x10(1); mr 3,30; bl _s80325AD8_9; lwz 4,0x10(1); addi 3,1,16; bl _s80325AD8_10; lwz 4,0x18(1); addi 3,1,24; bl _s80325AD8_11; mr 3,30; bl _s80325AD8_12; lwz 4,0x8(1); mr 3,31; bl _s80325AD8_13; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x24(1); addi 1,1,48"
extern "C" void _s80325AD8_0();
extern "C" void _s80325AD8_1();
extern "C" void _s80325AD8_2();
extern "C" void _s80325AD8_3();
extern "C" void _s80325AD8_4();
extern "C" void _s80325AD8_5();
extern "C" void _s80325AD8_6();
extern "C" void _s80325AD8_7();
extern "C" void _s80325AD8_8();
extern "C" void _s80325AD8_9();
extern "C" void _s80325AD8_10();
extern "C" void _s80325AD8_11();
extern "C" void _s80325AD8_12();
extern "C" void _s80325AD8_13();
extern "C" void f_80325AD8() {}
