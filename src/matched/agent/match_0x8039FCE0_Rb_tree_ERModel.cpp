// 0x8039FCE0 _Rb_tree<ERModel (324 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 28,4; mr 29,6; lwz 0,0x4(28); mr 27,3; mr 30,7; cmpw 29,0; beq 0f; cmpwi 8,0; bne 2f; cmpwi 5,0; bne 0f; lwz 9,0x0(30); lwz 0,0x10(29); cmplw 9,0; bge 2f; 0:; li 3,32; bl _s8039FCE0_0; lwz 0,0x0(30); addi 10,30,4; addi 8,3,20; mr 31,3; stw 0,0x10(3); lwz 0,0x4(30); lwz 9,0x8(10); lwz 11,0x4(10); stw 0,0x14(3); stw 9,0x8(8); stw 11,0x4(8); stw 31,0x8(29); lwz 9,0x4(28); cmpw 29,9; bne 1f; stw 31,0x4(29); lwz 9,0x4(28); b 3f; 1:; lwz 0,0x8(9); cmpw 29,0; bne 4f; stw 31,0x8(9); b 4f; 2:; li 3,32; bl _s8039FCE0_1; lwz 0,0x0(30); addi 10,30,4; addi 8,3,20; mr 31,3; stw 0,0x10(3); lwz 0,0x4(30); lwz 9,0x8(10); lwz 11,0x4(10); stw 0,0x14(3); stw 9,0x8(8); stw 11,0x4(8); stw 31,0xc(29); lwz 9,0x4(28); lwz 0,0xc(9); cmpw 29,0; bne 4f; 3:; stw 31,0xc(9); 4:; li 0,0; stw 29,0x4(31); stw 0,0xc(31); mr 3,31; stw 0,0x8(31); lwz 4,0x4(28); addi 4,4,4; bl _s8039FCE0_2; lwz 9,0x8(28); mr 3,27; addi 9,9,1; stw 9,0x8(28); stw 31,0x0(27); lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8039FCE0_0();
extern "C" void _s8039FCE0_1();
extern "C" void _s8039FCE0_2();
extern "C" void f_8039FCE0() {}
