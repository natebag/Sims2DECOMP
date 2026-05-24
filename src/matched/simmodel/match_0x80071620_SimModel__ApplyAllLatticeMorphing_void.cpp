// 0x80071620 SimModel::ApplyAllLatticeMorphing(void) (268 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-232(1); mfspr 0,8; stmw 30,0xe0(1); stw 0,0xec(1); lis 9,-32707; addi 11,1,8; mr 8,11; mr 31,3; addi 9,9,21884; li 10,96; addi 4,1,112; addi 30,1,216; 0:; lwz 0,0x0(9); addic. 10,10,-24; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); lwz 0,0xc(9); stw 0,0xc(11); lwz 0,0x10(9); stw 0,0x10(11); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(11); addi 11,11,24; bne 0b; lwz 0,0x0(9); li 7,26; mtspr 9,7; li 10,0; stw 0,0x0(11); mr 9,4; 1:; stw 10,0x0(9); addi 9,9,4; bdnz 1b; li 0,25; mr 11,8; mtspr 9,0; mr 8,4; addi 10,31,104; 2:; lwz 9,0x0(11); addi 11,11,4; rlwinm 9,9,2,0,29; lwzx 0,9,31; andi. 7,0,4; bne 3f; lwzx 0,10,9; stwx 0,8,9; 3:; lwzx 0,9,31; ori 0,0,2; stwx 0,9,31; bdnz 2b; mr 3,30; bl _s80071620_0; lwz 4,0x13c(31); mr 3,30; bl _s80071620_1; mr 3,30; li 4,2; bl _s80071620_2; lwz 0,0xec(1); mtspr 8,0; lmw 30,0xe0(1); addi 1,1,232"

extern "C" void _s80071620_0();
extern "C" void _s80071620_1();
extern "C" void _s80071620_2();

struct SimModel {
    void ApplyAllLatticeMorphing();
};

void SimModel::ApplyAllLatticeMorphing() {
}
