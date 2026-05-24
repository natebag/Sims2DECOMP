// 0x80187A44 HUDTarget::InitRepValues(void) (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); lis 9,-32697; addi 31,3,2216; addi 9,9,24012; li 26,0; addi 27,9,188; li 28,2; 0:; sth 26,0x0(31); sth 26,0x4(31); sth 26,0x8(31); lwz 11,0x0(27); addi 27,27,4; cmpwi 11,0; beq 1f; lwz 9,0x4(11); lwz 29,-21476(13); lha 3,0x1b0(9); lwz 9,0x1b4(9); lwz 30,0x0(29); add 3,11,3; mtspr 8,9; lha 0,0xb8(30); addi 30,30,184; add 29,29,0; blrl; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; mr. 3,3; beq 1f; bl _s80187A44_0; sth 3,0x4(31); 1:; lhz 0,0x4(31); addic. 28,28,-1; sth 0,0x0(31); addi 31,31,2; bne 0b; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"

extern "C" void _s80187A44_0();

struct HUDTarget {
    void InitRepValues();
};

void HUDTarget::InitRepValues() {
}
