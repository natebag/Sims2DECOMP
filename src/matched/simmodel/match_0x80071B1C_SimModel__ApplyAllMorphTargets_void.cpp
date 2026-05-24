// 0x80071B1C SimModel::ApplyAllMorphTargets(void) (764 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-112(1); mfspr 0,8; stfd f31,0x68(1); stmw 25,0x4c(1); stw 0,0x74(1); mr 28,3; lwz 3,0x6c(28); cmpwi 3,0; beq 17f; lwz 25,0x120(3); cmpwi 25,0; beq 17f; lwz 0,0x4(28); andi. 9,0,4; bne 17f; ori 0,0,2; mr 3,25; stw 0,0x4(28); bl _s80071B1C_0; lwz 9,0x13c(28); lwz 11,0x138(28); lbz 0,0x8c(9); lwz 10,0x4(11); extsb 0,0; mulli 0,0,12; lwz 9,0x1c(10); add 31,9,0; addic. 26,31,8; beq 1f; lwz 9,0x8(31); li 0,0; cmpwi 9,0; beq 0f; lwz 0,-4(9); 0:; cmpwi 0,0; bne 2f; 1:; mr 3,25; bl _s80071B1C_1; mr 3,25; bl _s80071B1C_2; mr 3,25; bl _s80071B1C_3; b 17f; 2:; mr 3,28; bl _s80071B1C_4; lwz 9,0x8(31); mr 27,3; li 0,0; cmpwi 9,0; beq 3f; lwz 0,-4(9); 3:; cmpwi 0,14; bne 8f; li 31,0; li 30,0; addi 29,1,56; b 6f; 4:; addi 0,30,-9; cmplwi 0,1; ble 5f; rlwinm 9,30,2,0,29; mr 4,27; lwzx 3,11,9; bl _s80071B1C_5; rlwinm 11,31,2,0,29; addi 9,1,8; addi 0,31,1; stwx 3,9,11; rlwinm 31,0,0,24,31; 5:; addi 30,30,1; 6:; lwz 11,0x0(26); li 0,0; cmpwi 11,0; beq 7f; lwz 0,-4(11); 7:; cmpw 30,0; blt 4b; b 12f; 8:; li 31,0; addi 29,1,56; b 10f; 9:; rlwinm 30,31,2,0,29; mr 4,27; lwzx 3,9,30; addi 31,31,1; bl _s80071B1C_6; addi 9,1,8; stwx 3,9,30; 10:; lwz 9,0x0(26); li 0,0; cmpwi 9,0; beq 11f; lwz 0,-4(9); 11:; cmpw 31,0; blt 9b; 12:; mr 3,29; li 4,0; li 5,12; bl _s80071B1C_7; lwz 10,0x13c(28); lis 9,-32707; lfs f31,0x55e0(9); lfs f0,0x108(10); fcmpu 0,f0,f31; beq 13f; lwz 0,0x8(1); mr 3,28; lwz 11,0xc(1); li 4,0; lwz 9,0x10(1); li 5,3; stw 0,0x38(1); mr 6,29; stw 11,0x3c(1); stw 9,0x40(1); lfs f1,0x108(10); bl _s80071B1C_8; mr 3,29; li 4,0; li 5,12; bl _s80071B1C_9; 13:; lwz 10,0x13c(28); lfs f0,0x114(10); fcmpu 0,f0,f31; beq 14f; lwz 0,0x2c(1); mr 3,28; lwz 11,0x30(1); li 4,9; lwz 9,0x34(1); li 5,3; stw 0,0x38(1); mr 6,29; stw 11,0x3c(1); stw 9,0x40(1); lfs f1,0x114(10); bl _s80071B1C_10; mr 3,29; li 4,0; li 5,12; bl _s80071B1C_11; 14:; lwz 10,0x13c(28); lfs f0,0x10c(10); fcmpu 0,f0,f31; beq 15f; lwz 0,0x20(1); mr 3,28; lwz 11,0x24(1); li 4,6; lwz 9,0x28(1); li 5,3; stw 0,0x38(1); mr 6,29; stw 11,0x3c(1); stw 9,0x40(1); lfs f1,0x10c(10); bl _s80071B1C_12; mr 3,29; li 4,0; li 5,12; bl _s80071B1C_13; 15:; lwz 10,0x13c(28); lfs f0,0x110(10); fcmpu 0,f0,f31; beq 16f; lwz 0,0x14(1); mr 3,28; lwz 11,0x18(1); li 4,3; lwz 9,0x1c(1); li 5,3; stw 0,0x38(1); mr 6,29; stw 11,0x3c(1); stw 9,0x40(1); lfs f1,0x110(10); bl _s80071B1C_14; mr 3,29; li 4,0; li 5,12; bl _s80071B1C_15; 16:; mr 3,25; bl _s80071B1C_16; mr 3,25; bl _s80071B1C_17; 17:; lwz 0,0x74(1); mtspr 8,0; lmw 25,0x4c(1); lfd f31,0x68(1); addi 1,1,112"

extern "C" void _s80071B1C_0();
extern "C" void _s80071B1C_1();
extern "C" void _s80071B1C_2();
extern "C" void _s80071B1C_3();
extern "C" void _s80071B1C_4();
extern "C" void _s80071B1C_5();
extern "C" void _s80071B1C_6();
extern "C" void _s80071B1C_7();
extern "C" void _s80071B1C_8();
extern "C" void _s80071B1C_9();
extern "C" void _s80071B1C_10();
extern "C" void _s80071B1C_11();
extern "C" void _s80071B1C_12();
extern "C" void _s80071B1C_13();
extern "C" void _s80071B1C_14();
extern "C" void _s80071B1C_15();
extern "C" void _s80071B1C_16();
extern "C" void _s80071B1C_17();

struct SimModel {
    void ApplyAllMorphTargets();
};

void SimModel::ApplyAllMorphTargets() {
}
