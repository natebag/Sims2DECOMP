// 0x803181E4 ERModel::TryIncrementSubResources(void) (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,3; li 31,0; addi 9,29,60; lwz 0,0x4(9); cmpw 31,0; bge 4f; mr 28,9; li 30,0; 0:; lwz 3,0x3c(29); add 3,3,30; bl _s803181E4_0; cmpwi 3,0; bne 3f; addic. 30,31,-1; blt 2f; mulli 31,30,24; 1:; lwz 3,0x3c(29); add 3,3,31; bl _s803181E4_1; addi 31,31,-24; addic. 30,30,-1; bge 1b; 2:; li 3,0; b 5f; 3:; lwz 0,0x4(28); addi 31,31,1; addi 30,30,24; cmpw 31,0; blt 0b; 4:; li 3,1; 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s803181E4_0();
extern "C" void _s803181E4_1();

struct ERModel {
    void TryIncrementSubResources();
};

void ERModel::TryIncrementSubResources() {
}
