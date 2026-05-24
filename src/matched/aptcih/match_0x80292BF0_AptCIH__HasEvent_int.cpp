// 0x80292BF0 AptCIH::HasEvent(int) (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 31,4; lwz 9,0x8(30); li 28,0; lwz 0,0x24(9); lha 3,0x20(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x4c(30); mr 29,3; lwz 0,0x1c(9); srawi 0,0,8; and. 9,0,31; bne 1f; lwz 11,0x8(29); cmpwi 11,0; beq 0f; lwz 9,0x8(11); lwz 0,0x24(9); lha 3,0x20(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0x10(3); and. 9,0,31; bne 1f; 0:; lwz 0,0x10(29); and. 9,0,31; beq 2f; 1:; li 28,1; 2:; mr 3,28; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

struct AptCIH {
    void HasEvent();
};

void AptCIH::HasEvent() {
}
