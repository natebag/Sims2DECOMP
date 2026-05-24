// 0x80363C74 EFontSize::DeallocateShaders(void) (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,3; li 31,0; addi 9,29,32; lwz 0,0x4(9); cmpw 31,0; bge 1f; mr 28,9; li 30,0; 0:; lwz 9,0x20(29); addi 31,31,1; lwzx 3,9,30; addi 30,30,4; bl _s80363C74_0; lwz 0,0x4(28); cmpw 31,0; blt 0b; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s80363C74_0();

struct EFontSize {
    void DeallocateShaders();
};

void EFontSize::DeallocateShaders() {
}
