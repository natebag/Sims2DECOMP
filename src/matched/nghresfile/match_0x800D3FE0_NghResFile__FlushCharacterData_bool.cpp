// 0x800D3FE0 NghResFile::FlushCharacterData(bool) (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; mfcr 12; stmw 28,0x10(1); stw 0,0x24(1); stw 12,0xc(1); cmpwi 3,4,0; li 29,0; mcrf cr4,cr3; mr 30,3; cmpwi 29,1; li 28,0; li 31,0; 0:; bne cr4,1f; beq 2f; 1:; lwz 9,0x17c(30); lwzx 3,31,9; bl _s800D3FE0_0; lwz 9,0x17c(30); stwx 28,31,9; 2:; addi 29,29,1; addi 31,31,4; cmpwi 29,1; ble 0b; beq cr3,4f; li 9,36; addi 3,30,544; mtspr 9,9; li 0,0; 3:; stw 0,0x0(3); addi 3,3,-4; bdnz 3b; 4:; lwz 0,0x24(1); lwz 12,0xc(1); mtspr 8,0; lmw 28,0x10(1); mtcrf 24,12; addi 1,1,32"

extern "C" void _s800D3FE0_0();

struct NghResFile {
    void FlushCharacterData();
};

void NghResFile::FlushCharacterData() {
}
