// 0x800CB2D0 Neighbor::FindActiveSlotIndex(WantFear::Bookmark (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x4(4); li 9,1; cmpwi 0,0; bne 0f; li 9,0; 0:; cmpwi 9,0; bne 2f; lha 3,-21222(13); blr; 1:; mr 3,9; blr; 2:; li 0,7; addi 3,3,408; mtspr 9,0; li 9,0; 3:; lwz 0,0x0(3); addi 3,3,4; cmpw 0,4; beq 1b; addi 9,9,1; bdnz 3b; lha 3,-21222(13)"
extern "C" int f_800CB2D0() {}
