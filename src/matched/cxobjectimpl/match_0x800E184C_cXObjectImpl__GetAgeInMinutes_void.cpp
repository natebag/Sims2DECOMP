// 0x800E184C cXObjectImpl::GetAgeInMinutes(void) (396 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 24,0x8(1); stw 0,0x2c(1); mr 29,3; lwz 11,0x4(29); addi 29,29,40; lwz 9,0x4(11); lwz 0,0x3dc(9); lha 3,0x3d8(9); mtspr 8,0; add 3,11,3; blrl; mr 30,3; li 4,5; lwz 9,0x0(30); lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,30,3; blrl; mr 28,3; li 4,21; mr 3,29; bl _s800E184C_0; lwz 9,0x0(30); li 4,0; lha 0,0x0(3); lha 3,0x30(9); lwz 9,0x34(9); subf 24,0,28; add 3,30,3; mtspr 8,9; blrl; mr 28,3; li 4,24; mr 3,29; bl _s800E184C_1; lwz 9,0x0(30); li 4,8; lha 0,0x0(3); lha 3,0x30(9); lwz 9,0x34(9); subf 31,0,28; add 3,30,3; mtspr 8,9; blrl; lwz 9,0x0(30); mr 25,3; li 4,7; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x0(30); mr 26,3; li 4,1; lha 3,0x30(9); lwz 0,0x34(9); add 3,30,3; mtspr 8,0; blrl; mr 27,3; li 4,45; mr 3,29; bl _s800E184C_2; lha 28,0x0(3); li 4,46; mr 3,29; bl _s800E184C_3; lha 30,0x0(3); li 4,47; mr 3,29; bl _s800E184C_4; lha 8,0x0(3); mr 4,26; mr 3,25; mr 5,27; mr 6,28; mr 7,30; bl _s800E184C_5; cmpwi 24,0; bge 0f; addi 24,24,60; addi 31,31,-1; 0:; cmpwi 31,0; bge 1f; addi 31,31,24; addi 3,3,-1; 1:; mulli 0,3,24; add 31,31,0; mulli 3,31,60; add 3,24,3; lwz 0,0x2c(1); mtspr 8,0; lmw 24,0x8(1); addi 1,1,40"

extern "C" void _s800E184C_0();
extern "C" void _s800E184C_1();
extern "C" void _s800E184C_2();
extern "C" void _s800E184C_3();
extern "C" void _s800E184C_4();
extern "C" void _s800E184C_5();

struct cXObjectImpl {
    void GetAgeInMinutes();
};

void cXObjectImpl::GetAgeInMinutes() {
}
