// 0x8017E028 UIReflow::AddToBlock(char (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,4; lwz 0,0x0(31); cmpwi 0,0; beq 1f; lwz 0,0x4(31); cmpwi 0,0; beq 1f; mr 3,29; bl _s8017E028_0; lwz 0,0x10(31); mr 30,3; lwz 9,0xc(31); add 0,0,30; cmplw 0,9; stw 0,0x10(31); blt 0f; mr 3,31; bl _s8017E028_1; 0:; lwz 3,0x4(31); mr 4,29; bl _s8017E028_2; lwz 0,0x4(31); add 0,0,30; stw 0,0x4(31); 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s8017E028_0();
extern "C" void _s8017E028_1();
extern "C" void _s8017E028_2();

struct UIReflow {
    void AddToBlock();
};

void UIReflow::AddToBlock() {
}
