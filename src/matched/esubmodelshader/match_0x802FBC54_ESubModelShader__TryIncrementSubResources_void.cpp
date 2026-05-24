// 0x802FBC54 ESubModelShader::TryIncrementSubResources(void) (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 5,3; lwz 4,0xc(5); cmpwi 4,0; beq 0f; lis 3,-32692; addi 5,5,8; addi 3,3,-17444; bl _s802FBC54_0; cmpwi 3,0; li 3,0; beq 1f; 0:; li 3,1; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s802FBC54_0();

struct ESubModelShader {
    void TryIncrementSubResources();
};

void ESubModelShader::TryIncrementSubResources() {
}
