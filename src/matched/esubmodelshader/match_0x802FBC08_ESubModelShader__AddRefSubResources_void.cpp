// 0x802FBC08 ESubModelShader::AddRefSubResources(void) (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 4,0xc(31); cmpwi 4,0; beq 0f; lis 3,-32692; li 5,0; addi 3,3,-17444; li 6,0; bl _s802FBC08_0; stw 3,0x8(31); 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s802FBC08_0();

struct ESubModelShader {
    void AddRefSubResources();
};

void ESubModelShader::AddRefSubResources() {
}
