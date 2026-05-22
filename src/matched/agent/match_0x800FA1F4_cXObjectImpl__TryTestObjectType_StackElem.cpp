// 0x800FA1F4 cXObjectImpl::TryTestObjectType(StackElem (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 9,5; mr 31,3; lha 5,0x4(9); lbz 4,0x6(9); li 6,0; lwz 30,0x0(9); li 7,0; addi 8,1,8; bl _s800FA1F4_0; cmpwi 3,-1; bne 0f; cmpwi 4,-1; beq 1f; 0:; lwz 3,0x4(31); lha 4,0x8(1); lwz 9,0x4(3); lha 0,0x488(9); lwz 9,0x48c(9); add 3,3,0; mtspr 8,9; blrl; mr. 11,3; bne 2f; lwz 11,0x0(31); li 0,1; stw 0,-24512(13); li 9,23; sth 9,0x34(11); li 4,23; lwz 11,0x4(31); lwz 9,0x4(11); lha 3,0x110(9); lwz 0,0x114(9); add 3,11,3; mtspr 8,0; blrl; 1:; li 3,-1; li 4,-1; b 5f; 2:; lwz 9,0x4(11); lha 3,0x368(9); lwz 0,0x36c(9); add 3,11,3; mtspr 8,0; blrl; mr. 31,3; beq 4f; mr 3,31; bl _s800FA1F4_1; cmpw 3,30; bne 3f; li 3,0; li 4,1; b 5f; 3:; mr 3,31; bl _s800FA1F4_2; bl _s800FA1F4_3; cmpw 3,30; li 3,0; li 4,1; beq 5f; 4:; li 3,0; li 4,0; 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s800FA1F4_0();
extern "C" void _s800FA1F4_1();
extern "C" void _s800FA1F4_2();
extern "C" void _s800FA1F4_3();
extern "C" void f_800FA1F4() {}
