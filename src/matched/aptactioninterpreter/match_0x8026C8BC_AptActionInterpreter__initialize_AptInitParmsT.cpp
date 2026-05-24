// 0x8026C8BC AptActionInterpreter::initialize(AptInitParmsT (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 29,4; mr 30,3; lwz 0,0x20(29); addi 28,30,12; lwz 3,-23020(13); addi 27,30,24; rlwinm 4,0,2,0,29; stw 0,0x4(30); bl _s8026C8BC_0; addi 26,30,36; stw 3,0x8(30); lwz 3,-23020(13); lwz 0,0x24(29); rlwinm 4,0,2,0,29; stw 0,0x4(28); bl _s8026C8BC_1; stw 3,0x8(28); lwz 3,-23020(13); lwz 0,0x24(29); rlwinm 4,0,2,0,29; stw 0,0x4(27); bl _s8026C8BC_2; stw 3,0x8(27); lwz 3,-23020(13); lwz 0,0x24(29); rlwinm 4,0,2,0,29; stw 0,0x4(26); bl _s8026C8BC_3; stw 3,0x8(26); li 0,0; stw 0,0x58(30); mr 3,29; stw 0,0x5c(30); bl _s8026C8BC_4; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"

extern "C" void _s8026C8BC_0();
extern "C" void _s8026C8BC_1();
extern "C" void _s8026C8BC_2();
extern "C" void _s8026C8BC_3();
extern "C" void _s8026C8BC_4();

struct AptActionInterpreter {
    void initialize_AptInitParmsT();
};

void AptActionInterpreter::initialize_AptInitParmsT() {
}
