// 0x8028557C AptActionQueueC::RegisterReferences(void) (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 28,3; li 30,0; bl _s8028557C_0; mr 29,3; cmpw 30,29; bge 3f; lis 25,-32704; lis 26,-32704; lis 27,-32704; 0:; mr 3,28; mr 4,30; bl _s8028557C_1; mr 31,3; lwz 0,0x0(31); cmpwi 0,1; bne 1f; lwz 9,-27024(13); li 3,0; lwz 4,0x10(31); addi 5,25,13188; mtspr 8,9; blrl; b 2f; 1:; cmpwi 0,2; bne 2f; lwz 9,-27024(13); li 3,0; lwz 4,0x8(31); addi 5,26,13224; mtspr 8,9; blrl; lwz 9,-27024(13); li 3,0; lwz 4,0xc(31); addi 5,27,13264; mtspr 8,9; blrl; 2:; addi 30,30,1; cmpw 30,29; blt 0b; 3:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"

extern "C" void _s8028557C_0();
extern "C" void _s8028557C_1();

struct AptActionQueueC {
    void RegisterReferences();
};

void AptActionQueueC::RegisterReferences() {
}
