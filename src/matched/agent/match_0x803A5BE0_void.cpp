// 0x803A5BE0 void (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 30,4; mr 27,5; mr 28,7; mr 29,3; mr 5,28; mr 31,30; bl _s803A5BE0_0; cmplw 30,27; bge 2f; subf 26,29,30; 0:; mr 3,31; mr 4,29; mtspr 8,28; blrl; cmpwi 3,0; beq 1f; lwz 0,0x0(29); mr 3,29; lwz 6,0x0(31); li 4,0; srawi 5,26,2; stw 0,0x0(31); mr 7,28; bl _s803A5BE0_1; 1:; addi 31,31,4; cmplw 31,27; blt 0b; 2:; mr 31,30; subf 0,29,31; srawi 0,0,2; cmpwi 0,1; ble 4f; subf 30,29,31; 3:; mr 4,31; mr 3,29; mr 5,28; addi 30,30,-4; bl _s803A5BE0_2; addi 31,31,-4; srawi 0,30,2; cmpwi 0,1; bgt 3b; 4:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s803A5BE0_0();
extern "C" void _s803A5BE0_1();
extern "C" void _s803A5BE0_2();
extern "C" void f_803A5BE0() {}
