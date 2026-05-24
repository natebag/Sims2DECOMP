// 0x80030104 ERoom::KillArchitecturalObject(CTilePt (456 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 23,0x1c(1); stw 0,0x44(1); mr 24,5; li 26,0; mr 25,4; addi 30,1,8; mr 4,3; stw 26,0x0(24); mr 23,6; mr 3,30; li 5,0; mr 27,30; bl _s80030104_0; li 28,0; lwz 0,0x4(30); cmpwi 0,0; beq 6f; 0:; lwz 30,0x4(27); lwz 9,0x4(30); lha 3,0x318(9); lwz 0,0x31c(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,8; bne 5f; lwz 9,0x4(30); lha 3,0x318(9); lwz 0,0x31c(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,2; beq 5f; lwz 9,0x4(30); li 4,13; lwz 0,0x264(9); lha 3,0x260(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x4(30); mr 29,3; li 4,1; mr 31,29; lha 3,0x260(9); lwz 0,0x264(9); add 3,30,3; mtspr 8,0; blrl; subfic 4,3,8; rlwinm 4,4,31,30,31; mr 3,25; bl _s80030104_1; cmpwi 3,1; bne 1f; andi. 0,29,8; bne 4f; 1:; cmpwi 3,8; bne 2f; andi. 0,29,4; bne 4f; 2:; cmpwi 3,2; bne 3f; andi. 0,29,1; bne 4f; 3:; cmpwi 3,4; bne 5f; andi. 0,31,2; beq 5f; 4:; mr 28,30; b 6f; 5:; addi 3,1,8; bl _s80030104_2; lwz 0,0x4(27); cmpwi 0,0; bne 0b; 6:; cmpwi 28,0; beq 8f; lwz 9,0x4(28); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,28,3; blrl; lwz 0,0x1c(3); cmpwi 23,0; stw 0,0x0(24); beq 7f; lwz 9,0x4(28); lwz 29,-21484(13); lha 3,0x328(9); lwz 9,0x32c(9); lwz 30,0x0(29); add 3,28,3; mtspr 8,9; lha 0,0x58(30); addi 30,30,88; add 29,29,0; blrl; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; 7:; li 26,1; 8:; mr 3,26; lwz 0,0x44(1); mtspr 8,0; lmw 23,0x1c(1); addi 1,1,64"

extern "C" void _s80030104_0();
extern "C" void _s80030104_1();
extern "C" void _s80030104_2();

struct ERoom {
    void KillArchitecturalObject_CTilePt();
};

void ERoom::KillArchitecturalObject_CTilePt() {
}
