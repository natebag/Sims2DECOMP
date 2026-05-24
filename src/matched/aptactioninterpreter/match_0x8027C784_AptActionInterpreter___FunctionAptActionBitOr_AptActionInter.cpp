// 0x8027C784 AptActionInterpreter::_FunctionAptActionBitOr(AptActionInterpreter (460 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,3; li 29,0; lwz 9,0x0(31); lwz 0,0x8(31); addi 11,9,-1; rlwinm 9,9,2,0,29; rlwinm 11,11,2,0,29; add 9,9,0; add 11,11,0; lwz 30,-4(9); lwz 28,-4(11); bl _s8027C784_0; cmpwi 3,7; bne 1f; lwz 0,0x0(30); andis. 9,0,2048; beq 0f; lwz 0,0x0(28); andis. 9,0,2048; bne 1f; 0:; lwz 29,-22936(13); 1:; cmpwi 29,0; bne 5f; mr 3,30; bl _s8027C784_1; mr 30,3; mr 3,28; bl _s8027C784_2; or 28,30,3; lwz 30,-26908(13); cmpwi 30,0; beq 4f; lwz 0,0x0(30); lwz 9,0xc(30); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26908(13); stw 11,0x0(30); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 2f; rlwinm 0,11,0,3,1; stw 0,0x0(30); b 3f; 2:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 30,11,9; stw 0,0x4(8); 3:; stw 28,0xc(30); mr 29,30; b 5f; 4:; lwz 3,-23020(13); li 4,16; bl _s8027C784_3; mr 30,3; li 4,7; mr 29,30; bl _s8027C784_4; lis 9,-32702; stw 28,0xc(30); addi 9,9,-24344; stw 9,0x8(30); 5:; lwz 0,0x0(31); cmpwi 0,2; blt 7f; lwz 9,0x8(29); lis 4,-32704; lis 5,-32704; addi 4,4,5904; lha 3,0x8(9); addi 5,5,5812; lwz 0,0xc(9); li 6,211; add 3,29,3; li 30,1; mtspr 8,0; lis 27,-32704; lis 28,-32704; blrl; 6:; lwz 11,0x0(31); addi 4,27,5904; lwz 8,0x8(31); addi 5,28,5812; subf 11,30,11; li 6,220; rlwinm 11,11,2,0,29; addi 30,30,1; lwzx 10,11,8; lwz 9,0x8(10); lha 3,0x10(9); lwz 0,0x14(9); add 3,10,3; mtspr 8,0; blrl; cmpwi 30,2; ble 6b; lwz 9,0x0(31); lwz 10,0x8(31); addi 9,9,-2; rlwinm 9,9,2,0,29; stwx 29,9,10; lwz 11,0x0(31); addi 11,11,-1; stw 11,0x0(31); 7:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s8027C784_0();
extern "C" void _s8027C784_1();
extern "C" void _s8027C784_2();
extern "C" void _s8027C784_3();
extern "C" void _s8027C784_4();

struct AptActionInterpreter {
    void _FunctionAptActionBitOr_AptActionInter();
};

void AptActionInterpreter::_FunctionAptActionBitOr_AptActionInter() {
}
