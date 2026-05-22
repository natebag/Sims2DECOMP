// 0x80199D70 CASSelectionTarget::ShiftShaderTexturesRight(void) (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 28,3; li 27,15; addi 30,28,1472; 0:; lwz 9,0x10(30); lwz 0,0x14(9); cmpwi 0,0; beq 1f; mr 3,0; b 2f; 1:; lwz 9,0x18(9); li 3,0; cmpwi 9,0; beq 2f; lwz 3,0x14(9); 2:; lwz 9,0xf0(3); lwz 11,0x0(30); lha 0,0x38(9); addi 29,9,56; lwz 9,0x14(11); add 31,3,0; cmpwi 9,0; beq 3f; mr 3,9; b 4f; 3:; lwz 9,0x18(11); li 3,0; cmpwi 9,0; beq 4f; lwz 3,0x14(9); 4:; li 4,0; addi 27,27,-1; bl _s80199D70_0; addi 30,30,-4; lwz 0,0x4(29); mr 4,3; mr 3,31; li 5,0; mtspr 8,0; blrl; cmplwi 27,3; bgt 0b; addi 30,28,1364; li 5,48; mr 4,30; addi 3,28,1380; bl _s80199D70_1; mr 3,30; li 4,0; li 5,16; bl _s80199D70_2; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s80199D70_0();
extern "C" void _s80199D70_1();
extern "C" void _s80199D70_2();
extern "C" void f_80199D70() {}
