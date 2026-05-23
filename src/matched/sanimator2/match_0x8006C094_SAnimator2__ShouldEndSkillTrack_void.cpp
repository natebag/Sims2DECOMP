// 0x8006C094 SAnimator2::ShouldEndSkillTrack(void) (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 4,48; lwz 3,0x8(31); li 30,0; addi 3,3,820; bl _s8006C094_0; cmpwi 3,0; bne 2f; lwz 0,0x61c(31); andi. 9,0,1; beq 3f; lwz 9,0x8(31); addi 11,9,820; lwz 9,0x8(11); cmpwi 9,-1; beq 0f; mulli 9,9,176; lwz 0,0x44(11); add 9,9,0; lwz 9,0x30(9); b 1f; 0:; li 9,0; 1:; andi. 0,9,32; beq 3f; lwz 3,0x4(31); li 4,0; lwz 9,0x4(3); lha 0,0xd8(9); lwz 9,0xdc(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; ble 3f; 2:; li 30,1; 3:; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s8006C094_0();

struct SAnimator2 {
    void ShouldEndSkillTrack();
};

void SAnimator2::ShouldEndSkillTrack() {
}
