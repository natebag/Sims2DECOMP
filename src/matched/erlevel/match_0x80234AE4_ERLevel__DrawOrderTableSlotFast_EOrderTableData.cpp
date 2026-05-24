// 0x80234AE4 ERLevel::DrawOrderTableSlotFast(EOrderTableData (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); addis 3,3,3; li 0,1; lwz 29,-24008(3); li 28,0; stw 0,-28428(13); mr. 31,4; beq 2f; mr 27,3; 0:; lwz 4,0xc(31); lwz 30,0x28(31); cmpw 28,4; beq 1f; mr 28,4; cmpwi 4,0; beq 1f; lwz 9,0x70(29); li 5,1; lha 3,0xe8(9); lwz 0,0xec(9); add 3,29,3; mtspr 8,0; blrl; 1:; lwz 0,0x14(31); mr 4,31; addi 3,27,-24160; mtspr 8,0; blrl; mr. 31,30; bne 0b; 2:; lwz 11,0x70(29); lis 9,-32704; lfs f1,-2816(9); lwz 0,0x25c(11); lha 3,0x258(11); mtspr 8,0; add 3,29,3; blrl; li 0,0; stw 0,-28428(13); lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

struct ERLevel {
    void DrawOrderTableSlotFast_EOrderTableData();
};

void ERLevel::DrawOrderTableSlotFast_EOrderTableData() {
}
