// 0x80040030 EGlobal::GetUrbzButtonsRow(unsigned (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,4; lwz 3,0xe8(3); lis 4,-32707; addi 4,4,10264; bl _s80040030_0; mr. 3,3; bne 0f; li 3,0; 0:; cmpwi 3,0; beq 2f; lwz 11,0xc(3); li 9,0; lwz 3,0x4(3); cmpw 9,11; bge 2f; 1:; lwz 0,0x0(3); cmpw 0,31; beq 3f; addi 9,9,1; addi 3,3,12; cmpw 9,11; blt 1b; 2:; li 3,0; 3:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s80040030_0();

struct EGlobal {
    void GetUrbzButtonsRow();
};

void EGlobal::GetUrbzButtonsRow() {
}
