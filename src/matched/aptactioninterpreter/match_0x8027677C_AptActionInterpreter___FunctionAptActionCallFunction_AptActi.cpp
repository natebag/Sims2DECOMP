// 0x8027677C AptActionInterpreter::_FunctionAptActionCallFunction(AptActionInterpreter (576 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 25,0x1c(1); stw 0,0x3c(1); mr 30,3; lis 8,-32700; lwz 11,0x0(30); addi 7,8,-6476; lwz 0,0x8(30); mr 28,4; addi 9,11,-1; lhz 10,-6476(8); rlwinm 9,9,2,0,29; rlwinm 11,11,2,0,29; add 9,9,0; add 11,11,0; lwz 31,-4(11); addi 10,10,1; lwz 3,-4(9); li 29,0; sth 10,-6476(8); stw 7,0x8(1); bl _s8027677C_0; lwz 9,0x0(31); mr 25,3; stw 29,0x10(1); li 11,0; rlwinm 0,9,0,25,31; cmpwi 0,22; bne 0f; rlwinm 11,9,5,31,31; 0:; cmpwi 11,0; beq 1f; mr 3,31; li 4,0; bl _s8027677C_1; mr 31,3; 1:; lwz 0,0x0(31); li 11,0; mr 9,0; rlwinm 0,0,0,25,31; cmpwi 0,1; beq 2f; cmpwi 0,42; bne 3f; 2:; andis. 0,9,2048; beq 3f; li 11,1; 3:; cmpwi 11,0; beq 5f; rlwinm 0,9,0,25,31; lwz 3,0x4(28); cmpwi 0,1; lwz 4,0x8(28); mr 5,31; beq 4f; lwz 5,0x24(31); 4:; addi 6,1,16; addi 7,1,8; addi 5,5,12; bl _s8027677C_2; lwz 4,0x10(1); mr 3,30; lwz 5,0x8(28); addi 6,1,8; li 7,1; li 8,1; li 9,0; bl _s8027677C_3; mr 29,3; b 6f; 5:; mr 29,31; 6:; lwz 9,0x8(29); lis 4,-32704; lis 5,-32704; addi 4,4,7540; lwz 0,0xc(9); addi 5,5,6212; lha 3,0x8(9); li 6,5116; mtspr 8,0; add 3,29,3; blrl; lwz 0,0x0(30); cmpwi 0,2; blt 8f; li 31,1; lis 26,-32704; lis 27,-32704; 7:; lwz 11,0x0(30); addi 4,26,6004; lwz 8,0x8(30); addi 5,27,5812; subf 11,31,11; li 6,180; rlwinm 11,11,2,0,29; addi 31,31,1; lwzx 10,11,8; lwz 9,0x8(10); lha 3,0x10(9); lwz 0,0x14(9); add 3,10,3; mtspr 8,0; blrl; cmpwi 31,2; ble 7b; lwz 9,0x0(30); addi 9,9,-2; stw 9,0x0(30); 8:; lwz 4,0x10(1); cmpwi 4,0; bne 9f; lwz 4,0x4(28); 9:; mr 3,30; mr 5,29; mr 6,25; bl _s8027677C_4; lwz 9,0x8(29); lis 4,-32704; lis 5,-32704; addi 4,4,7540; lwz 0,0x14(9); addi 5,5,6212; lha 3,0x10(9); li 6,5144; mtspr 8,0; add 3,29,3; blrl; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 10f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8027677C_5; 10:; lwz 0,0x3c(1); mtspr 8,0; lmw 25,0x1c(1); addi 1,1,56"

extern "C" void _s8027677C_0();
extern "C" void _s8027677C_1();
extern "C" void _s8027677C_2();
extern "C" void _s8027677C_3();
extern "C" void _s8027677C_4();
extern "C" void _s8027677C_5();

struct AptActionInterpreter {
    void _FunctionAptActionCallFunction_AptActi();
};

void AptActionInterpreter::_FunctionAptActionCallFunction_AptActi() {
}
