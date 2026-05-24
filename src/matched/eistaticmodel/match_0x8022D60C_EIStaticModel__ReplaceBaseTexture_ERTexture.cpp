// 0x8022D60C EIStaticModel::ReplaceBaseTexture(ERTexture (640 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-104(1); mfspr 0,8; stmw 14,0x20(1); stw 0,0x6c(1); mr 15,3; mr 17,4; lwz 9,0x120(15); mr 18,6; stw 5,0x18(1); cmpwi 9,0; beq 17f; lwz 26,0x118(15); cmpwi 26,0; beq 17f; lwz 14,0x40(9); li 16,0; cmpw 16,14; bge 17f; stw 16,0x1c(1); 0:; lwz 9,0x120(15); li 23,0; lwz 0,0x3c(9); lwz 9,0x1c(1); add 19,0,9; lwz 20,0x4(19); cmpw 23,20; bge 16f; li 22,0; 1:; lwz 0,0x0(19); li 21,0; lwz 29,0x4(26); add 24,0,22; cmpwi 29,0; beq 15f; lwz 0,0x58(29); andi. 11,0,2; bne 15f; li 0,0; bne 4f; lwz 0,0x14(29); cmpwi 0,0; beq 2f; mr 11,0; b 3f; 2:; lwz 9,0x18(29); li 11,0; cmpwi 9,0; beq 3f; lwz 11,0x14(9); 3:; lwz 0,0x4(11); rlwinm 0,0,6,31,31; 4:; cmpwi 0,0; bne 15f; lwz 0,0x8(29); lwz 11,0x18(1); lwz 9,0x20(29); cmpw 0,11; bne 5f; li 21,1; cmpwi 9,0; beq 7f; lwz 9,0x8(9); lwz 0,0x8(18); b 6f; 5:; cmpwi 9,0; beq 7f; lwz 9,0x8(9); lwz 0,0x8(17); 6:; cmpw 9,0; beq 15f; 7:; lis 5,-32704; li 6,1; addi 5,5,-4556; addi 3,1,8; li 4,12; li 28,0; crxor 6,6,6; bl _s8022D60C_0; li 31,2; stb 28,0x13(1); addi 3,1,8; lwz 4,0x8(29); bl _s8022D60C_1; mr 30,3; lis 25,-32704; lis 27,-32692; b 10f; 8:; addi 3,27,-17444; li 28,1; bl _s8022D60C_2; li 31,1; 9:; mr 6,31; li 4,12; addi 5,25,-4556; addi 3,1,8; crxor 6,6,6; bl _s8022D60C_3; addi 31,31,1; lwz 4,0x8(29); addi 3,1,8; bl _s8022D60C_4; mr 30,3; 10:; addi 3,27,-17444; mr 4,30; bl _s8022D60C_5; cmpwi 3,0; beq 11f; cmplwi 31,99; ble 9b; cmpwi 28,0; beq 8b; addi 28,28,1; 11:; cmplwi 28,1; bgt 17f; mr 3,29; mr 4,30; bl _s8022D60C_6; mr. 31,3; beq 15f; addi 3,27,-17444; mr 5,30; mr 4,31; bl _s8022D60C_7; mr 3,31; bl _s8022D60C_8; lwz 3,0x8(24); cmpwi 3,0; beq 12f; bl _s8022D60C_9; 12:; stw 31,0x8(24); lwz 3,0x4(26); bl _s8022D60C_10; cmpwi 21,0; stw 31,0x4(26); beq 13f; mr 3,31; mr 4,18; li 5,0; bl _s8022D60C_11; b 14f; 13:; mr 3,31; mr 4,17; li 5,0; bl _s8022D60C_12; 14:; addi 26,26,16; 15:; addi 23,23,1; addi 22,22,112; cmpw 23,20; blt 1b; 16:; lwz 9,0x1c(1); addi 16,16,1; cmpw 16,14; addi 9,9,24; stw 9,0x1c(1); blt 0b; 17:; lwz 0,0x6c(1); mtspr 8,0; lmw 14,0x20(1); addi 1,1,104"

extern "C" void _s8022D60C_0();
extern "C" void _s8022D60C_1();
extern "C" void _s8022D60C_2();
extern "C" void _s8022D60C_3();
extern "C" void _s8022D60C_4();
extern "C" void _s8022D60C_5();
extern "C" void _s8022D60C_6();
extern "C" void _s8022D60C_7();
extern "C" void _s8022D60C_8();
extern "C" void _s8022D60C_9();
extern "C" void _s8022D60C_10();
extern "C" void _s8022D60C_11();
extern "C" void _s8022D60C_12();

struct EIStaticModel {
    void ReplaceBaseTexture_ERTexture();
};

void EIStaticModel::ReplaceBaseTexture_ERTexture() {
}
