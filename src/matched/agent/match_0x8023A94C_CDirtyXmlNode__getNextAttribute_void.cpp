// 0x8023A94C CDirtyXmlNode::getNextAttribute(void) (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); li 0,0; addi 30,1,8; stw 0,0x8(1); mr 31,4; stw 0,0x4(30); mr 28,3; stw 0,0x8(1); lis 27,-32695; addi 5,27,-784; li 6,128; lwz 3,0x4(31); lwz 4,0x18(31); stw 0,0x4(30); bl _s8023A94C_0; cmpwi 3,0; ble 0f; lwz 3,0x4(31); lis 29,-32695; lwz 4,0x18(31); addi 5,29,-656; li 6,128; bl _s8023A94C_1; cmpwi 3,0; ble 0f; lwz 9,0x18(31); addi 0,27,-784; stw 0,0x8(1); addi 11,29,-656; addi 9,9,1; stw 11,0x4(30); stw 9,0x18(31); 0:; lwz 9,0x8(1); lwz 10,0xc(1); mr 3,28; stw 9,0x0(28); stw 10,0x4(28); lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s8023A94C_0();
extern "C" void _s8023A94C_1();
extern "C" void f_8023A94C() {}
