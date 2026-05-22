// 0x8023A8FC CDirtyXmlNode::getFirstAttribute(void) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); li 0,0; lwz 9,0x0(4); stw 0,0x18(4); mr 30,3; lha 0,0x20(9); lwz 9,0x24(9); add 4,4,0; mtspr 8,9; crxor 6,6,6; blrl; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_8023A8FC() {}
