// 0x8036B490 RParticle::AddRefSubResources(void) (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 27,3; lwz 29,0x14(27); cmpwi 29,0; beq 4f; lwz 0,0x108(29); andis. 9,0,32; beq 0f; lis 3,-32692; lwz 4,0x16c(29); addi 3,3,-27556; b 3f; 0:; andis. 9,0,512; beq 2f; lwz 0,0x18(27); li 28,0; cmpw 28,0; bge 4f; lis 26,-32692; addi 30,27,28; li 31,364; 1:; lwzx 4,31,29; addi 3,26,-27556; li 5,0; li 6,0; bl _s8036B490_0; addi 28,28,1; stw 3,0x0(30); stwx 3,31,29; addi 30,30,4; addi 31,31,132; lwz 0,0x18(27); cmpw 28,0; blt 1b; b 4f; 2:; lis 3,-32692; lwz 4,0x16c(29); addi 3,3,-17444; 3:; li 5,0; li 6,0; bl _s8036B490_1; stw 3,0x1c(27); stw 3,0x16c(29); 4:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"

extern "C" void _s8036B490_0();
extern "C" void _s8036B490_1();

struct RParticle {
    void AddRefSubResources();
};

void RParticle::AddRefSubResources() {
}
