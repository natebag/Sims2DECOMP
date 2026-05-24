// 0x800D8D90 NghResFile::SectionSaveViaRegistry(NghResFile::RegistryID, (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); li 0,0; addi 9,1,8; stw 0,0x8(1); mr 30,5; mr 31,6; stw 0,0xc(9); mr 5,9; stw 0,0x4(9); stw 0,0x8(9); bl _s800D8D90_0; cmpwi 3,0; beq 0f; lwz 0,0xc(1); cmpwi 0,0; beq 0f; mr 3,30; mr 4,31; mtspr 8,0; blrl; 0:; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"

extern "C" void _s800D8D90_0();

struct NghResFile {
    void SectionSaveViaRegistry_NghResFile__RegistryID();
};

void NghResFile::SectionSaveViaRegistry_NghResFile__RegistryID() {
}
