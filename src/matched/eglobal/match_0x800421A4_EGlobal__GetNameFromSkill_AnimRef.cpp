// 0x800421A4 EGlobal::GetNameFromSkill(AnimRef (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); li 31,0; lwz 3,-21508(13); stw 31,0x8(1); mr 30,4; lwz 9,0x0(3); lha 0,0x170(9); lwz 9,0x174(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 4f; lwz 3,-21508(13); addi 29,1,8; lwz 9,0x0(3); lha 0,0x170(9); lwz 9,0x174(9); add 3,3,0; mtspr 8,9; blrl; mr 4,30; addi 5,1,12; bl _s800421A4_0; mr. 3,3; beq 2f; lwz 3,0x8(3); cmpwi 3,0; beq 0f; lwz 9,0xc(1); rlwinm 9,9,2,0,29; lwzx 31,9,3; 0:; cmpwi 29,0; beq 1f; lwz 0,0xc(1); stw 0,0x0(29); 1:; li 0,1; b 3f; 2:; li 0,-1; stw 0,0x8(1); li 0,0; 3:; cmpwi 0,0; beq 4f; mr 3,31; b 5f; 4:; li 3,0; 5:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"

extern "C" void _s800421A4_0();

struct EGlobal {
    void GetNameFromSkill();
};

void EGlobal::GetNameFromSkill() {
}
