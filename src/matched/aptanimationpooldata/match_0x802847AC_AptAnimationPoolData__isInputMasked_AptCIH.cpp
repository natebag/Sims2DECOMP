// 0x802847AC AptAnimationPoolData::isInputMasked(AptCIH (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x94(3); cmpwi 0,0; bne 1f; 0:; li 3,0; blr; 1:; mr. 9,4; beq 3f; 2:; cmpw 9,0; beq 0b; lwz 9,0x48(9); cmpwi 9,0; bne 2b; 3:; li 3,1"

struct AptAnimationPoolData {
    void isInputMasked_AptCIH();
};

void AptAnimationPoolData::isInputMasked_AptCIH() {
}
