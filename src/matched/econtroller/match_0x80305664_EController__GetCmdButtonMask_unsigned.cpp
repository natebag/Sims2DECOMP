// 0x80305664 EController::GetCmdButtonMask(unsigned (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,4; li 30,0; bl _s80305664_0; mr. 3,3; b 1f; 0:; lwz 0,0x4(3); addic. 3,3,8; or 30,30,0; 1:; beq 2f; lwz 0,0x0(3); cmpw 0,31; beq 0b; 2:; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s80305664_0();

struct EController {
    void GetCmdButtonMask();
};

void EController::GetCmdButtonMask() {
}
