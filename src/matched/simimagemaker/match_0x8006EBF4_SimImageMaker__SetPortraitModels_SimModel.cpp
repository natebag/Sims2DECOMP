// 0x8006EBF4 SimImageMaker::SetPortraitModels(SimModel (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-104(1); mfspr 0,8; stmw 28,0x58(1); stw 0,0x6c(1); mr 28,3; mr. 4,4; beq 2f; lis 9,-32707; addi 11,1,8; mr 8,11; addi 9,9,21152; addi 29,4,104; li 10,72; 0:; lwz 0,0x0(9); addic. 10,10,-24; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); lwz 0,0xc(9); stw 0,0xc(11); lwz 0,0x10(9); stw 0,0x10(11); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(11); addi 11,11,24; bne 0b; lwz 0,0x0(9); mr 31,8; addi 30,31,72; stw 0,0x0(11); 1:; lwz 4,0x0(31); mr 3,28; addi 31,31,4; rlwinm 0,4,2,0,29; lwzx 5,29,0; bl _s8006EBF4_0; cmpw 31,30; ble 1b; 2:; lwz 0,0x6c(1); mtspr 8,0; lmw 28,0x58(1); addi 1,1,104"

extern "C" void _s8006EBF4_0();

struct SimImageMaker {
    void SetPortraitModels_SimModel();
};

void SimImageMaker::SetPortraitModels_SimModel() {
}
