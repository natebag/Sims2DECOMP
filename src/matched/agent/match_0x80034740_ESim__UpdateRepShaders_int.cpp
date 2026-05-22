// 0x80034740 ESim::UpdateRepShaders(int) (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-568(1); mfspr 0,8; stmw 28,0x228(1); stw 0,0x23c(1); mr 29,3; mr 28,4; addi 3,1,8; li 30,0; bl _s80034740_0; li 31,0; mr 3,29; bl _s80034740_1; mr 4,3; addi 3,1,8; bl _s80034740_2; 0:; lwz 9,0x63c(29); lwzx 0,31,9; andi. 11,0,16; beq 1f; addi 9,9,104; addi 3,1,8; lwzx 5,9,31; mr 4,30; bl _s80034740_3; 1:; addi 30,30,1; addi 31,31,4; cmpwi 30,25; ble 0b; mr 4,28; addi 3,1,8; bl _s80034740_4; addi 3,1,8; li 4,2; bl _s80034740_5; lwz 0,0x23c(1); mtspr 8,0; lmw 28,0x228(1); addi 1,1,568"
extern "C" void _s80034740_0();
extern "C" void _s80034740_1();
extern "C" void _s80034740_2();
extern "C" void _s80034740_3();
extern "C" void _s80034740_4();
extern "C" void _s80034740_5();
extern "C" void f_80034740() {}
