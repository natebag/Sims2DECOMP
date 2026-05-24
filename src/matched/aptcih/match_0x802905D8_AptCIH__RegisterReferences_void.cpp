// 0x802905D8 AptCIH::RegisterReferences(void) (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; bl _s802905D8_0; lwz 4,0x48(31); mr 30,3; cmpwi 4,0; beq 0f; lwz 9,-27024(13); lis 5,-32704; addi 5,5,23124; mr 3,31; mtspr 8,9; blrl; 0:; cmpwi 30,0; beq 1f; mr 3,30; mr 4,31; bl _s802905D8_1; 1:; mr 3,31; li 29,0; bl _s802905D8_2; li 30,0; cmpwi 3,13; bne 2f; mr 3,31; bl _s802905D8_3; subfic 0,3,0; adde 30,0,3; 2:; cmpwi 30,0; bne 4f; mr 3,31; li 30,0; bl _s802905D8_4; cmpwi 3,18; bne 3f; mr 3,31; bl _s802905D8_5; subfic 0,3,0; adde 30,0,3; 3:; cmpwi 30,0; beq 5f; 4:; li 29,1; 5:; cmpwi 29,0; beq 6f; lwz 3,0x4c(31); cmpwi 3,0; beq 6f; addi 3,3,36; bl _s802905D8_6; mr 4,31; bl _s802905D8_7; 6:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s802905D8_0();
extern "C" void _s802905D8_1();
extern "C" void _s802905D8_2();
extern "C" void _s802905D8_3();
extern "C" void _s802905D8_4();
extern "C" void _s802905D8_5();
extern "C" void _s802905D8_6();
extern "C" void _s802905D8_7();

struct AptCIH {
    void RegisterReferences();
};

void AptCIH::RegisterReferences() {
}
