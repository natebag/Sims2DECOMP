// 0x801B2F28 FAMTarget::ConvertNumericMoneyToString(int, (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-544(1); mfspr 0,8; stmw 28,0x210(1); stw 0,0x224(1); addi 30,1,8; mr 29,4; mr 28,5; addi 4,30,8; li 5,256; mr 3,30; bl _s801B2F28_0; mr 4,30; mr 3,29; li 5,1; bl _s801B2F28_1; mr 3,30; bl _s801B2F28_2; mr 4,3; mr 3,28; bl _s801B2F28_3; lwz 0,0x224(1); mtspr 8,0; lmw 28,0x210(1); addi 1,1,544"

extern "C" void _s801B2F28_0();
extern "C" void _s801B2F28_1();
extern "C" void _s801B2F28_2();
extern "C" void _s801B2F28_3();

struct FAMTarget {
    void ConvertNumericMoneyToString();
};

void FAMTarget::ConvertNumericMoneyToString() {
}
