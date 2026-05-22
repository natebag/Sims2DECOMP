// 0x80109DF0 cXObjectImpl::GosubObjectTree(cXObject (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,3; mr 27,4; lwz 11,0x4(31); mr 29,5; mr 28,6; lwz 9,0x4(11); lwz 0,0x254(9); lha 3,0x250(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x4(27); lwz 30,0x0(31); lha 3,0x378(9); lwz 0,0x37c(9); add 3,27,3; mtspr 8,0; blrl; mr 4,3; mr 5,29; mr 3,30; mr 6,28; bl _s80109DF0_0; cmpwi 3,0; bne 0f; li 3,0; b 1f; 0:; lwz 9,0x0(31); lwz 10,0x0(9); lwz 11,0x18(10); lwz 0,0x4c(11); lha 3,0x48(11); mtspr 8,0; add 3,10,3; blrl; lwz 9,0x4(27); mr 30,3; lha 3,0x328(9); lwz 0,0x32c(9); add 3,27,3; mtspr 8,0; blrl; sth 3,0x4(30); li 3,1; 1:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s80109DF0_0();
extern "C" void f_80109DF0() {}
