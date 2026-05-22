// 0x801EC09C StaticIsSkillUpgradeObject(int) (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,6; lis 9,-32704; mtspr 9,0; addi 9,9,-14320; 0:; lwz 0,0x0(9); addi 9,9,4; cmpw 0,3; bne 1f; li 3,1; blr; 1:; bdnz 0b; li 3,0"
extern "C" int f_801EC09C() {}
