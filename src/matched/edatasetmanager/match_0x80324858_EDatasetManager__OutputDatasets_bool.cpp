// 0x80324858 EDatasetManager::OutputDatasets(bool) (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; xori 3,30,1; bl _s80324858_0; stw 30,-26628(13); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s80324858_0();

struct EDatasetManager {
    void OutputDatasets();
};

void EDatasetManager::OutputDatasets() {
}
