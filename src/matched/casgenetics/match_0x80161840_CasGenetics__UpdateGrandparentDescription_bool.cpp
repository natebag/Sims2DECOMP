// 0x80161840 CasGenetics::UpdateGrandparentDescription(bool, (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmplwi 5,25; ble 1f; 0:; li 3,0; blr; 1:; cmpwi 4,0; li 9,0; beq 2f; li 9,1; 2:; rlwinm 9,9,4,0,27; lwzx 11,9,3; add 9,9,3; lwz 0,0x4(9); subf 0,11,0; srawi 0,0,2; cmplw 5,0; bge 0b; rlwinm 9,5,2,0,29; lwzx 5,11,9; cmpwi 5,0; beq 0b; lwz 5,0x0(5); cmpwi 5,0; beq 0b; li 9,288; 3:; lwz 0,0x0(6); addic. 9,9,-24; stw 0,0x0(5); lwz 0,0x4(6); stw 0,0x4(5); lwz 0,0x8(6); stw 0,0x8(5); lwz 0,0xc(6); stw 0,0xc(5); lwz 0,0x10(6); stw 0,0x10(5); lwz 0,0x14(6); addi 6,6,24; stw 0,0x14(5); addi 5,5,24; bne 3b; lwz 0,0x0(6); li 3,1; stw 0,0x0(5)"

struct CasGenetics {
    void UpdateGrandparentDescription();
};

void CasGenetics::UpdateGrandparentDescription() {
}
