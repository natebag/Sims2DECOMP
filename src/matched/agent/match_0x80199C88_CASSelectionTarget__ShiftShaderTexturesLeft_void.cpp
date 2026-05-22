// 0x80199C88 CASSelectionTarget::ShiftShaderTexturesLeft(void) (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 28,3; li 27,0; addi 31,28,1444; 0:; lwz 9,-16(31); lwz 0,0x14(9); cmpwi 0,0; beq 1f; mr 3,0; b 2f; 1:; lwz 9,0x18(9); li 3,0; cmpwi 9,0; beq 2f; lwz 3,0x14(9); 2:; lwz 9,0xf0(3); lwz 11,0x0(31); lha 0,0x38(9); addi 29,9,56; lwz 9,0x14(11); add 30,3,0; cmpwi 9,0; beq 3f; mr 3,9; b 4f; 3:; lwz 9,0x18(11); li 3,0; cmpwi 9,0; beq 4f; lwz 3,0x14(9); 4:; li 4,0; addi 27,27,1; bl _s80199C88_0; addi 31,31,4; lwz 0,0x4(29); mr 4,3; mr 3,30; li 5,0; mtspr 8,0; blrl; cmplwi 27,11; ble 0b; addi 4,28,1380; li 5,48; addi 3,28,1364; bl _s80199C88_1; addi 3,28,1412; li 4,0; li 5,16; bl _s80199C88_2; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s80199C88_0();
extern "C" void _s80199C88_1();
extern "C" void _s80199C88_2();
extern "C" void f_80199C88() {}
