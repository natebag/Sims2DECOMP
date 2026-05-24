// 0x8022C18C EIStaticModel::RegisterFloor(void) (532 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 26,0x40(1); stw 0,0x5c(1); mr 29,3; lwz 9,0x120(29); cmpwi 9,0; beq 13f; lwz 28,0x40(9); cmpwi 28,0; li 30,0; beq 0f; lwz 30,0x3c(9); 0:; lis 11,-32704; li 0,0; lfs f0,-4600(11); addi 9,1,8; stw 0,0x8(1); lis 11,-32733; stw 0,0x4(9); addi 11,11,-12148; stw 0,0x8(9); addi 10,29,296; stw 0,0xc(9); stw 0,0x10(9); stw 0,0x14(9); stw 0,0x18(9); stw 0,0x1c(9); stw 0,0x20(9); stw 0,0x24(9); stw 0,0x34(9); stfs f0,0x30(9); stw 0,0x28(9); stfs f0,0x2c(9); stw 0,0x8(1); lwz 8,0x7c(29); stw 0,0x34(9); stw 0,0x4(9); cmpwi 8,0; stw 0,0x8(9); stw 0,0xc(9); stw 0,0x10(9); stw 0,0x14(9); stw 0,0x18(9); stw 0,0x1c(9); stw 0,0x20(9); stw 0,0x24(9); stw 11,0x1c(1); stw 10,0x18(1); stw 29,0x2c(1); beq 3f; lwz 9,0x24(8); cmpwi 9,0; li 0,0; beq 1f; lwz 0,0x18(9); 1:; cmpwi 0,0; beq 3f; lwz 9,0x120(29); li 11,0; lwz 0,0x8c(9); cmpwi 0,0; beq 2f; li 11,1; 2:; lwz 0,0x7c(29); or 0,0,11; stw 0,0x14(1); b 4f; 3:; lwz 9,0x0(29); lwz 0,0x164(9); lha 3,0x160(9); mtspr 8,0; add 3,29,3; blrl; li 0,0; stw 3,0x14(1); 4:; stw 0,0x24(1); cmpwi 28,0; beq 13f; 5:; lwz 0,0x4(30); cmpwi 0,0; li 31,0; beq 6f; lwz 31,0x0(30); 6:; addi 28,28,-1; addi 27,30,24; cmpwi 0,0; ble 12f; mr 30,0; lis 26,-32692; 7:; lwz 0,0x8(31); cmpwi 0,0; bne 8f; lwz 4,0xc(31); addi 3,26,-17444; li 5,0; li 6,0; bl _s8022C18C_0; stw 3,0x8(31); 8:; lwz 9,0x8(31); lwz 0,0x14(9); cmpwi 0,0; beq 9f; mr 11,0; b 10f; 9:; lwz 9,0x18(9); li 11,0; cmpwi 9,0; beq 10f; lwz 11,0x14(9); 10:; lwz 0,0x4(11); andi. 9,0,1024; beq 11f; lwz 0,0x0(31); addi 4,1,8; lwz 3,0x4(29); stw 0,0x20(1); lwz 9,0x8(31); stw 9,0x28(1); lwz 0,0x4(11); stw 0,0x8(1); bl _s8022C18C_1; 11:; addi 31,31,112; addic. 30,30,-1; bne 7b; 12:; mr 30,27; mr. 28,28; bne 5b; 13:; lwz 0,0x5c(1); mtspr 8,0; lmw 26,0x40(1); addi 1,1,88"

extern "C" void _s8022C18C_0();
extern "C" void _s8022C18C_1();

struct EIStaticModel {
    void RegisterFloor();
};

void EIStaticModel::RegisterFloor() {
}
