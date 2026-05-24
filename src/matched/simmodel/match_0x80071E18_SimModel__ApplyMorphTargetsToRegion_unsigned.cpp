// 0x80071E18 SimModel::ApplyMorphTargetsToRegion(unsigned (588 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stfd f30,0x50(1); stfd f31,0x58(1); stmw 25,0x34(1); stw 0,0x64(1); mr 26,4; mr 28,5; lwz 4,0x6c(3); fmr f31,f1; mr 25,6; cmpwi 4,0; beq 14f; lwz 29,0x120(4); cmpwi 29,0; beq 14f; lwz 0,0x4(3); andi. 9,0,4; bne 14f; ori 0,0,2; addi 4,3,104; stw 0,0x4(3); li 31,-1; addi 3,1,8; bl _s80071E18_0; lis 9,-32707; fmr f1,f31; lfs f31,0x55e4(9); addi 3,1,8; stw 31,0x10(1); addi 4,1,12; stw 31,0x18(1); addi 5,1,16; stfs f31,0xc(1); addi 6,1,20; stfs f31,0x14(1); addi 7,1,24; bl _s80071E18_1; lfs f0,0xc(1); fcmpu 0,f0,f31; bne 0f; stw 31,0x10(1); 0:; lfs f0,0x14(1); fcmpu 0,f0,f31; bne 1f; stw 31,0x18(1); 1:; bl _s80071E18_2; rlwinm 4,28,2,0,29; li 5,0; bl _s80071E18_3; mr. 27,3; bne 2f; addi 3,1,8; li 4,2; bl _s80071E18_4; b 14f; 2:; cmpwi 28,0; ble 4f; li 0,0; mr 9,27; mr 31,28; 3:; stw 0,0x0(9); addic. 31,31,-1; addi 9,9,4; bne 3b; 4:; li 31,0; cmpw 31,28; bge 8f; li 30,0; 5:; lwzx 4,30,25; cmpwi 4,0; beq 7f; lwz 0,0x10(1); cmpw 31,0; beq 6f; lwz 0,0x18(1); cmpw 31,0; bne 7f; 6:; mr 3,29; add 5,26,31; bl _s80071E18_5; mr 0,3; mr 4,29; stwx 0,30,27; bl _s80071E18_6; 7:; addi 31,31,1; addi 30,30,4; cmpw 31,28; blt 5b; 8:; lwz 4,0x10(1); lis 31,17200; lis 9,-32707; xoris 0,4,32768; lfd f31,0x55e8(9); stw 0,0x2c(1); lis 9,-32707; lfs f30,0x55f0(9); stw 31,0x28(1); lfd f0,0x28(1); fsub f0,f0,f31; frsp f0,f0; fcmpu 0,f0,f30; beq 9f; lfs f1,0xc(1); add 4,4,26; mr 3,29; bl _s80071E18_7; 9:; lwz 4,0x18(1); xoris 0,4,32768; stw 0,0x2c(1); stw 31,0x28(1); lfd f0,0x28(1); fsub f0,f0,f31; frsp f0,f0; fcmpu 0,f0,f30; beq 10f; lfs f1,0x14(1); add 4,4,26; mr 3,29; bl _s80071E18_8; 10:; mr 3,29; bl _s80071E18_9; cmpwi 28,0; ble 13f; mr 31,28; mr 30,27; 11:; lwz 4,0x0(30); addi 30,30,4; cmpwi 4,0; beq 12f; mr 3,29; bl _s80071E18_10; 12:; addic. 31,31,-1; bne 11b; 13:; bl _s80071E18_11; mr 4,27; bl _s80071E18_12; addi 3,1,8; li 4,2; bl _s80071E18_13; 14:; lwz 0,0x64(1); mtspr 8,0; lmw 25,0x34(1); lfd f30,0x50(1); lfd f31,0x58(1); addi 1,1,96"

extern "C" void _s80071E18_0();
extern "C" void _s80071E18_1();
extern "C" void _s80071E18_2();
extern "C" void _s80071E18_3();
extern "C" void _s80071E18_4();
extern "C" void _s80071E18_5();
extern "C" void _s80071E18_6();
extern "C" void _s80071E18_7();
extern "C" void _s80071E18_8();
extern "C" void _s80071E18_9();
extern "C" void _s80071E18_10();
extern "C" void _s80071E18_11();
extern "C" void _s80071E18_12();
extern "C" void _s80071E18_13();

struct SimModel {
    void ApplyMorphTargetsToRegion();
};

void SimModel::ApplyMorphTargetsToRegion() {
}
