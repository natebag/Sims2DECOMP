// 0x8022CC24 EIStaticModel::DrawAsShadow(ELevelDrawData (504 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 30,4; lwz 0,0x120(31); cmpwi 0,0; beq 13f; lwz 0,0x30(31); cmpwi 0,0; beq 0f; lwz 3,0x2c(31); mtspr 8,0; blrl; b 1f; 0:; li 3,0; 1:; cmpwi 3,0; bne 13f; lwz 4,0x7c(31); cmpwi 4,0; beq 6f; lwz 0,0x10(4); cmpwi 0,0; beq 6f; lwz 0,0x0(4); andi. 9,0,2; beq 6f; lwz 0,0xb4(30); lwz 9,0x318(31); cmpw 0,4; beq 7f; stw 3,0xac(30); stw 4,0xb4(30); lwz 5,0x24(4); lwz 4,0x10(4); cmpwi 5,0; beq 2f; lwz 5,0x18(5); b 3f; 2:; li 5,0; 3:; cmpwi 9,0; beq 4f; lwz 3,0x98(30); lwz 9,0x70(3); lha 0,0xd8(9); lwz 9,0xdc(9); b 5f; 4:; lwz 3,0x98(30); lwz 9,0x70(3); lha 0,0xe8(9); lwz 9,0xec(9); 5:; add 3,3,0; mtspr 8,9; blrl; b 7f; 6:; lwz 9,0x0(31); lwz 0,0x164(9); lha 3,0x160(9); mtspr 8,0; add 3,31,3; blrl; lwz 0,0xac(30); cmpw 0,3; beq 7f; li 0,0; stw 3,0xac(30); stw 0,0xb4(30); mr 4,3; lwz 11,0x98(30); li 5,1; lwz 9,0x70(11); lha 3,0xe8(9); lwz 0,0xec(9); add 3,11,3; mtspr 8,0; blrl; 7:; lwz 29,0x11c(31); lwz 31,0x118(31); cmpwi 29,0; beq 13f; 8:; lwz 0,0x8(31); andi. 9,0,1025; bne 12f; lhz 0,0x2(31); andi. 9,0,8; bne 12f; lwz 11,0x4(31); lwz 0,0xa8(30); ori 9,11,1; cmpw 0,9; beq 11f; stw 9,0xa8(30); lwz 4,0x98(30); lwz 3,0x14(11); cmpwi 3,0; beq 9f; mr 11,3; b 10f; 9:; lwz 9,0x18(11); li 11,0; cmpwi 9,0; beq 10f; lwz 11,0x14(9); 10:; lwz 9,0xf0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 11:; lwz 3,0x98(30); lwz 4,0xc(31); lwz 9,0x70(3); lha 0,0xb8(9); lwz 9,0xbc(9); add 3,3,0; mtspr 8,9; blrl; 12:; addi 31,31,16; addic. 29,29,-1; bne 8b; 13:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

struct EIStaticModel {
    void DrawAsShadow_ELevelDrawData();
};

void EIStaticModel::DrawAsShadow_ELevelDrawData() {
}
