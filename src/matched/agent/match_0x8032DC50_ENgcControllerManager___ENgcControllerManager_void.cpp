// 0x8032DC50 ENgcControllerManager::~ENgcControllerManager(void) (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32697; andi. 0,4,1; addi 9,9,-17768; stw 9,0x20(3); beq 0f; bl _s8032DC50_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8032DC50_0();
extern "C" void f_8032DC50() {}
