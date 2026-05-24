// 0x80354838 Effects::FastParticleEmitter::InitResourceData(void) (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 3,0x194(31); cmpwi 3,0; beq 0f; bl _s80354838_0; li 0,0; stw 0,0x194(31); 0:; lwz 9,0x18c(31); lwz 0,0xc0(9); cmpwi 0,0; bne 1f; lis 3,-32702; addi 3,3,10592; bl _s80354838_1; lwz 9,0x18c(31); stw 3,0xc0(9); 1:; lwz 9,0x18c(31); lis 30,-32692; addi 30,30,-7364; li 5,0; lwz 4,0xc0(9); li 6,0; mr 3,30; bl _s80354838_2; lwz 9,0x18c(31); mr 3,30; lwz 4,0xc0(9); bl _s80354838_3; stw 3,0x194(31); li 3,1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s80354838_0();
extern "C" void _s80354838_1();
extern "C" void _s80354838_2();
extern "C" void _s80354838_3();

struct Effects {
    void FastParticleEmitter__InitResourceData();
};

void Effects::FastParticleEmitter__InitResourceData() {
}
