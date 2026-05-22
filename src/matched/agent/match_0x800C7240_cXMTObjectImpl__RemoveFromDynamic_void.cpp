// 0x800C7240 cXMTObjectImpl::RemoveFromDynamic(void) (292 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 11,0x4(30); lwz 9,0x4(11); lwz 0,0x44(9); lha 3,0x40(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x4(30); lwz 9,0x4(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; mr. 11,3; beq 0f; lwz 9,0x4(11); lha 3,0x58(9); lwz 0,0x5c(9); add 3,11,3; mtspr 8,0; blrl; mr 31,3; b 1f; 0:; li 31,0; 1:; cmpw 31,30; bne 3f; lwz 3,0x4(30); lwz 9,0x4(3); lha 0,0x18(9); lwz 9,0x1c(9); add 3,3,0; mtspr 8,9; blrl; mr. 11,3; beq 2f; lwz 9,0x4(11); lha 3,0x58(9); lwz 0,0x5c(9); add 3,11,3; mtspr 8,0; blrl; mr 31,3; b 3f; 2:; li 31,0; 3:; mr 3,30; bl _s800C7240_0; cmpwi 31,0; beq 4f; mr 3,31; bl _s800C7240_1; 4:; lwz 9,0x0(30); lwz 10,0x4(9); lwz 11,0x4(10); lha 3,0x1a8(11); lwz 0,0x1ac(11); add 3,10,3; mtspr 8,0; blrl; cmpwi 3,0; beq 5f; mr 3,30; bl _s800C7240_2; 5:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800C7240_0();
extern "C" void _s800C7240_1();
extern "C" void _s800C7240_2();
extern "C" void f_800C7240() {}
