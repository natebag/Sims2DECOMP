// 0x80324810 EDatasetManager::GetRef(unsigned (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,-26632(13); mr 9,3; li 3,1; cmpwi 0,0; beq 0f; mr 3,9; bl _s80324810_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s80324810_0();

struct EDatasetManager {
    void GetRef();
};

void EDatasetManager::GetRef() {
}
