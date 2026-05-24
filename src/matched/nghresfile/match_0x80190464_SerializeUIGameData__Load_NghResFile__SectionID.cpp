// 0x80190464 SerializeUIGameData::Load(NghResFile::SectionID, (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 0,21865; li 9,1; ori 0,0,30769; li 11,0; cmpw 3,0; beq 3f; lis 0,21865; ori 0,0,30770; cmpw 3,0; bne 0f; li 11,1; b 3f; 0:; lis 0,21865; ori 0,0,30771; cmpw 3,0; bne 1f; li 11,2; b 3f; 1:; lis 0,21865; ori 0,0,30772; cmpw 3,0; bne 2f; li 11,3; b 3f; 2:; li 9,0; 3:; cmpwi 9,0; beq 5f; lwz 5,0x0(4); cmplwi 5,1024; ble 4f; li 5,1024; 4:; lis 9,-32701; rlwinm 0,11,2,0,29; addi 9,9,27664; lwz 4,0x4(4); lwzx 3,9,0; bl _s80190464_0; 5:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s80190464_0();

struct NghResFile {
    void Load_NghResFile__SectionID();
};

void NghResFile::Load_NghResFile__SectionID() {
}
