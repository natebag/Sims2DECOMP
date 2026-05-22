// 0x8039EE5C void (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 29,4; mr 31,5; subf 0,3,29; srawi 0,0,2; cmpwi 0,16; ble 0f; lwz 0,0x0(31); addi 30,3,64; mr 4,30; addi 5,1,8; stw 0,0x8(1); bl _s8039EE5C_0; lwz 0,0x0(31); mr 3,30; mr 4,29; li 5,0; stw 0,0x10(1); addi 6,1,16; stw 0,0x8(1); bl _s8039EE5C_1; b 1f; 0:; lwz 0,0x0(31); mr 4,29; addi 5,1,8; stw 0,0x8(1); bl _s8039EE5C_2; 1:; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s8039EE5C_0();
extern "C" void _s8039EE5C_1();
extern "C" void _s8039EE5C_2();
extern "C" void f_8039EE5C() {}
