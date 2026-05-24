// 0x80324620 EDatasetManager::AddRefAsync(char (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; bl _s80324620_0; lwz 0,-26632(13); li 3,1; cmpwi 0,0; beq 0f; mr 3,31; mr 4,30; bl _s80324620_1; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s80324620_0();
extern "C" void _s80324620_1();

struct EDatasetManager {
    void AddRefAsync();
};

void EDatasetManager::AddRefAsync() {
}
