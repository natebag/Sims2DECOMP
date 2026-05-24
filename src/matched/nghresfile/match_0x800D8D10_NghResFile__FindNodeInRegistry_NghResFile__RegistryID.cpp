// 0x800D8D10 NghResFile::FindNodeInRegistry(NghResFile::RegistryID, (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,0x10(3); li 8,0; lwz 0,0x14(3); cmplw 11,0; bge 2f; lwz 0,0x0(11); cmpw 0,4; bne 0f; lwz 0,0xc(11); li 8,1; lwz 9,0x4(11); lwz 11,0x8(11); stw 0,0xc(5); stw 4,0x0(5); b 1f; 0:; lwz 0,0x14(3); addi 11,11,16; cmplw 11,0; bge 2f; lwz 10,0x0(11); cmpw 10,4; bne 0b; lwz 0,0xc(11); li 8,1; lwz 9,0x4(11); lwz 11,0x8(11); stw 0,0xc(5); stw 10,0x0(5); 1:; stw 9,0x4(5); stw 11,0x8(5); 2:; mr 3,8"

struct NghResFile {
    void FindNodeInRegistry_NghResFile__RegistryID();
};

void NghResFile::FindNodeInRegistry_NghResFile__RegistryID() {
}
