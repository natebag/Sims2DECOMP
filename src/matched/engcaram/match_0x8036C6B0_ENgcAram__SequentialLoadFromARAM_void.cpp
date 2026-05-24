// 0x8036C6B0 ENgcAram::SequentialLoadFromARAM(void (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 0,-25816(13); mr 30,3; mr 29,4; mr 31,5; cmpwi 0,0; beq 1f; 0:; lwz 0,-25816(13); cmpwi 0,0; bne 0b; 1:; li 0,1; mr 3,30; stw 0,-25816(13); mr 4,31; bl _s8036C6B0_0; lis 3,-32690; lis 10,-32713; addi 3,3,-6592; mr 7,29; mr 8,30; mr 9,31; addi 10,10,-14524; li 4,0; li 5,1; li 6,1; bl _s8036C6B0_1; 2:; lwz 0,-25816(13); cmpwi 0,0; bne 2b; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s8036C6B0_0();
extern "C" void _s8036C6B0_1();

struct ENgcAram {
    void SequentialLoadFromARAM();
};

void ENgcAram::SequentialLoadFromARAM() {
}
