// 0x80184520 ActionMenu::GetPlayerSim(void) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 0,0xa8(3); lis 9,-32697; addi 9,9,24012; rlwinm 0,0,2,0,29; addi 9,9,188; lwzx 31,9,0; cmpwi 31,0; beq 0f; lwz 9,0x4(31); lha 3,0x308(9); lwz 0,0x30c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 0f; li 31,0; 0:; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

struct ActionMenu {
    void GetPlayerSim();
};

void ActionMenu::GetPlayerSim() {
}
