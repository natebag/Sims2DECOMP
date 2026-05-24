// 0x8022CE1C EIStaticModel::DrawShadow(ELevelDrawData (624 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-256(1); mfspr 0,8; stfd f31,0xf8(1); stmw 30,0xf0(1); stw 0,0x104(1); mr 30,3; mr 31,4; lwz 0,0x120(30); cmpwi 0,0; beq 10f; lwz 4,0x7c(30); cmpwi 4,0; beq 4f; lwz 0,0x10(4); cmpwi 0,0; beq 4f; lwz 0,0x0(4); andi. 9,0,2; beq 4f; lwz 0,0xb4(31); lwz 9,0x318(30); cmpw 0,4; beq 5f; li 0,0; stw 4,0xb4(31); stw 0,0xac(31); lwz 5,0x24(4); lwz 4,0x10(4); cmpwi 5,0; beq 0f; lwz 5,0x18(5); b 1f; 0:; li 5,0; 1:; cmpwi 9,0; beq 2f; lwz 3,0x98(31); lwz 9,0x70(3); lha 0,0xd8(9); lwz 9,0xdc(9); b 3f; 2:; lwz 3,0x98(31); lwz 9,0x70(3); lha 0,0xe8(9); lwz 9,0xec(9); 3:; add 3,3,0; mtspr 8,9; blrl; b 5f; 4:; lwz 9,0x0(30); lwz 0,0x164(9); lha 3,0x160(9); mtspr 8,0; add 3,30,3; blrl; lwz 0,0xac(31); cmpw 0,3; beq 5f; li 0,0; stw 3,0xac(31); stw 0,0xb4(31); mr 4,3; lwz 11,0x98(31); li 5,1; lwz 9,0x70(11); lha 3,0xe8(9); lwz 0,0xec(9); add 3,11,3; mtspr 8,0; blrl; 5:; lwz 0,0x1c(30); addi 5,1,24; addi 6,1,26; cmpwi 0,0; beq 6f; lwz 3,0x28(30); li 4,0; mtspr 8,0; blrl; b 7f; 6:; sth 0,0x18(1); sth 0,0x1a(1); 7:; lha 5,0x1a(1); cmpwi 5,0; blt 10f; beq 8f; addi 4,1,8; mr 3,30; bl _s8022CE1C_0; lis 11,-32704; lis 10,-32704; lfs f0,-4568(11); addi 9,1,96; lfs f31,-4564(10); mr 4,9; stfs f0,0x60(1); addi 3,1,32; stfs f0,0x4(9); stfs f31,0x8(9); bl _s8022CE1C_1; lfs f13,0x8(1); addi 3,1,176; lfs f0,0xc(1); addi 4,1,32; lfs f12,0x10(1); fneg f13,f13; fneg f0,f0; lwz 5,-26704(13); fdivs f0,f0,f12; addi 5,5,160; fdivs f13,f13,f12; stfs f0,0x44(1); stfs f13,0x40(1); bl _s8022CE1C_2; addi 4,1,176; addi 3,1,32; bl _s8022CE1C_3; addi 4,1,32; addi 3,1,112; bl _s8022CE1C_4; lwz 11,0x98(31); fmr f1,f31; addi 4,1,32; li 5,0; lwz 9,0x70(11); lwz 0,0xfc(9); lha 3,0xf8(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stw 0,0xb0(31); b 9f; 8:; lwz 0,0xb0(31); addi 4,31,64; cmpw 0,4; beq 9f; stw 4,0xb0(31); lis 9,-32704; lwz 11,0x98(31); li 5,0; lfs f1,-4564(9); lwz 9,0x70(11); lha 3,0xf8(9); lwz 0,0xfc(9); add 3,11,3; mtspr 8,0; blrl; 9:; mr 3,30; mr 4,31; bl _s8022CE1C_5; 10:; lwz 0,0x104(1); mtspr 8,0; lmw 30,0xf0(1); lfd f31,0xf8(1); addi 1,1,256"

extern "C" void _s8022CE1C_0();
extern "C" void _s8022CE1C_1();
extern "C" void _s8022CE1C_2();
extern "C" void _s8022CE1C_3();
extern "C" void _s8022CE1C_4();
extern "C" void _s8022CE1C_5();

struct EIStaticModel {
    void DrawShadow_ELevelDrawData();
};

void EIStaticModel::DrawShadow_ELevelDrawData() {
}
