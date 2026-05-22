// 0x8023A604 _ParseChildNodes(CDirtyXmlNode (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 30,5; mr 29,3; mr 28,4; mr 3,30; bl _s8023A604_0; mr. 31,3; beq 1f; li 3,0; mr 4,31; bl _s8023A604_1; stw 3,0x0(29); cmpwi 28,1; ble 2f; addi 29,29,4; addi 30,28,-1; 0:; mr 3,31; bl _s8023A604_2; mr 31,3; li 3,0; mr 4,31; bl _s8023A604_3; stw 3,0x0(29); addic. 30,30,-1; addi 29,29,4; bne 0b; b 2f; 1:; lis 6,-32704; mr 3,30; addi 6,6,-1824; addi 4,1,8; li 5,2; bl _s8023A604_4; cmpwi 3,0; ble 2f; li 4,62; mr 3,30; bl _s8023A604_5; addi 31,3,1; mr 4,31; li 3,0; bl _s8023A604_6; stw 3,0x0(29); 2:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s8023A604_0();
extern "C" void _s8023A604_1();
extern "C" void _s8023A604_2();
extern "C" void _s8023A604_3();
extern "C" void _s8023A604_4();
extern "C" void _s8023A604_5();
extern "C" void _s8023A604_6();
extern "C" void f_8023A604() {}
