// 0x8027DF4C AptActionInterpreter::_FunctionAptActionGetUrl2(AptActionInterpreter (1160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 25,0x2c(1); stw 0,0x4c(1); mr 30,3; lis 28,-32700; lwz 11,0x0(30); mr 26,4; lwz 0,0x8(30); addi 4,1,16; addi 9,11,-1; lhz 10,-6476(28); rlwinm 9,9,2,0,29; rlwinm 11,11,2,0,29; add 9,9,0; add 11,11,0; lwz 3,-4(9); addi 10,10,2; lwz 29,-4(11); addi 27,28,-6476; mr 25,4; sth 10,-6476(28); stw 27,0x8(1); addi 31,1,8; stw 27,0x10(1); bl _s8027DF4C_0; lwz 4,0x10(1); mr 3,30; addi 4,4,8; bl _s8027DF4C_1; cmpwi 3,0; beq 0f; mr 4,31; mr 3,29; bl _s8027DF4C_2; lwz 4,0x10(1); mr 3,30; lwz 5,0x8(1); addi 4,4,8; addi 5,5,8; bl _s8027DF4C_3; b 19f; 0:; lwz 11,0x10(1); lhz 9,-6476(28); lhz 10,0x2(11); addi 9,9,1; stw 27,0x18(1); sth 9,-6476(28); cmpwi 10,0; beq 4f; addi 11,11,8; addi 0,10,-1; lbzx 9,11,0; extsb 9,9; cmpwi 9,102; beq 1f; cmpwi 9,70; bne 13f; 1:; addi 0,10,-2; lbzx 9,11,0; extsb 9,9; cmpwi 9,119; beq 2f; cmpwi 9,87; bne 13f; 2:; addi 0,10,-3; lbzx 9,11,0; extsb 9,9; cmpwi 9,115; beq 3f; cmpwi 9,83; bne 13f; 3:; addi 0,10,-4; lbzx 9,11,0; cmpwi 9,46; bne 13f; 4:; addi 4,1,8; mr 3,29; bl _s8027DF4C_4; lwz 11,0x10(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x18(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 5f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8027DF4C_5; 5:; lwz 9,0x10(1); addi 28,1,24; stw 9,0x18(1); lhz 4,0x2(9); cmpwi 4,3; ble 6f; addi 4,4,-4; mr 3,28; li 5,4; bl _s8027DF4C_6; 6:; lwz 5,0x8(26); li 9,0; lwz 4,0x4(26); mr 3,30; addi 6,1,8; li 7,1; li 8,1; bl _s8027DF4C_7; lwz 0,0x0(3); li 11,0; rlwinm 9,0,0,25,31; addi 9,9,-12; cmplwi 9,7; bgt 7f; rlwinm 11,0,5,31,31; 7:; cmpwi 11,0; beq 8f; addi 4,1,8; bl _s8027DF4C_8; 8:; lwz 0,0x0(30); addi 29,1,32; cmpwi 0,2; blt 10f; li 31,1; lis 26,-32704; lis 27,-32704; 9:; lwz 11,0x0(30); addi 4,26,6004; lwz 8,0x8(30); addi 5,27,5812; subf 11,31,11; li 6,180; rlwinm 11,11,2,0,29; addi 31,31,1; lwzx 10,11,8; lwz 9,0x8(10); lha 3,0x10(9); lwz 0,0x14(9); add 3,10,3; mtspr 8,0; blrl; cmpwi 31,2; ble 9b; lwz 9,0x0(30); addi 9,9,-2; stw 9,0x0(30); 10:; lwz 11,0x8(1); mr 4,28; lwz 3,-22996(13); mr 5,29; stw 11,0x20(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); bl _s8027DF4C_9; lwz 4,0x18(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 11f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8027DF4C_10; 11:; lwz 4,0x10(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 12f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8027DF4C_11; 12:; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 23f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8027DF4C_12; b 23f; 13:; lwz 0,0x0(29); li 11,0; mr 9,0; rlwinm 0,0,0,25,31; cmpwi 0,1; beq 14f; cmpwi 0,42; bne 15f; 14:; andis. 0,9,2048; beq 15f; li 11,1; 15:; cmpwi 11,0; beq 17f; rlwinm 0,9,0,25,31; lwz 4,0x4(26); cmpwi 0,1; lwz 5,0x8(26); mr 6,29; beq 16f; lwz 6,0x24(29); 16:; addi 6,6,12; mr 3,30; li 7,1; li 8,1; li 9,0; bl _s8027DF4C_13; b 18f; 17:; mr 3,29; 18:; mr 4,3; lwz 5,0x8(26); mr 6,25; mr 3,30; bl _s8027DF4C_14; lwz 4,0x18(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 19f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8027DF4C_15; 19:; lwz 0,0x0(30); cmpwi 0,2; blt 21f; li 31,1; lis 26,-32704; lis 27,-32704; 20:; lwz 11,0x0(30); addi 4,26,6004; lwz 8,0x8(30); addi 5,27,5812; subf 11,31,11; li 6,180; rlwinm 11,11,2,0,29; addi 31,31,1; lwzx 10,11,8; lwz 9,0x8(10); lha 3,0x10(9); lwz 0,0x14(9); add 3,10,3; mtspr 8,0; blrl; cmpwi 31,2; ble 20b; lwz 9,0x0(30); addi 9,9,-2; stw 9,0x0(30); 21:; lwz 4,0x10(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 22f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8027DF4C_16; 22:; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 23f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8027DF4C_17; 23:; lwz 0,0x4c(1); mtspr 8,0; lmw 25,0x2c(1); addi 1,1,72"

extern "C" void _s8027DF4C_0();
extern "C" void _s8027DF4C_1();
extern "C" void _s8027DF4C_2();
extern "C" void _s8027DF4C_3();
extern "C" void _s8027DF4C_4();
extern "C" void _s8027DF4C_5();
extern "C" void _s8027DF4C_6();
extern "C" void _s8027DF4C_7();
extern "C" void _s8027DF4C_8();
extern "C" void _s8027DF4C_9();
extern "C" void _s8027DF4C_10();
extern "C" void _s8027DF4C_11();
extern "C" void _s8027DF4C_12();
extern "C" void _s8027DF4C_13();
extern "C" void _s8027DF4C_14();
extern "C" void _s8027DF4C_15();
extern "C" void _s8027DF4C_16();
extern "C" void _s8027DF4C_17();

struct AptActionInterpreter {
    void _FunctionAptActionGetUrl2_AptActionInt();
};

void AptActionInterpreter::_FunctionAptActionGetUrl2_AptActionInt() {
}
