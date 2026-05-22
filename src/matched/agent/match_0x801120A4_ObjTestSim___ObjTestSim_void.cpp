// 0x801120A4 ObjTestSim::~ObjTestSim(void) (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,3; mr 28,4; lwz 0,0x18(29); cmpwi 0,0; beq 1f; li 30,0; addi 31,29,8; 0:; lwz 9,0x18(29); mr 4,30; lhz 5,0x0(31); addi 30,30,1; lwz 11,0x0(9); addi 31,31,2; extsh 5,5; lwz 9,0x4(11); lha 3,0x1f0(9); lwz 0,0x1f4(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 30,7; ble 0b; li 0,0; stw 0,0x18(29); 1:; andi. 0,28,1; beq 2f; mr 3,29; bl _s801120A4_0; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s801120A4_0();
extern "C" void f_801120A4() {}
