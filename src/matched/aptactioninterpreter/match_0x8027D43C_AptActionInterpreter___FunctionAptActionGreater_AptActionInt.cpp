// 0x8027D43C AptActionInterpreter::_FunctionAptActionGreater(AptActionInterpreter (924 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stfd f31,0x28(1); stmw 27,0x14(1); stw 0,0x34(1); mr 31,3; lwz 9,0x0(31); lwz 0,0x8(31); addi 11,9,-1; rlwinm 9,9,2,0,29; rlwinm 11,11,2,0,29; add 9,9,0; add 11,11,0; lwz 29,-4(9); lwz 30,-4(11); bl _s8027D43C_0; cmpwi 3,7; bne 3f; lwz 0,0x0(29); andis. 9,0,2048; beq 0f; lwz 0,0x0(30); andis. 9,0,2048; bne 3f; 0:; lwz 0,0x0(31); lis 27,-32704; cmpwi 0,2; blt 2f; li 30,1; lis 29,-32704; 1:; lwz 11,0x0(31); addi 4,29,6004; lwz 8,0x8(31); addi 5,27,5812; subf 11,30,11; li 6,180; rlwinm 11,11,2,0,29; addi 30,30,1; lwzx 10,11,8; lwz 9,0x8(10); lha 3,0x10(9); lwz 0,0x14(9); add 3,10,3; mtspr 8,0; blrl; cmpwi 30,2; ble 1b; lwz 9,0x0(31); addi 9,9,-2; stw 9,0x0(31); 2:; lwz 9,0x0(31); lis 4,-32704; lwz 10,-22936(13); lis 5,-32704; lwz 8,0x8(31); rlwinm 11,9,2,0,29; addi 9,9,1; addi 4,4,5760; stwx 10,11,8; addi 5,5,5812; stw 9,0x0(31); li 6,138; lwz 9,0x8(10); lha 3,0x8(9); lwz 0,0xc(9); add 3,10,3; mtspr 8,0; blrl; b 22f; 3:; lwz 0,0x0(29); li 11,0; mr 9,0; rlwinm 0,0,0,25,31; cmpwi 0,1; beq 4f; cmpwi 0,42; bne 5f; 4:; andis. 0,9,2048; beq 5f; li 11,1; 5:; cmpwi 11,0; beq 10f; lwz 0,0x0(30); li 10,0; mr 11,0; rlwinm 0,0,0,25,31; cmpwi 0,1; beq 6f; cmpwi 0,42; bne 7f; 6:; andis. 0,11,2048; beq 7f; li 10,1; 7:; cmpwi 10,0; beq 10f; rlwinm 0,9,0,25,31; mr 9,29; cmpwi 0,1; beq 8f; lwz 9,0x24(29); 8:; lwz 9,0xc(9); rlwinm 0,11,0,25,31; cmpwi 0,1; mr 11,30; addi 3,9,8; beq 9f; lwz 11,0x24(30); 9:; lwz 4,0xc(11); addi 4,4,8; bl _s8027D43C_1; rlwinm 3,3,1,31,31; b 15f; 10:; rlwinm 0,9,0,25,31; li 11,0; cmpwi 0,6; bne 11f; rlwinm 11,9,5,31,31; 11:; cmpwi 11,0; bne 13f; lwz 9,0x0(30); li 11,0; rlwinm 0,9,0,25,31; cmpwi 0,6; bne 12f; rlwinm 11,9,5,31,31; 12:; cmpwi 11,0; beq 14f; 13:; mr 3,30; bl _s8027D43C_2; fmr f31,f1; mr 3,29; bl _s8027D43C_3; fcmpu 7,f31,f1; mfcr 3; rlwinm 3,3,30,31,31; b 15f; 14:; mr 3,30; bl _s8027D43C_4; mr 30,3; mr 3,29; bl _s8027D43C_5; cmpw cr7,30,3; mfcr 3; rlwinm 3,3,30,31,31; 15:; cmpwi 3,0; li 28,1; bne 16f; li 28,0; 16:; lwz 30,-26916(13); cmpwi 30,0; beq 19f; lwz 0,0x0(30); lwz 9,0xc(30); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26916(13); stw 11,0x0(30); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 17f; rlwinm 0,11,0,3,1; stw 0,0x0(30); b 18f; 17:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 30,11,9; stw 0,0x4(8); 18:; stw 28,0xc(30); mr 29,30; b 20f; 19:; lwz 3,-23020(13); li 4,16; bl _s8027D43C_6; mr 30,3; li 4,5; mr 29,30; bl _s8027D43C_7; lis 9,-32702; stw 28,0xc(30); addi 9,9,-29224; stw 9,0x8(30); 20:; lwz 0,0x0(31); cmpwi 0,2; blt 22f; lwz 9,0x8(29); lis 4,-32704; lis 5,-32704; addi 4,4,5904; lha 3,0x8(9); addi 5,5,5812; lwz 0,0xc(9); li 6,211; add 3,29,3; li 30,1; mtspr 8,0; lis 27,-32704; lis 28,-32704; blrl; 21:; lwz 11,0x0(31); addi 4,28,5904; lwz 8,0x8(31); addi 5,27,5812; subf 11,30,11; li 6,220; rlwinm 11,11,2,0,29; addi 30,30,1; lwzx 10,11,8; lwz 9,0x8(10); lha 3,0x10(9); lwz 0,0x14(9); add 3,10,3; mtspr 8,0; blrl; cmpwi 30,2; ble 21b; lwz 9,0x0(31); lwz 10,0x8(31); addi 9,9,-2; rlwinm 9,9,2,0,29; stwx 29,9,10; lwz 11,0x0(31); addi 11,11,-1; stw 11,0x0(31); 22:; lwz 0,0x34(1); mtspr 8,0; lmw 27,0x14(1); lfd f31,0x28(1); addi 1,1,48"

extern "C" void _s8027D43C_0();
extern "C" void _s8027D43C_1();
extern "C" void _s8027D43C_2();
extern "C" void _s8027D43C_3();
extern "C" void _s8027D43C_4();
extern "C" void _s8027D43C_5();
extern "C" void _s8027D43C_6();
extern "C" void _s8027D43C_7();

struct AptActionInterpreter {
    void _FunctionAptActionGreater_AptActionInt();
};

void AptActionInterpreter::_FunctionAptActionGreater_AptActionInt() {
}
