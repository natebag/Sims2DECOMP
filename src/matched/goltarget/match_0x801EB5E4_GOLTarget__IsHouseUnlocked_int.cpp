// 0x801EB5E4 GOLTarget::IsHouseUnlocked(int, (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 3,-21476(13); li 4,1; li 31,0; lwz 9,0x0(3); lha 0,0x120(9); lwz 9,0x124(9); add 3,3,0; mtspr 8,9; blrl; mr. 11,3; beq 0f; lwz 9,0x0(11); lha 3,0x148(9); lwz 0,0x14c(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; beq 0f; li 31,1; 0:; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

struct GOLTarget {
    void IsHouseUnlocked();
};

void GOLTarget::IsHouseUnlocked() {
}
