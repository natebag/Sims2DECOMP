// 0x800DCFB8 cXObjectImpl::HierSetSite(HierarchySite (348 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,4; mr 29,3; lwz 0,0x0(31); cmpwi 0,0; bne 0f; bl _s800DCFB8_0; 0:; lwz 5,0x14(31); addi 3,1,8; addi 4,31,4; bl _s800DCFB8_1; lwz 9,0xc(31); cmpwi 9,0; bne 1f; lwz 0,0x0(31); cmpwi 0,0; beq 2f; lwz 11,-21484(13); addi 4,1,8; addi 30,29,40; lwz 9,0x0(11); lwz 0,0x254(9); lha 3,0x250(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-21484(13); addi 4,1,8; lha 5,0x64(29); lwz 9,0x0(11); lwz 0,0x25c(9); lha 3,0x258(9); mtspr 8,0; add 3,11,3; blrl; li 4,14; li 5,-1; mr 3,30; bl _s800DCFB8_2; li 4,26; mr 3,30; li 5,0; bl _s800DCFB8_3; lwz 11,0x4(29); lwz 4,0x14(31); lwz 9,0x4(11); lha 3,0x1d8(9); lwz 0,0x1dc(9); add 3,11,3; mtspr 8,0; blrl; b 2f; 1:; lwz 5,0x10(31); addi 30,29,40; lwz 9,0x90(9); li 4,14; rlwinm 0,5,5,0,26; lhz 11,0x64(29); add 9,9,0; extsh 5,5; sth 11,0x4(9); mr 3,30; bl _s800DCFB8_4; lwz 9,0xc(31); li 4,26; mr 3,30; lha 5,0x64(9); bl _s800DCFB8_5; lwz 11,0x4(29); lwz 4,0x14(31); lwz 9,0x4(11); lha 3,0x1d8(9); lwz 0,0x1dc(9); add 3,11,3; mtspr 8,0; blrl; 2:; addi 3,1,8; li 4,2; bl _s800DCFB8_6; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"

extern "C" void _s800DCFB8_0();
extern "C" void _s800DCFB8_1();
extern "C" void _s800DCFB8_2();
extern "C" void _s800DCFB8_3();
extern "C" void _s800DCFB8_4();
extern "C" void _s800DCFB8_5();
extern "C" void _s800DCFB8_6();

struct cXObjectImpl {
    void HierSetSite_HierarchySite();
};

void cXObjectImpl::HierSetSite_HierarchySite() {
}
