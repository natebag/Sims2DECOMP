// 0x8021C644 XObjLang::GetConstantsDataField(short, (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_8021C780" lines="0:; lwz 11,0x0(31); lwz 3,0x4(11); lwz 9,0x4(3); lha 0,0x2b0(9); lwz 9,0x2b4(9); add 3,3,0; mtspr 8,9; blrl; addic. 29,3,-1; blt 3f; 1:; lwz 11,0x0(31); mr 4,29; lwz 10,0x4(11); lwz 9,0x4(10); lha 3,0x2c0(9); lwz 0,0x2c4(9); add 3,10,3; mtspr 8,0; blrl; mr. 30,3; beq 2f; lwz 9,0x4(30); lha 3,0x390(9); lwz 0,0x394(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,0; bne 2f; lwz 9,0x4(30); li 4,1; lha 3,0x120(9); lwz 0,0x124(9); add 3,30,3; mtspr 8,0; blrl; 2:; addic. 29,29,-1; bge 1b; 3:; lwz 31,0x8(31); cmpwi 31,0; bne 0b"
extern "C" void f_8021C780();
extern "C" void f_8021C644() {}
