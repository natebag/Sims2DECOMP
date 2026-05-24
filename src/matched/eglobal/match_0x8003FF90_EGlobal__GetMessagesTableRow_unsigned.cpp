// 0x8003FF90 EGlobal::GetMessagesTableRow(unsigned (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr. 31,4; beq 4f; lwz 3,0xe8(3); lis 4,-32707; addi 4,4,10248; bl _s8003FF90_0; mr. 3,3; beq 1f; b 2f; 0:; mr 3,9; b 5f; 1:; li 3,0; 2:; cmpwi 3,0; beq 4f; lwz 0,0xc(3); li 11,0; lwz 3,0x4(3); cmpw 11,0; bge 4f; mr 9,3; mr 10,0; addi 3,3,16; 3:; lha 0,0x0(3); addi 3,3,20; cmpw 0,31; beq 0b; addi 11,11,1; addi 9,9,20; cmpw 11,10; blt 3b; 4:; li 3,0; 5:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s8003FF90_0();

struct EGlobal {
    void GetMessagesTableRow();
};

void EGlobal::GetMessagesTableRow() {
}
