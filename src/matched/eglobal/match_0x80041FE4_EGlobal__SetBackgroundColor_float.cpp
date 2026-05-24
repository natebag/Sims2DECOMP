// 0x80041FE4 EGlobal::SetBackgroundColor(float, (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stfd f29,0x48(1); stfd f30,0x50(1); stfd f31,0x58(1); stmw 27,0x34(1); stw 0,0x64(1); lwz 11,-26392(13); addi 4,1,8; addi 5,1,40; fmr f30,f1; lwz 9,0x0(11); fmr f31,f2; fmr f29,f3; addi 27,1,24; lwz 0,0x54(9); lha 3,0x50(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-26392(13); lwz 28,0x28(1); lwz 30,0x0(11); lha 29,0x48(30); stfs f30,0x18(1); addi 30,30,72; stfs f31,0x1c(1); add 29,11,29; stfs f29,0x20(1); lwz 9,0x0(11); lwz 0,0x64(9); lha 3,0x60(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0x4(30); mr 6,3; mr 3,29; mr 4,27; mr 5,28; mtspr 8,0; blrl; lwz 0,0x64(1); mtspr 8,0; lmw 27,0x34(1); lfd f29,0x48(1); lfd f30,0x50(1); lfd f31,0x58(1); addi 1,1,96"

struct EGlobal {
    void SetBackgroundColor();
};

void EGlobal::SetBackgroundColor() {
}
