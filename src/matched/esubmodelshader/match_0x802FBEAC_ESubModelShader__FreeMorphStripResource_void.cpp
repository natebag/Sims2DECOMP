// 0x802FBEAC ESubModelShader::FreeMorphStripResource(void) (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 30,3; li 29,0; addi 9,30,44; lwz 0,0x4(9); cmpw 29,0; bge 1f; mr 27,9; li 31,0; li 28,0; 0:; lwz 9,0x2c(30); mr 3,30; addi 29,29,1; add 9,9,28; mr 4,9; stw 31,0xc(9); stw 31,0x14(9); addi 28,28,52; stw 31,0x4(9); stw 31,0x10(9); stw 31,0x8(9); bl _s802FBEAC_0; lwz 0,0x4(27); cmpw 29,0; blt 0b; 1:; addi 3,30,44; bl _s802FBEAC_1; addi 3,30,56; li 4,0; li 5,48; bl _s802FBEAC_2; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s802FBEAC_0();
extern "C" void _s802FBEAC_1();
extern "C" void _s802FBEAC_2();

struct ESubModelShader {
    void FreeMorphStripResource();
};

void ESubModelShader::FreeMorphStripResource() {
}
