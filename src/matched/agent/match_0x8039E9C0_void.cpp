// 0x8039E9C0 void (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 26,0x18(1); stw 0,0x34(1); mr 30,7; mr 28,4; lwz 0,0x0(30); mr 27,5; mr 29,3; stw 0,0x8(1); addi 5,1,8; mr 31,28; bl _s8039E9C0_0; cmplw 28,27; bge 2f; subf 26,29,28; 0:; lwz 4,0x0(31); mr 3,30; lwz 5,0x0(29); bl _s8039E9C0_1; cmpwi 3,0; beq 1f; lwz 9,0x0(30); mr 3,29; lwz 6,0x0(31); li 4,0; lwz 0,0x0(29); srawi 5,26,2; stw 9,0x10(1); addi 7,1,16; stw 0,0x0(31); stw 9,0x8(1); bl _s8039E9C0_2; 1:; addi 31,31,4; cmplw 31,27; blt 0b; 2:; mr 31,28; lwz 9,0x0(30); subf 0,29,31; srawi 0,0,2; stw 9,0x8(1); cmpwi 0,1; ble 4f; subf 30,29,31; 3:; lwz 0,0x8(1); mr 4,31; mr 3,29; addi 5,1,16; stw 0,0x10(1); addi 30,30,-4; bl _s8039E9C0_3; addi 31,31,-4; srawi 0,30,2; cmpwi 0,1; bgt 3b; 4:; lwz 0,0x34(1); mtspr 8,0; lmw 26,0x18(1); addi 1,1,48"
extern "C" void _s8039E9C0_0();
extern "C" void _s8039E9C0_1();
extern "C" void _s8039E9C0_2();
extern "C" void _s8039E9C0_3();
extern "C" void f_8039E9C0() {}
