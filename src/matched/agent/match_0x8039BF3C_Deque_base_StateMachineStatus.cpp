// 0x8039BF3C _Deque_base<StateMachineStatus (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 26,0x10(1); stw 0,0x2c(1); mr 26,4; li 0,8; rlwinm 9,26,27,5,31; stw 0,0x8(1); addi 30,9,1; mr 31,3; addi 9,9,3; cmplw 0,9; stw 9,0xc(1); addi 0,1,12; addi 9,1,8; bge 0f; mr 9,0; 0:; lwz 3,0x0(9); stw 3,0x2c(31); cmpwi 3,0; beq 2f; rlwinm 3,3,2,0,29; cmplwi 3,128; ble 1f; bl _s8039BF3C_0; mr 27,3; b 3f; 1:; bl _s8039BF3C_1; mr 27,3; b 3f; 2:; li 27,0; 3:; lwz 29,0x2c(31); rlwinm 28,30,2,0,29; stw 27,0x24(31); mr 3,31; subf 29,30,29; rlwinm 29,29,1,0,29; add 30,27,29; add 28,30,28; mr 4,30; mr 5,28; bl _s8039BF3C_2; stw 30,0xc(31); addi 10,31,16; addi 11,28,-4; rlwinm 8,26,2,25,29; lwzx 9,27,29; addi 0,9,128; stw 9,0x4(31); stw 0,0x8(31); stw 11,0xc(10); lwz 9,-4(28); addi 11,9,128; stw 9,0x4(10); stw 11,0x8(10); lwz 0,0x14(31); lwz 9,0x4(31); add 0,0,8; stw 0,0x10(31); stw 9,0x0(31); lwz 0,0x2c(1); mtspr 8,0; lmw 26,0x10(1); addi 1,1,40"
extern "C" void _s8039BF3C_0();
extern "C" void _s8039BF3C_1();
extern "C" void _s8039BF3C_2();
extern "C" void f_8039BF3C() {}
