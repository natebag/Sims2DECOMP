// 0x80197DF0 CASGeneticsTarget::SetGrandparentIndex(unsigned (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x94(3); cmpwi 9,0; bne 1f; 0:; li 3,0; blr; 1:; lwz 0,0x300(3); mr 11,9; srw 0,0,4; andi. 9,0,1; bne 2f; addi 11,11,16; 2:; lwz 9,0x0(11); lwz 0,0x4(11); subf 0,9,0; srawi. 9,0,2; beq 0b; cmpwi 5,0; bge 3f; addi 5,9,-1; b 4f; 3:; cmplw 5,9; blt 4f; li 5,0; 4:; addi 9,3,156; rlwinm 0,4,2,0,29; stwx 5,9,0; li 3,1"

struct CASGeneticsTarget {
    void SetGrandparentIndex();
};

void CASGeneticsTarget::SetGrandparentIndex() {
}
