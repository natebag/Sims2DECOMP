// 0x80093D04 MUStatesSlotSelectSave::~MUStatesSlotSelectSave(void) (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32698; andi. 0,4,1; addi 9,9,-13880; stw 9,0x18(3); beq 0f; bl _s80093D04_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80093D04_0();
extern "C" void f_80093D04() {}
