// 0x80273D40 AptActionInterpreter::_FunctionAptActionOr(AptActionInterpreter (656 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stfd f31,0x28(1); stmw 27,0x14(1); stw 0,0x34(1); mr 29,3; li 28,0; lwz 9,0x0(29); lwz 0,0x8(29); addi 11,9,-1; rlwinm 9,9,2,0,29; rlwinm 11,11,2,0,29; add 9,9,0; add 11,11,0; lwz 30,-4(9); lwz 31,-4(11); bl _s80273D40_0; cmpwi 3,7; bne 1f; lwz 0,0x0(30); andis. 9,0,2048; beq 0f; lwz 0,0x0(31); andis. 9,0,2048; bne 1f; 0:; lwz 28,-22936(13); 1:; cmpwi 28,0; bne 13f; lwz 9,0x0(30); li 11,0; rlwinm 0,9,0,25,31; cmpwi 0,7; bne 2f; rlwinm 11,9,5,31,31; 2:; cmpwi 11,0; beq 6f; lwz 9,0x0(31); li 11,0; rlwinm 0,9,0,25,31; cmpwi 0,7; bne 3f; rlwinm 11,9,5,31,31; 3:; cmpwi 11,0; beq 6f; lwz 0,0xc(30); li 27,0; lwz 3,0xc(31); cmpwi 0,0; bne 4f; cmpwi 3,0; beq 5f; 4:; li 27,1; 5:; lwz 30,-26916(13); cmpwi 30,0; beq 12f; lwz 0,0x0(30); lwz 9,0xc(30); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26916(13); stw 11,0x0(30); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; bge 9f; b 10f; 6:; mr 3,30; li 27,0; bl _s80273D40_1; fmr f31,f1; mr 3,31; bl _s80273D40_2; fmr f0,f1; lis 9,-32704; lfs f1,0x1bc4(9); fcmpu 0,f31,f1; bne 7f; fcmpu 0,f0,f1; beq 8f; 7:; li 27,1; 8:; lwz 30,-26916(13); cmpwi 30,0; beq 12f; lwz 0,0x0(30); lwz 9,0xc(30); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26916(13); stw 11,0x0(30); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 10f; 9:; rlwinm 0,11,0,3,1; stw 0,0x0(30); b 11f; 10:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 30,11,9; stw 0,0x4(8); 11:; stw 27,0xc(30); mr 28,30; b 13f; 12:; lwz 3,-23020(13); li 4,16; bl _s80273D40_3; mr 30,3; li 4,5; mr 28,30; bl _s80273D40_4; lis 9,-32702; stw 27,0xc(30); addi 9,9,-29224; stw 9,0x8(30); 13:; lwz 0,0x0(29); lis 31,-32704; cmpwi 0,2; blt 15f; li 30,1; lis 27,-32704; 14:; lwz 11,0x0(29); addi 4,27,6004; lwz 8,0x8(29); addi 5,31,5812; subf 11,30,11; li 6,180; rlwinm 11,11,2,0,29; addi 30,30,1; lwzx 10,11,8; lwz 9,0x8(10); lha 3,0x10(9); lwz 0,0x14(9); add 3,10,3; mtspr 8,0; blrl; cmpwi 30,2; ble 14b; lwz 9,0x0(29); addi 9,9,-2; stw 9,0x0(29); 15:; lwz 9,0x0(29); lis 4,-32704; lwz 10,0x8(29); lis 5,-32704; rlwinm 11,9,2,0,29; addi 4,4,5760; stwx 28,11,10; addi 9,9,1; stw 9,0x0(29); addi 5,5,5812; li 6,138; lwz 9,0x8(28); lha 3,0x8(9); lwz 0,0xc(9); add 3,28,3; mtspr 8,0; blrl; lwz 0,0x34(1); mtspr 8,0; lmw 27,0x14(1); lfd f31,0x28(1); addi 1,1,48"

extern "C" void _s80273D40_0();
extern "C" void _s80273D40_1();
extern "C" void _s80273D40_2();
extern "C" void _s80273D40_3();
extern "C" void _s80273D40_4();

struct AptActionInterpreter {
    void _FunctionAptActionOr_AptActionInterpre();
};

void AptActionInterpreter::_FunctionAptActionOr_AptActionInterpre() {
}
