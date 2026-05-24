// 0x80292228 AptCIH::FindAndSetEvents(void) (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 24,0x8(1); stw 0,0x2c(1); mr 27,3; lis 28,2; lwz 9,0x8(27); lis 29,2; li 26,0; ori 28,28,455; lha 3,0x20(9); ori 29,29,192; lwz 0,0x24(9); add 3,27,3; mtspr 8,0; blrl; lis 9,-32700; lis 11,-32694; addi 31,9,-10248; mr 30,3; addi 24,11,-11332; addi 25,31,40; 0:; lwz 9,0x0(31); lwz 0,0x10(30); and. 11,0,9; bne 1f; and. 0,9,28; beq 1f; lwz 4,0x4(31); mr 3,27; li 5,0; rlwinm 4,4,2,0,29; add 4,4,24; bl _s80292228_0; cmpwi 3,0; beq 1f; lwz 0,0x0(31); lwz 9,0x10(30); or 9,9,0; stw 9,0x10(30); lwz 0,0x0(31); and. 9,0,29; beq 1f; li 26,1; 1:; addi 31,31,8; cmpw 31,25; ble 0b; mr 3,26; lwz 0,0x2c(1); mtspr 8,0; lmw 24,0x8(1); addi 1,1,40"

extern "C" void _s80292228_0();

struct AptCIH {
    void FindAndSetEvents();
};

void AptCIH::FindAndSetEvents() {
}
