// 0x8002314C ESimsDataManager::preloadResources(EEvent (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; lwz 4,-32056(13); lis 5,28514; lwz 3,0xd34(30); ori 5,5,27252; li 6,0; li 7,0; bl _s8002314C_0; lwz 9,0xd34(30); mr 3,29; lwz 11,0x0(9); lwz 0,0x4(9); subf 0,11,0; srawi 0,0,2; stw 0,0xd28(30); bl _s8002314C_1; lwz 3,0xd34(30); addi 4,30,3364; bl _s8002314C_2; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s8002314C_0();
extern "C" void _s8002314C_1();
extern "C" void _s8002314C_2();

struct ESimsDataManager {
    void preloadResources_EEvent();
};

void ESimsDataManager::preloadResources_EEvent() {
}
