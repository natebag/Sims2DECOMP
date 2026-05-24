// 0x8022E8D8 EIStaticSubModel::DrawAsShadow(ELevelDrawData (276 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 30,4; lwz 3,0xa0(31); bl _s8022E8D8_0; lwz 0,0xac(30); cmpw 0,3; beq 0f; li 0,0; stw 3,0xac(30); stw 0,0xb4(30); mr 4,3; lwz 11,0x98(30); li 5,1; lwz 9,0x70(11); lha 3,0xe8(9); lwz 0,0xec(9); add 3,11,3; mtspr 8,0; blrl; 0:; lwz 29,0x9c(31); lwz 31,0x98(31); cmpwi 29,0; beq 6f; 1:; lwz 0,0x8(31); andi. 9,0,1025; bne 5f; lwz 11,0x4(31); lwz 0,0xa8(30); ori 9,11,1; cmpw 0,9; beq 4f; stw 9,0xa8(30); lwz 4,0x98(30); lwz 3,0x14(11); cmpwi 3,0; beq 2f; mr 11,3; b 3f; 2:; lwz 9,0x18(11); li 11,0; cmpwi 9,0; beq 3f; lwz 11,0x14(9); 3:; lwz 9,0xf0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 4:; lwz 3,0x98(30); lwz 4,0xc(31); lwz 9,0x70(3); lha 0,0xb8(9); lwz 9,0xbc(9); add 3,3,0; mtspr 8,9; blrl; 5:; addi 31,31,16; addic. 29,29,-1; bne 1b; 6:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s8022E8D8_0();

struct EIStaticSubModel {
    void DrawAsShadow_ELevelDrawData();
};

void EIStaticSubModel::DrawAsShadow_ELevelDrawData() {
}
