// 0x800F2AC0 ObjectIterator::operator++(void) (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 28,0x20(1); stw 0,0x34(1); mr 28,3; lwz 11,0x4(28); cmpwi 11,0; beq 6f; lwz 9,0x4(11); li 30,0; lha 3,0x520(9); lwz 0,0x524(9); add 3,11,3; mtspr 8,0; blrl; mr 31,3; 0:; lwz 0,0x94(31); lwz 9,0x90(31); subf 0,9,0; srawi 29,0,5; cmpw 30,29; bge 2f; 1:; mr 4,30; mr 3,31; bl _s800F2AC0_0; addi 30,30,1; cmpwi 3,0; stw 3,0x4(28); bne 5f; cmpw 30,29; blt 1b; 2:; lwz 0,0x4(28); cmpwi 0,0; bne 5f; lwz 9,0x0(28); cmpwi 31,0; beq 3f; lwz 0,0x4(31); cmpw 0,9; b 4f; 3:; cmpwi 9,0; 4:; beq 5f; mr 4,31; addi 3,1,8; bl _s800F2AC0_1; lwz 9,0x18(1); lwz 0,0x4(28); addi 30,9,1; lwz 31,0x14(1); cmpwi 0,0; beq 0b; 5:; mr 3,28; 6:; lwz 0,0x34(1); mtspr 8,0; lmw 28,0x20(1); addi 1,1,48"
extern "C" void _s800F2AC0_0();
extern "C" void _s800F2AC0_1();
extern "C" void f_800F2AC0() {}
