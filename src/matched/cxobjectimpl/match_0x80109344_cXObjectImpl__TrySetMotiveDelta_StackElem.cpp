// 0x80109344 cXObjectImpl::TrySetMotiveDelta(StackElem (584 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stfd f31,0x28(1); stmw 28,0x18(1); stw 0,0x34(1); mr 30,5; mr 31,3; lbz 9,0x3(30); mr 28,4; li 11,1; rlwinm 0,9,0,29,30; cmpwi 0,0; bne 0f; li 11,0; 0:; cmpwi 11,0; beq 7f; andi. 0,9,1; beq 3f; rlwinm 0,9,0,24,31; li 30,0; andi. 9,0,2; beq 1f; lwz 30,0x4(31); b 2f; 1:; andi. 9,0,4; beq 2f; lwz 3,-21484(13); lha 4,0x4(28); lwz 9,0x0(3); lha 0,0x90(9); lwz 9,0x94(9); add 3,3,0; mtspr 8,9; blrl; mr 30,3; 2:; lwz 3,-21496(13); lwz 9,0x0(3); lha 0,0x198(9); lwz 9,0x19c(9); add 3,3,0; mtspr 8,9; blrl; mr 4,30; bl _s80109344_0; b 11f; 3:; lbz 0,0x2(30); cmpwi 0,4; blt 4f; cmpwi 0,9; ble 5f; cmpwi 0,15; bgt 4f; cmpwi 0,14; bge 5f; 4:; lwz 11,0x0(31); li 0,1; stw 0,-24512(13); li 9,26; sth 9,0x34(11); li 4,26; lwz 11,0x4(31); lwz 9,0x4(11); lha 3,0x110(9); lwz 0,0x114(9); add 3,11,3; mtspr 8,0; blrl; b 7f; 5:; lbz 4,0x0(30); mr 3,31; lha 5,0x4(30); li 6,0; li 7,0; addi 8,1,8; bl _s80109344_1; cmpwi 3,-1; bne 6f; cmpwi 4,-1; beq 7f; 6:; lbz 4,0x1(30); mr 3,31; lha 5,0x6(30); li 6,0; li 7,0; addi 8,1,10; bl _s80109344_2; cmpwi 3,-1; bne 8f; cmpwi 4,-1; bne 8f; 7:; li 3,-1; li 4,-1; b 12f; 8:; lha 0,0x8(1); lis 8,17200; lis 9,-32706; xoris 0,0,32768; lfd f13,-15880(9); stw 0,0x14(1); lis 9,-32706; lfs f11,-15872(9); lis 10,-32706; stw 8,0x10(1); li 29,0; lfs f12,-15868(10); lfd f0,0x10(1); lbz 0,0x3(30); fsub f0,f0,f13; frsp f0,f0; andi. 9,0,2; fdivs f0,f0,f11; fdivs f31,f0,f12; beq 9f; lwz 29,0x4(31); b 10f; 9:; andi. 9,0,4; beq 10f; lwz 3,-21484(13); lha 4,0x4(28); lwz 9,0x0(3); lha 0,0x90(9); lwz 9,0x94(9); add 3,3,0; mtspr 8,9; blrl; mr 29,3; 10:; lwz 3,-21496(13); lwz 9,0x0(3); lha 0,0x198(9); lwz 9,0x19c(9); add 3,3,0; mtspr 8,9; blrl; lbz 5,0x2(30); mr 4,29; lha 6,0xa(1); fmr f1,f31; bl _s80109344_3; 11:; li 3,0; li 4,1; 12:; lwz 0,0x34(1); mtspr 8,0; lmw 28,0x18(1); lfd f31,0x28(1); addi 1,1,48"

extern "C" void _s80109344_0();
extern "C" void _s80109344_1();
extern "C" void _s80109344_2();
extern "C" void _s80109344_3();

struct cXObjectImpl {
    void TrySetMotiveDelta_StackElem();
};

void cXObjectImpl::TrySetMotiveDelta_StackElem() {
}
