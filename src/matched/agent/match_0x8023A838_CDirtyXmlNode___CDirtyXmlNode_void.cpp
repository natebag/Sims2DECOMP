// 0x8023A838 CDirtyXmlNode::~CDirtyXmlNode(void) (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; lis 9,-32697; lwz 0,0x10(31); addi 9,9,-24968; mr 28,4; stw 9,0x0(31); cmpwi 0,0; ble 3f; li 30,0; cmpw 30,0; bge 2f; li 29,0; 0:; lwz 9,0x1c(31); lwzx 11,29,9; cmpwi 11,0; beq 1f; lwz 9,0x0(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 1:; lwz 0,0x10(31); addi 30,30,1; addi 29,29,4; cmpw 30,0; blt 0b; 2:; lwz 3,0x1c(31); cmpwi 3,0; beq 3f; bl _s8023A838_0; 3:; lis 9,-32697; andi. 0,28,1; addi 9,9,-24752; stw 9,0x0(31); beq 4f; mr 3,31; bl _s8023A838_1; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8023A838_0();
extern "C" void _s8023A838_1();
extern "C" void f_8023A838() {}
