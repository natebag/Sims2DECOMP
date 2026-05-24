// 0x8015325C XRoute::IsPersonSittingOnChairGoal(cXPerson (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,3; mr 28,4; lwz 30,0x0(29); lwz 0,0x4(29); cmpw 30,0; beq 2f; 0:; lha 4,0xc(30); cmpwi 4,0; beq 1f; lwz 3,0x4c(29); lwz 9,0x4(3); lha 0,0x488(9); lwz 9,0x48c(9); add 3,3,0; mtspr 8,9; blrl; mr. 31,3; beq 1f; lwz 9,0x4(31); lha 3,0x480(9); lwz 0,0x484(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 1f; lwz 3,0x0(28); lwz 9,0x4(3); lha 0,0x2d0(9); lwz 9,0x2d4(9); add 3,3,0; mtspr 8,9; blrl; cmpw 3,31; bne 1f; li 3,1; b 3f; 1:; lwz 0,0x4(29); addi 30,30,16; cmpw 30,0; bne 0b; 2:; li 3,0; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

struct XRoute {
    void IsPersonSittingOnChairGoal_cXPerson();
};

void XRoute::IsPersonSittingOnChairGoal_cXPerson() {
}
