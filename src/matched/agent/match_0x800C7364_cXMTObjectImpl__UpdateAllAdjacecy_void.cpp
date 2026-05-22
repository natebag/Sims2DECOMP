// 0x800C7364 cXMTObjectImpl::UpdateAllAdjacecy(void) (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 9,0x0(31); lwz 10,0x4(9); lwz 11,0x4(10); lha 3,0x1a8(11); lwz 0,0x1ac(11); add 3,10,3; mtspr 8,0; blrl; cmpwi 3,0; beq 4f; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x10(9); lwz 9,0x14(9); add 3,3,0; mtspr 8,9; blrl; mr. 11,3; bne 1f; b 2f; 0:; mr 3,31; bl _s800C7364_0; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x18(9); lwz 9,0x1c(9); add 3,3,0; mtspr 8,9; blrl; mr. 11,3; beq 2f; 1:; lwz 9,0x4(11); lha 3,0x58(9); lwz 0,0x5c(9); add 3,11,3; mtspr 8,0; blrl; mr 31,3; b 3f; 2:; li 31,0; 3:; cmpwi 31,0; bne 0b; 4:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s800C7364_0();
extern "C" void f_800C7364() {}
