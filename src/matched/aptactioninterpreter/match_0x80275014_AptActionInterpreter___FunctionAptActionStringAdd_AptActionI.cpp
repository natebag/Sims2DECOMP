// 0x80275014 AptActionInterpreter::_FunctionAptActionStringAdd(AptActionInterpreter (508 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 25,0x14(1); stw 0,0x34(1); mr 29,3; lwz 9,0x0(29); lwz 0,0x8(29); addi 11,9,-1; rlwinm 9,9,2,0,29; rlwinm 11,11,2,0,29; add 9,9,0; add 11,11,0; lwz 28,-4(9); lwz 27,-4(11); bl _s80275014_0; mr 26,28; mr 25,27; cmpwi 3,7; bne 6f; lwz 30,-26892(13); cmpwi 30,0; beq 3f; lwz 0,0x0(30); lwz 9,0x10(30); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26892(13); stw 11,0x0(30); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 0f; rlwinm 0,11,0,3,1; stw 0,0x0(30); b 1f; 0:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 30,11,9; stw 0,0x4(8); 1:; addi 31,30,12; mr 3,31; bl _s80275014_1; cmpwi 3,0; bne 2f; mr 3,31; li 4,0; bl _s80275014_2; 2:; mr 31,30; b 4f; 3:; lwz 3,-23020(13); li 4,20; bl _s80275014_3; bl _s80275014_4; mr 31,3; 4:; lis 9,-32694; addi 3,1,8; lwz 4,-10656(9); addi 30,31,12; addi 4,4,8; bl _s80275014_5; addi 4,1,8; mr 3,30; bl _s80275014_6; addi 3,1,8; li 4,2; bl _s80275014_7; lwz 0,0x0(26); andis. 9,0,2048; bne 5f; mr 28,31; 5:; lwz 0,0x0(25); andis. 9,0,2048; bne 6f; mr 27,31; 6:; mr 3,28; mr 4,27; bl _s80275014_8; lis 28,-32704; lwz 0,0x0(29); mr 31,3; cmpwi 0,2; blt 8f; li 30,1; lis 27,-32704; 7:; lwz 11,0x0(29); addi 4,27,6004; lwz 8,0x8(29); addi 5,28,5812; subf 11,30,11; li 6,180; rlwinm 11,11,2,0,29; addi 30,30,1; lwzx 10,11,8; lwz 9,0x8(10); lha 3,0x10(9); lwz 0,0x14(9); add 3,10,3; mtspr 8,0; blrl; cmpwi 30,2; ble 7b; lwz 9,0x0(29); addi 9,9,-2; stw 9,0x0(29); 8:; lwz 9,0x0(29); lis 4,-32704; lwz 10,0x8(29); lis 5,-32704; rlwinm 11,9,2,0,29; addi 4,4,5760; stwx 31,11,10; addi 9,9,1; stw 9,0x0(29); addi 5,5,5812; li 6,138; lwz 9,0x8(31); lha 3,0x8(9); lwz 0,0xc(9); add 3,31,3; mtspr 8,0; blrl; lwz 0,0x34(1); mtspr 8,0; lmw 25,0x14(1); addi 1,1,48"

extern "C" void _s80275014_0();
extern "C" void _s80275014_1();
extern "C" void _s80275014_2();
extern "C" void _s80275014_3();
extern "C" void _s80275014_4();
extern "C" void _s80275014_5();
extern "C" void _s80275014_6();
extern "C" void _s80275014_7();
extern "C" void _s80275014_8();

struct AptActionInterpreter {
    void _FunctionAptActionStringAdd_AptActionI();
};

void AptActionInterpreter::_FunctionAptActionStringAdd_AptActionI() {
}
