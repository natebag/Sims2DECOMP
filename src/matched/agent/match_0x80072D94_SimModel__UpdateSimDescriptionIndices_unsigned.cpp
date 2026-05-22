// 0x80072D94 SimModel::UpdateSimDescriptionIndices(unsigned (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 27,0x24(1); stw 0,0x3c(1); mr 27,3; mr. 4,4; beq 2f; mr 28,4; li 29,0; 0:; lwz 31,0x0(28); addi 28,28,4; cmpwi 31,0; beq 1f; lwz 4,0x13c(27); addi 3,1,8; addi 30,1,24; mr 5,29; bl _s80072D94_0; lwz 3,0x138(27); mr 5,31; mr 4,29; addi 6,1,8; mr 7,30; bl _s80072D94_1; cmpwi 3,0; beq 1f; lbz 5,0x3(30); mr 4,29; lwz 3,0x13c(27); extsb 5,5; bl _s80072D94_2; 1:; addi 29,29,1; cmpwi 29,25; ble 0b; 2:; lwz 0,0x3c(1); mtspr 8,0; lmw 27,0x24(1); addi 1,1,56"
extern "C" void _s80072D94_0();
extern "C" void _s80072D94_1();
extern "C" void _s80072D94_2();
extern "C" void f_80072D94() {}
