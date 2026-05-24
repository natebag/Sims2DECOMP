// 0x80108EC8 cXObjectImpl::TryPassiveInfluence(StackElem (384 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,5; mr 30,3; lbz 0,0x2(31); mr 29,4; lha 5,0x0(31); extsb 4,0; li 6,0; li 7,0; addi 8,1,8; bl _s80108EC8_0; cmpwi 3,-1; bne 0f; cmpwi 4,-1; bne 0f; li 0,0; li 3,-1; li 4,-1; sth 0,0x4(29); b 5f; 0:; lwz 11,-21484(13); lha 4,0x8(1); lwz 9,0x0(11); lwz 0,0x94(9); lha 3,0x90(9); mtspr 8,0; add 3,11,3; blrl; lbz 0,0x4(31); mr 29,3; cmpwi 0,5; bne 1f; lwz 3,-21496(13); lwz 9,0x0(3); lha 0,0x198(9); lwz 9,0x19c(9); add 3,3,0; mtspr 8,9; blrl; mr 4,29; bl _s80108EC8_1; b 4f; 1:; lbz 4,0x5(31); li 0,0; addi 5,1,10; addi 6,1,12; sth 0,0xe(1); mr 3,30; extsb 4,4; bl _s80108EC8_2; lha 4,0xa(1); mr 3,30; lha 5,0xc(1); li 6,0; li 7,0; addi 8,1,14; bl _s80108EC8_3; cmpwi 3,-1; bne 2f; cmpwi 4,-1; bne 2f; li 3,-1; li 4,-1; b 5f; 2:; lha 0,0xe(1); cmpwi 0,32; ble 3f; li 0,32; sth 0,0xe(1); 3:; lwz 11,-21496(13); lwz 9,0x0(11); lha 3,0x198(9); lwz 0,0x19c(9); add 3,11,3; mtspr 8,0; blrl; lbz 8,0x6(31); mr 4,29; lbz 5,0x3(31); lbz 6,0x4(31); extsb 8,8; lbz 7,0xf(1); extsb 5,5; extsb 6,6; extsb 7,7; bl _s80108EC8_4; 4:; li 3,0; li 4,1; 5:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"

extern "C" void _s80108EC8_0();
extern "C" void _s80108EC8_1();
extern "C" void _s80108EC8_2();
extern "C" void _s80108EC8_3();
extern "C" void _s80108EC8_4();

struct cXObjectImpl {
    void TryPassiveInfluence_StackElem();
};

void cXObjectImpl::TryPassiveInfluence_StackElem() {
}
