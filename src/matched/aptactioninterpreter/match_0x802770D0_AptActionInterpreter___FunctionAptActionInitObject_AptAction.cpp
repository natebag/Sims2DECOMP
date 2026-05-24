// 0x802770D0 AptActionInterpreter::_FunctionAptActionInitObject(AptActionInterpreter (788 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 22,0x10(1); stw 0,0x3c(1); mr 31,3; mr 29,4; lwz 9,0x0(31); lis 23,-32704; lwz 0,0x8(31); rlwinm 9,9,2,0,29; add 9,9,0; lwz 3,-4(9); bl _s802770D0_0; lwz 9,0x0(31); mr 30,3; cmpwi 9,0; ble 0f; lwz 0,0x8(31); rlwinm 9,9,2,0,29; lis 4,-32704; addi 5,23,5812; add 9,9,0; addi 4,4,5964; lwz 11,-4(9); li 6,160; lwz 9,0x8(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; lwz 9,0x0(31); addi 9,9,-1; stw 9,0x0(31); 0:; lis 6,-32694; lwz 5,0x8(29); addi 6,6,-11332; lwz 4,0x4(29); addi 6,6,400; mr 3,31; li 7,0; li 8,1; bl _s802770D0_1; mr. 26,3; beq 7f; li 28,0; cmpwi 30,0; add 25,30,30; ble 3f; lis 24,-32700; mr 29,30; addi 22,24,-6476; addi 27,1,8; 1:; lwz 11,0x0(31); addi 9,28,1; lwz 0,0x8(31); mr 4,27; subf 9,9,11; lhz 10,-6476(24); subf 11,28,11; rlwinm 9,9,2,0,29; rlwinm 11,11,2,0,29; add 9,9,0; add 11,11,0; lwz 3,-4(9); lwz 30,-4(11); addi 10,10,1; sth 10,-6476(24); stw 22,0x8(1); bl _s802770D0_2; mr 4,27; mr 5,30; addi 3,26,12; bl _s802770D0_3; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 2f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802770D0_4; 2:; addi 28,28,2; addic. 29,29,-1; bne 1b; 3:; lwz 0,0x0(31); cmpw 0,25; blt 6f; li 30,1; cmpw 30,25; bgt 5f; lis 29,-32704; 4:; lwz 11,0x0(31); addi 4,29,6004; lwz 8,0x8(31); addi 5,23,5812; subf 11,30,11; li 6,180; rlwinm 11,11,2,0,29; addi 30,30,1; lwzx 10,11,8; lwz 9,0x8(10); lha 3,0x10(9); lwz 0,0x14(9); add 3,10,3; mtspr 8,0; blrl; cmpw 30,25; ble 4b; 5:; lwz 0,0x0(31); subf 0,25,0; stw 0,0x0(31); 6:; lwz 9,0x0(31); lis 4,-32704; lwz 10,0x8(31); lis 5,-32704; rlwinm 11,9,2,0,29; addi 4,4,5760; stwx 26,11,10; addi 9,9,1; stw 9,0x0(31); addi 5,5,5812; li 6,138; lwz 9,0x8(26); lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,26,3; blrl; lwz 9,0x8(26); lis 4,-32704; lis 5,-32704; addi 4,4,7928; lha 3,0x10(9); addi 5,5,6212; lwz 0,0x14(9); li 6,5443; add 3,26,3; mtspr 8,0; blrl; b 11f; 7:; add 29,30,30; cmpwi 29,0; ble 10f; lwz 0,0x0(31); cmpw 0,29; blt 10f; li 30,1; cmpw 30,29; bgt 9f; lis 28,-32704; 8:; lwz 11,0x0(31); addi 4,28,6048; lwz 8,0x8(31); addi 5,23,5812; subf 11,30,11; li 6,251; rlwinm 11,11,2,0,29; addi 30,30,1; lwzx 10,11,8; lwz 9,0x8(10); lha 3,0x10(9); lwz 0,0x14(9); add 3,10,3; mtspr 8,0; blrl; cmpw 30,29; ble 8b; 9:; lwz 0,0x0(31); subf 0,29,0; stw 0,0x0(31); 10:; lwz 9,0x0(31); lis 4,-32704; lwz 10,-22936(13); lis 5,-32704; lwz 8,0x8(31); rlwinm 11,9,2,0,29; addi 9,9,1; addi 4,4,5760; stwx 10,11,8; addi 5,5,5812; stw 9,0x0(31); li 6,138; lwz 9,0x8(10); lha 3,0x8(9); lwz 0,0xc(9); add 3,10,3; mtspr 8,0; blrl; 11:; lwz 0,0x3c(1); mtspr 8,0; lmw 22,0x10(1); addi 1,1,56"

extern "C" void _s802770D0_0();
extern "C" void _s802770D0_1();
extern "C" void _s802770D0_2();
extern "C" void _s802770D0_3();
extern "C" void _s802770D0_4();

struct AptActionInterpreter {
    void _FunctionAptActionInitObject_AptAction();
};

void AptActionInterpreter::_FunctionAptActionInitObject_AptAction() {
}
