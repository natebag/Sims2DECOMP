// 0x80299100 AptPseudoDisplayList::FindInst(int, (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x0(3); b 1f; 0:; mr 9,11; 1:; lwz 11,0x8(9); cmpwi 11,0; beq 2f; lwz 0,0x10(11); mr 10,0; cmpw 0,4; blt 0b; cmpwi 11,0; beq 2f; cmpw 10,4; bne 2f; stw 11,0x0(6); b 3f; 2:; li 0,0; stw 0,0x0(6); 3:; stw 9,0x0(5)"

struct AptPseudoDisplayList {
    void FindInst();
};

void AptPseudoDisplayList::FindInst() {
}
