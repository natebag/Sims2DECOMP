// 0x803A753C _Rb_tree<unsigned (292 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,4; mr 30,6; lwz 0,0x4(29); mr 28,3; mr 31,7; cmpw 30,0; beq 0f; cmpwi 8,0; bne 2f; cmpwi 5,0; bne 0f; lwz 9,0x0(31); lwz 0,0x10(30); cmplw 9,0; bge 2f; 0:; li 3,72; bl _s803A753C_0; lwz 0,0x0(31); mr 9,3; addi 4,31,4; addi 3,9,20; mr 31,9; stw 0,0x10(9); bl _s803A753C_1; stw 31,0x8(30); lwz 9,0x4(29); cmpw 30,9; bne 1f; stw 31,0x4(30); lwz 9,0x4(29); b 3f; 1:; lwz 0,0x8(9); cmpw 30,0; bne 4f; stw 31,0x8(9); b 4f; 2:; li 3,72; bl _s803A753C_2; lwz 0,0x0(31); mr 9,3; addi 4,31,4; addi 3,9,20; stw 0,0x10(9); mr 31,9; bl _s803A753C_3; stw 31,0xc(30); lwz 9,0x4(29); lwz 0,0xc(9); cmpw 30,0; bne 4f; 3:; stw 31,0xc(9); 4:; li 0,0; stw 30,0x4(31); stw 0,0xc(31); mr 3,31; stw 0,0x8(31); lwz 4,0x4(29); addi 4,4,4; bl _s803A753C_4; lwz 9,0x8(29); mr 3,28; addi 9,9,1; stw 9,0x8(29); stw 31,0x0(28); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s803A753C_0();
extern "C" void _s803A753C_1();
extern "C" void _s803A753C_2();
extern "C" void _s803A753C_3();
extern "C" void _s803A753C_4();
extern "C" void f_803A753C() {}
