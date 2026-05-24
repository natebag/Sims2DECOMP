// 0x80333C5C ENgcMemoryCard::IsEnoughFiles(unsigned (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 30,5; li 29,0; mr 31,6; stw 29,0x8(1); addi 5,1,8; bl _s80333C5C_0; lwz 0,0x8(1); cmplw 0,30; blt 0f; li 0,1; stw 0,0x0(31); b 1f; 0:; stw 29,0x0(31); 1:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"

extern "C" void _s80333C5C_0();

struct ENgcMemoryCard {
    void IsEnoughFiles();
};

void ENgcMemoryCard::IsEnoughFiles() {
}
