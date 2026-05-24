// 0x80164ABC CasNpcEditor::GetNPCCompositeTextureName(CasSimDescriptionS2C (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 31,3; mr 29,4; mr 28,6; mr. 27,5; bne 0f; lis 4,-32706; addi 4,4,-2656; bl _s80164ABC_0; b 1f; 0:; addi 30,1,8; mr 3,30; bl _s80164ABC_1; lwz 5,0xc(29); lis 4,-32706; addi 4,4,-2140; mr 3,30; crxor 6,6,6; bl _s80164ABC_2; lwz 5,0x8(1); mr 4,27; mr 3,31; mr 6,28; bl _s80164ABC_3; lwz 4,0x8(1); mr 3,30; bl _s80164ABC_4; 1:; mr 3,31; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"

extern "C" void _s80164ABC_0();
extern "C" void _s80164ABC_1();
extern "C" void _s80164ABC_2();
extern "C" void _s80164ABC_3();
extern "C" void _s80164ABC_4();

struct CasNpcEditor {
    void GetNPCCompositeTextureName_CasSimDescriptionS2();
};

void CasNpcEditor::GetNPCCompositeTextureName_CasSimDescriptionS2() {
}
