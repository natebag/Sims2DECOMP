// 0x8023A570 _ParseNumChildNodes(unsigned (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,3; li 31,0; bl _s8023A570_0; mr. 3,3; beq 2f; li 31,1; b 1f; 0:; addi 31,31,1; 1:; bl _s8023A570_1; mr. 3,3; beq 3f; lbz 0,0x0(3); cmpwi 0,60; bne 0b; lbz 0,0x1(3); cmpwi 0,47; bne 0b; b 3f; 2:; lis 6,-32704; mr 3,30; addi 6,6,-1824; addi 4,1,8; li 5,2; bl _s8023A570_2; cmpwi 3,0; ble 3f; li 31,1; 3:; mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s8023A570_0();
extern "C" void _s8023A570_1();
extern "C" void _s8023A570_2();
extern "C" void f_8023A570() {}
