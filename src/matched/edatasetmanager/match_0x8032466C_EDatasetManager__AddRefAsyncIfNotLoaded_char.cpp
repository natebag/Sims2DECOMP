// 0x8032466C EDatasetManager::AddRefAsyncIfNotLoaded(char (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; bl _s8032466C_0; cmpwi 3,0; bne 0f; lwz 11,-22652(13); lwz 9,0x0(11); lwz 0,0xe4(9); lha 3,0xe0(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0xd1c(31); mr 4,30; lha 3,0x28(9); lwz 0,0x2c(9); add 3,31,3; mtspr 8,0; blrl; b 1f; 0:; mr 3,31; mr 4,30; bl _s8032466C_1; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s8032466C_0();
extern "C" void _s8032466C_1();

struct EDatasetManager {
    void AddRefAsyncIfNotLoaded();
};

void EDatasetManager::AddRefAsyncIfNotLoaded() {
}
