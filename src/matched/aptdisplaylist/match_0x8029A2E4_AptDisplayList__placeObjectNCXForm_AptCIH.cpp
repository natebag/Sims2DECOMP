// 0x8029A2E4 AptDisplayList::placeObjectNCXForm(AptCIH (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-112(1); mfspr 0,8; stfd f31,0x68(1); stmw 22,0x40(1); stw 0,0x74(1); lwz 0,0x78(1); mr 31,3; mr 30,4; mr 28,5; mr 27,6; mr 25,7; mr 24,8; mr 23,9; mr 22,10; fmr f31,f1; lwz 29,0x7c(1); cmpwi 0,0; lwz 26,0x80(1); bne 0f; stw 29,0xc(1); stw 26,0x10(1); stw 0,0x14(1); stw 0,0x8(1); b 1f; 0:; mr 4,0; addi 3,1,24; bl _s8029A2E4_0; li 9,0; addi 0,1,24; stw 9,0x14(1); mr 3,31; stw 0,0x8(1); mr 4,30; stw 29,0xc(1); mr 5,28; stw 26,0x10(1); mr 6,27; mr 7,25; mr 8,24; mr 9,23; mr 10,22; fmr f1,f31; 1:; bl _s8029A2E4_1; lwz 0,0x74(1); mtspr 8,0; lmw 22,0x40(1); lfd f31,0x68(1); addi 1,1,112"

extern "C" void _s8029A2E4_0();
extern "C" void _s8029A2E4_1();

struct AptDisplayList {
    void placeObjectNCXForm_AptCIH();
};

void AptDisplayList::placeObjectNCXForm_AptCIH() {
}
