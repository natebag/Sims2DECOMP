// 0x8030552C EController::AddCmdsToFilter(unsigned (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr. 0,6; mr 28,3; mr 29,4; mtspr 9,0; ble 1f; mr 30,5; mfspr 31,9; 0:; lwz 5,0x0(30); mr 3,28; addi 30,30,4; mr 4,29; bl _s8030552C_0; addic. 31,31,-1; bne 0b; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s8030552C_0();

struct EController {
    void AddCmdsToFilter();
};

void EController::AddCmdsToFilter() {
}
