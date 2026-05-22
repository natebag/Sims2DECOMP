// 0x800712A4 SimModel::GetChangedModels(int (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 25,0x1c(1); stw 0,0x3c(1); mr 29,3; mr. 31,4; li 3,0; beq 3f; mr 3,31; li 4,-1; li 5,104; mr 27,31; bl _s800712A4_0; li 25,0; li 31,0; addi 28,29,104; 0:; lwz 9,0x0(28); li 26,0; addi 28,28,4; cmpwi 9,0; beq 1f; lwz 9,0x120(9); cmpwi 9,0; beq 1f; lwz 26,0x8(9); 1:; lwz 4,0x13c(29); addi 3,1,8; mr 5,31; bl _s800712A4_1; lwz 3,0x13c(29); mr 4,31; lwz 30,0x138(29); bl _s800712A4_2; mr 5,3; mr 4,31; mr 3,30; addi 6,1,8; bl _s800712A4_3; cmpw 26,3; beq 2f; stw 3,0x0(27); li 25,1; 2:; addi 31,31,1; addi 27,27,4; cmplwi 31,25; ble 0b; mr 3,25; 3:; lwz 0,0x3c(1); mtspr 8,0; lmw 25,0x1c(1); addi 1,1,56"
extern "C" void _s800712A4_0();
extern "C" void _s800712A4_1();
extern "C" void _s800712A4_2();
extern "C" void _s800712A4_3();
extern "C" void f_800712A4() {}
