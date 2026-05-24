// 0x800475A4 EIFloor::DrawShadow(ELevelDrawData (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 31,0x104(3); lwz 30,0x98(4); cmpwi 31,0; beq 1f; 0:; lwz 9,0x70(30); lwz 4,0x4(31); lha 3,0xb8(9); lwz 0,0xbc(9); add 3,30,3; mtspr 8,0; blrl; lwz 31,0x0(31); cmpwi 31,0; bne 0b; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

struct EIFloor {
    void DrawShadow_ELevelDrawData();
};

void EIFloor::DrawShadow_ELevelDrawData() {
}
