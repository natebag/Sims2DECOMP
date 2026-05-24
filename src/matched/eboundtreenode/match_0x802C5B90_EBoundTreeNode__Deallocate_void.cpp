// 0x802C5B90 EBoundTreeNode::Deallocate(void) (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 29,3; li 30,1; lis 27,-32688; li 28,0; addi 31,29,36; 0:; lwz 3,0x0(31); addi 4,27,-13040; bl _s802C5B90_0; cmpwi 3,0; beq 1f; lwz 3,0x0(31); bl _s802C5B90_1; b 2f; 1:; lwz 3,0x0(31); lwz 9,0x0(3); lha 0,0x8(9); lwz 9,0xc(9); add 3,3,0; mtspr 8,9; blrl; 2:; stw 28,0x0(31); addic. 30,30,-1; addi 31,31,-4; bge 0b; lwz 9,0x0(29); lha 3,0x8(9); lwz 0,0xc(9); add 3,29,3; mtspr 8,0; blrl; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s802C5B90_0();
extern "C" void _s802C5B90_1();

struct EBoundTreeNode {
    void Deallocate();
};

void EBoundTreeNode::Deallocate() {
}
