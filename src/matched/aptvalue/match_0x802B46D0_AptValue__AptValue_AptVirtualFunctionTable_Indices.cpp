// 0x802B46D0 AptValue::AptValue(AptVirtualFunctionTable_Indices, (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32703; mr 30,3; addi 9,9,9120; stw 9,0x8(30); bl _s802B46D0_0; mr 3,30; li 4,0; bl _s802B46D0_1; mr 3,30; li 4,1; bl _s802B46D0_2; mr 3,30; li 4,0; bl _s802B46D0_3; mr 3,30; li 4,0; bl _s802B46D0_4; lwz 0,0x0(30); addi 11,13,-27020; mr 3,30; li 4,0; rlwinm 0,0,0,6,4; stw 0,0x0(30); lwz 9,0x0(11); stw 9,0x4(30); addi 9,9,1; stw 9,0x0(11); bl _s802B46D0_5; mr 3,30; bl _s802B46D0_6; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s802B46D0_0();
extern "C" void _s802B46D0_1();
extern "C" void _s802B46D0_2();
extern "C" void _s802B46D0_3();
extern "C" void _s802B46D0_4();
extern "C" void _s802B46D0_5();
extern "C" void _s802B46D0_6();

struct AptValue {
    void AptValue_AptVirtualFunctionTable_Indices();
};

void AptValue::AptValue_AptVirtualFunctionTable_Indices() {
}
