// 0x80275728 AptActionInterpreter::_FunctionAptActionTrace(AptActionInterpreter (592 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); mr 29,3; lis 10,-32700; lwz 11,0x0(29); addi 8,10,-6476; lwz 0,0x8(29); li 31,0; lhz 9,-6476(10); rlwinm 11,11,2,0,29; add 11,11,0; lwz 28,-4(11); addi 9,9,1; sth 9,-6476(10); stw 8,0x8(1); bl _s80275728_0; cmpwi 3,7; bne 5f; lwz 0,0x0(28); andis. 9,0,2048; bne 5f; lwz 30,-26892(13); cmpwi 30,0; beq 3f; lwz 0,0x0(30); lwz 9,0x10(30); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26892(13); stw 11,0x0(30); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 0f; rlwinm 0,11,0,3,1; stw 0,0x0(30); b 1f; 0:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 30,11,9; stw 0,0x4(8); 1:; addi 31,30,12; mr 3,31; bl _s80275728_1; cmpwi 3,0; bne 2f; mr 3,31; li 4,0; bl _s80275728_2; 2:; mr 31,30; b 4f; 3:; lwz 3,-23020(13); li 4,20; bl _s80275728_3; bl _s80275728_4; mr 31,3; 4:; lis 9,-32694; addi 3,1,16; lwz 4,-10656(9); addi 30,31,12; addi 4,4,8; bl _s80275728_5; addi 4,1,16; mr 3,30; bl _s80275728_6; addi 3,1,16; li 4,2; bl _s80275728_7; mr 3,31; addi 4,1,8; bl _s80275728_8; 5:; cmpwi 31,0; bne 6f; mr 3,28; addi 4,1,8; bl _s80275728_9; 6:; addi 3,1,16; lis 4,-32704; mr 30,3; addi 4,4,7240; bl _s80275728_10; addi 4,1,8; mr 3,30; bl _s80275728_11; lis 4,-32704; mr 3,30; addi 4,4,7252; bl _s80275728_12; lis 9,-32694; lwz 4,0x10(1); lwz 0,-16268(9); lis 3,-32704; addi 3,3,7256; addi 4,4,8; mtspr 8,0; crxor 6,6,6; blrl; lwz 9,0x0(29); cmpwi 9,0; ble 7f; lwz 0,0x8(29); rlwinm 9,9,2,0,29; lis 4,-32704; lis 5,-32704; add 9,9,0; addi 4,4,5964; lwz 11,-4(9); addi 5,5,5812; li 6,160; lwz 9,0x8(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; lwz 9,0x0(29); addi 9,9,-1; stw 9,0x0(29); 7:; lwz 4,0x10(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 8f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80275728_13; 8:; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 9f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80275728_14; 9:; lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"

extern "C" void _s80275728_0();
extern "C" void _s80275728_1();
extern "C" void _s80275728_2();
extern "C" void _s80275728_3();
extern "C" void _s80275728_4();
extern "C" void _s80275728_5();
extern "C" void _s80275728_6();
extern "C" void _s80275728_7();
extern "C" void _s80275728_8();
extern "C" void _s80275728_9();
extern "C" void _s80275728_10();
extern "C" void _s80275728_11();
extern "C" void _s80275728_12();
extern "C" void _s80275728_13();
extern "C" void _s80275728_14();

struct AptActionInterpreter {
    void _FunctionAptActionTrace_AptActionInter();
};

void AptActionInterpreter::_FunctionAptActionTrace_AptActionInter() {
}
