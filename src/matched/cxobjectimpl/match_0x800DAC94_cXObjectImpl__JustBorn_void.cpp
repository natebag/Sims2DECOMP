// 0x800DAC94 cXObjectImpl::JustBorn(void) (296 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; lwz 11,0x4(29); addi 29,29,40; lwz 9,0x4(11); lwz 0,0x3dc(9); lha 3,0x3d8(9); mtspr 8,0; add 3,11,3; blrl; mr 30,3; li 4,8; lwz 9,0x0(30); lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,30,3; blrl; mr 5,3; li 4,45; mr 3,29; bl _s800DAC94_0; lwz 9,0x0(30); li 4,7; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,30,3; blrl; mr 5,3; li 4,46; mr 3,29; bl _s800DAC94_1; lwz 9,0x0(30); li 4,1; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,30,3; blrl; mr 5,3; li 4,47; mr 3,29; bl _s800DAC94_2; lwz 9,0x0(30); li 4,0; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,30,3; blrl; mr 5,3; li 4,24; mr 3,29; bl _s800DAC94_3; lwz 9,0x0(30); li 4,5; lha 3,0x30(9); lwz 0,0x34(9); add 3,30,3; mtspr 8,0; blrl; mr 5,3; li 4,21; mr 3,29; bl _s800DAC94_4; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s800DAC94_0();
extern "C" void _s800DAC94_1();
extern "C" void _s800DAC94_2();
extern "C" void _s800DAC94_3();
extern "C" void _s800DAC94_4();

struct cXObjectImpl {
    void JustBorn();
};

void cXObjectImpl::JustBorn() {
}
