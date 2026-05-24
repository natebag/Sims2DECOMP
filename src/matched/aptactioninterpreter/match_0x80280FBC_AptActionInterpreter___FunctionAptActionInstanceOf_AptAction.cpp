// 0x80280FBC AptActionInterpreter::_FunctionAptActionInstanceOf(AptActionInterpreter (560 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 31,3; lwz 29,0x0(31); cmpwi 29,1; bgt 2f; lwz 28,-22936(13); lis 4,-32704; lis 5,-32704; addi 4,4,5904; lwz 9,0x8(28); addi 5,5,5812; li 6,211; li 30,1; lha 3,0x8(9); lis 26,-32704; lwz 0,0xc(9); lis 27,-32704; add 3,28,3; b 1f; 0:; lwz 11,0x0(31); addi 4,26,5904; lwz 8,0x8(31); addi 5,27,5812; subf 11,30,11; li 6,220; rlwinm 11,11,2,0,29; addi 30,30,1; lwzx 10,11,8; lwz 9,0x8(10); lha 3,0x10(9); lwz 0,0x14(9); add 3,10,3; 1:; mtspr 8,0; blrl; cmpw 30,29; ble 0b; lwz 9,0x0(31); lwz 10,0x8(31); subf 9,29,9; rlwinm 9,9,2,0,29; stwx 28,9,10; lwz 11,0x0(31); addi 11,11,1; subf 11,29,11; b 8f; 2:; lwz 0,0x8(31); addi 9,29,-1; rlwinm 9,9,2,0,29; rlwinm 11,29,2,0,29; add 9,9,0; add 11,11,0; lwz 3,-4(11); lwz 4,-4(9); bl _s80280FBC_0; lwz 30,-26916(13); mr 28,3; cmpwi 30,0; beq 5f; lwz 0,0x0(30); lwz 9,0xc(30); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26916(13); stw 11,0x0(30); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 3f; rlwinm 0,11,0,3,1; stw 0,0x0(30); b 4f; 3:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 30,11,9; stw 0,0x4(8); 4:; stw 28,0xc(30); mr 29,30; b 6f; 5:; lwz 3,-23020(13); li 4,16; bl _s80280FBC_1; mr 30,3; li 4,5; mr 29,30; bl _s80280FBC_2; lis 9,-32702; stw 28,0xc(30); addi 9,9,-29224; stw 9,0x8(30); 6:; lwz 0,0x0(31); cmpwi 0,2; blt 9f; lwz 9,0x8(29); lis 4,-32704; lis 5,-32704; addi 4,4,5904; lha 3,0x8(9); addi 5,5,5812; lwz 0,0xc(9); li 6,211; add 3,29,3; li 30,1; mtspr 8,0; lis 26,-32704; lis 27,-32704; blrl; 7:; lwz 11,0x0(31); addi 4,26,5904; lwz 8,0x8(31); addi 5,27,5812; subf 11,30,11; li 6,220; rlwinm 11,11,2,0,29; addi 30,30,1; lwzx 10,11,8; lwz 9,0x8(10); lha 3,0x10(9); lwz 0,0x14(9); add 3,10,3; mtspr 8,0; blrl; cmpwi 30,2; ble 7b; lwz 9,0x0(31); lwz 10,0x8(31); addi 9,9,-2; rlwinm 9,9,2,0,29; stwx 29,9,10; lwz 11,0x0(31); addi 11,11,-1; 8:; stw 11,0x0(31); 9:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"

extern "C" void _s80280FBC_0();
extern "C" void _s80280FBC_1();
extern "C" void _s80280FBC_2();

struct AptActionInterpreter {
    void _FunctionAptActionInstanceOf_AptAction();
};

void AptActionInterpreter::_FunctionAptActionInstanceOf_AptAction() {
}
