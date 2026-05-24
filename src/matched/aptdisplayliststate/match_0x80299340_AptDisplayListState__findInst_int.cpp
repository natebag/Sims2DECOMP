// 0x80299340 AptDisplayListState::findInst(int, (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 26,3; mr 29,4; lwz 9,0x0(26); mr 25,6; mr 28,7; mr. 27,5; mr 30,9; lwz 31,0x54(9); beq 5f; cmpwi 31,0; beq 5f; 0:; lwz 0,0x0(31); andis. 9,0,2048; bne 4f; lwz 3,0x0(27); lwz 4,0xc(31); lhz 5,0x2(3); lhz 0,0x2(4); cmpw 5,0; beq 1f; li 3,0; b 3f; 1:; cmpw 3,4; bne 2f; li 3,1; b 3f; 2:; addi 3,3,8; addi 4,4,8; bl _s80299340_0; subfic 0,3,0; adde 3,0,3; 3:; cmpwi 3,0; bne 8f; 4:; mr 30,31; lwz 31,0x54(30); cmpwi 31,0; bne 0b; 5:; lwz 9,0x0(26); lwz 31,0x54(9); mr 30,9; b 7f; 6:; mr 30,31; lwz 31,0x54(30); 7:; cmpwi 31,0; beq 9f; lwz 0,0x58(31); srawi 9,0,15; cmpw 9,29; blt 6b; cmpwi 31,0; beq 9f; srawi 0,0,15; cmpw 0,29; bne 9f; 8:; stw 31,0x0(28); b 10f; 9:; li 0,0; stw 0,0x0(28); 10:; stw 30,0x0(25); lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"

extern "C" void _s80299340_0();

struct AptDisplayListState {
    void findInst();
};

void AptDisplayListState::findInst() {
}
