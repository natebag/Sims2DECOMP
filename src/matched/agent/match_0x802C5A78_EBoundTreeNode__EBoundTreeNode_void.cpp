// 0x802C5A78 EBoundTreeNode::EBoundTreeNode(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); lis 9,-32697; mr 11,3; addi 9,9,-24560; lis 8,-32702; stw 9,0x0(11); addi 7,11,16; addi 6,11,4; li 10,0; lfs f0,-7540(8); stfs f0,0x8(1); stfs f0,0x10(1); stfs f0,0xc(1); lwz 0,0x8(1); lwz 8,0xc(1); lwz 9,0x10(1); stw 0,0x10(11); stw 9,0x8(7); stw 8,0x4(7); lwz 0,0x10(11); stw 0,0x4(11); stw 9,0x8(6); stw 8,0x4(6); stw 10,0x20(11); stw 10,0x1c(11); stw 10,0x24(11); addi 1,1,24"
extern "C" void f_802C5A78() {}
