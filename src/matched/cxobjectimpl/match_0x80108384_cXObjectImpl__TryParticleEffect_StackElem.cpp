// 0x80108384 cXObjectImpl::TryParticleEffect(StackElem (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 29,0x0(5); lwz 30,0x4(5); mr. 31,3; beq 0f; lwz 9,0x4(31); li 4,7; lwz 3,0x0(9); bl _s80108384_0; b 1f; 0:; li 3,0; 1:; cmpwi 3,0; bne 2f; lwz 11,0x0(31); li 0,1; stw 0,-24512(13); li 9,28; sth 9,0x34(11); li 4,28; lwz 11,0x4(31); lwz 9,0x4(11); lha 3,0x110(9); lwz 0,0x114(9); add 3,11,3; mtspr 8,0; blrl; li 3,-1; li 4,-1; b 3f; 2:; lwz 11,0x3f4(3); mr 4,29; mr 5,30; lwz 9,0x0(11); lwz 0,0x10c(9); lha 3,0x108(9); mtspr 8,0; add 3,11,3; blrl; xori 3,3,1; subfic 0,3,0; adde 3,0,3; mr 4,3; li 3,0; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s80108384_0();

struct cXObjectImpl {
    void TryParticleEffect_StackElem();
};

void cXObjectImpl::TryParticleEffect_StackElem() {
}
