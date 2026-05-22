// 0x803B338C deque<int, (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 30,0x0(4); lwz 0,0x1c(31); lwz 11,0x24(31); lwz 9,0x2c(31); subf 0,11,0; srawi 0,0,2; subf 9,0,9; cmplwi 9,1; bgt 0f; li 4,1; li 5,0; bl _s803B338C_0; 0:; li 3,128; bl _s803B338C_1; lwz 11,0x1c(31); addi 8,31,16; stw 3,0x4(11); lwz 9,0x10(31); stw 30,0x0(9); lwz 11,0x1c(31); addi 0,11,4; stw 0,0xc(8); lwz 9,0x4(11); addi 10,9,128; stw 9,0x4(8); stw 10,0x8(8); lwz 0,0x14(31); stw 0,0x10(31); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s803B338C_0();
extern "C" void _s803B338C_1();
extern "C" void f_803B338C() {}
