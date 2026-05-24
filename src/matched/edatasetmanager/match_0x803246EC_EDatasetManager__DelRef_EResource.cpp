// 0x803246EC EDatasetManager::DelRef(EResource (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr. 4,4; beq 0f; cmpwi 4,1; beq 0f; bl _s803246EC_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s803246EC_0();

struct EDatasetManager {
    void DelRef_EResource();
};

void EDatasetManager::DelRef_EResource() {
}
