// 0x802C5D7C EBoundTreeNode::RegisterType(unsigned (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 7,3; lis 4,-32724; lis 3,-32688; lis 5,-32724; lis 6,-32724; lis 8,-32702; lis 9,-32688; addi 3,3,-13040; addi 4,4,23708; addi 5,5,23748; addi 6,6,23780; addi 8,8,-7556; addi 9,9,-13320; bl _s802C5D7C_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802C5D7C_0();
extern "C" void f_802C5D7C() {}
