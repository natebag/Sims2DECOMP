// 0x8027554C AptActionInterpreter::_FunctionAptActionCloneSprite(AptActionInterpreter (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 28,4; lwz 9,0x0(31); lwz 0,0x8(31); addi 11,9,-2; rlwinm 10,9,2,0,29; addi 9,9,-1; add 10,10,0; rlwinm 9,9,2,0,29; rlwinm 11,11,2,0,29; add 9,9,0; add 11,11,0; lwz 3,-4(10); lwz 29,-4(9); lwz 30,-4(11); bl _s8027554C_0; mr 8,3; lwz 5,0x8(28); lwz 4,0x4(28); mr 6,30; mr 7,29; mr 3,31; li 9,0; bl _s8027554C_1; lwz 0,0x0(31); cmpwi 0,3; blt 1f; li 30,1; lis 28,-32704; lis 29,-32704; 0:; lwz 11,0x0(31); addi 4,28,6004; lwz 8,0x8(31); addi 5,29,5812; subf 11,30,11; li 6,180; rlwinm 11,11,2,0,29; addi 30,30,1; lwzx 10,11,8; lwz 9,0x8(10); lha 3,0x10(9); lwz 0,0x14(9); add 3,10,3; mtspr 8,0; blrl; cmpwi 30,3; ble 0b; lwz 9,0x0(31); addi 9,9,-3; stw 9,0x0(31); 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8027554C_0();
extern "C" void _s8027554C_1();
extern "C" void f_8027554C() {}
