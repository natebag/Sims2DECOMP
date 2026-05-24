// 0x800DB9A8 cXObjectImpl::DayPassed(void) (368 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s800DB9A8_0; lwz 3,0x4(30); lwz 9,0x4(3); lha 0,0x390(9); lwz 9,0x394(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 2f; cmpwi 30,0; beq 0f; lwz 9,0x4(30); li 4,3; lwz 3,0x0(9); bl _s800DB9A8_1; mr 31,3; b 1f; 0:; li 31,0; 1:; cmpwi 31,0; beq 7f; lwz 9,0x4(31); lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; cmpw 3,31; bne 7f; lwz 11,0x4(30); lwz 9,0x4(11); lwz 0,0x224(9); lha 3,0x220(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x0(3); lwz 4,0x8c(30); lha 0,0xa0(9); lwz 9,0xa4(9); add 3,3,0; mtspr 8,9; blrl; mr. 3,3; beq 7f; lwz 31,0x38(3); b 3f; 2:; lwz 31,0x88(30); 3:; lha 0,0x4a(31); cmpwi 0,0; bne 7f; lwz 3,-21496(13); li 4,41; lwz 9,0x0(3); lha 0,0x30(9); lwz 9,0x34(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 7f; addi 30,30,40; li 4,41; mr 3,30; bl _s800DB9A8_2; lha 5,0x0(3); lha 0,0x24(31); cmpw 5,0; bne 4f; lhz 0,0x46(31); cmpwi 0,0; bne 5f; 4:; lhz 0,0x48(31); 5:; subf 0,0,5; extsh 5,0; lha 3,0x4c(31); cmpw 5,3; bge 6f; mr 5,3; 6:; mr 3,30; li 4,41; bl _s800DB9A8_3; 7:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s800DB9A8_0();
extern "C" void _s800DB9A8_1();
extern "C" void _s800DB9A8_2();
extern "C" void _s800DB9A8_3();

struct cXObjectImpl {
    void DayPassed();
};

void cXObjectImpl::DayPassed() {
}
