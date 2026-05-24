// 0x8012BF48 cXPersonImpl::SetSimSocialIntrestFromMotiveValue(cXPerson (324 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stfd f31,0x20(1); stmw 28,0x10(1); stw 0,0x2c(1); lwz 10,0x4(3); fmr f31,f1; lwz 30,-21476(13); mr 28,4; lwz 9,0x4(10); lwz 11,0x0(30); lha 3,0x1b0(9); lwz 9,0x1b4(9); addi 29,11,184; add 3,10,3; lha 0,0xb8(11); mtspr 8,9; add 30,30,0; blrl; lwz 0,0x4(29); mr 4,3; mr 3,30; mtspr 8,0; blrl; bl _s8012BF48_0; lwz 9,0x4(28); mr 30,3; lwz 0,0x1b4(9); lha 3,0x1b0(9); mtspr 8,0; add 3,28,3; blrl; lis 9,-32706; mr 29,3; lfs f0,-12704(9); lis 11,-32706; lwz 9,0x0(30); mr 4,29; fdivs f0,f31,f0; lfs f13,-12700(11); lha 3,0x20(9); lwz 0,0x24(9); add 3,30,3; mtspr 8,0; fmuls f31,f0,f13; blrl; cmpwi 3,1; bgt 0f; lwz 9,0x0(30); mr 4,29; li 5,2; lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x0(30); mr 4,29; lha 3,0x20(9); lwz 0,0x24(9); add 3,30,3; mtspr 8,0; blrl; 0:; lwz 9,0x0(30); fmr f0,f31; fctiwz f13,f0; stfd f13,0x8(1); mr 4,29; lha 3,0x48(9); li 5,1; lwz 0,0x4c(9); lwz 6,0xc(1); add 3,30,3; mtspr 8,0; blrl; lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x10(1); lfd f31,0x20(1); addi 1,1,40"

extern "C" void _s8012BF48_0();

struct cXPersonImpl {
    void SetSimSocialIntrestFromMotiveValue_cXPerson();
};

void cXPersonImpl::SetSimSocialIntrestFromMotiveValue_cXPerson() {
}
