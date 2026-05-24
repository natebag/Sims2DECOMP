// 0x80276F24 AptActionInterpreter::_FunctionAptActionInitArray(AptActionInterpreter (428 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 31,3; lwz 9,0x0(31); lwz 0,0x8(31); rlwinm 9,9,2,0,29; add 9,9,0; lwz 3,-4(9); bl _s80276F24_0; lwz 9,0x0(31); mr 29,3; cmpwi 9,0; ble 0f; lwz 0,0x8(31); rlwinm 9,9,2,0,29; lis 4,-32704; lis 5,-32704; add 9,9,0; addi 4,4,5964; lwz 11,-4(9); addi 5,5,5812; li 6,160; lwz 9,0x8(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; lwz 9,0x0(31); addi 9,9,-1; stw 9,0x0(31); 0:; cmpwi 29,0; lwz 3,-23016(13); li 4,48; mfcr 27; bl _s80276F24_1; li 30,0; bl _s80276F24_2; mr 28,3; lis 4,-32704; lwz 9,0x8(28); lis 5,-32704; addi 4,4,7800; addi 5,5,6212; lha 3,0x8(9); li 6,5372; lwz 0,0xc(9); add 3,28,3; mtspr 8,0; blrl; cmpw 30,29; bge 2f; 1:; lwz 9,0x0(31); mr 4,30; lwz 0,0x8(31); mr 3,28; subf 9,30,9; rlwinm 9,9,2,0,29; addi 30,30,1; add 9,9,0; lwz 5,-4(9); bl _s80276F24_3; cmpw 30,29; blt 1b; 2:; mtcrf 128,27; ble 5f; lwz 0,0x0(31); cmpw 0,29; blt 5f; li 30,1; cmpw 30,29; bgt 4f; lis 26,-32704; lis 27,-32704; 3:; lwz 11,0x0(31); addi 4,26,6048; lwz 8,0x8(31); addi 5,27,5812; subf 11,30,11; li 6,251; rlwinm 11,11,2,0,29; addi 30,30,1; lwzx 10,11,8; lwz 9,0x8(10); lha 3,0x10(9); lwz 0,0x14(9); add 3,10,3; mtspr 8,0; blrl; cmpw 30,29; ble 3b; 4:; lwz 0,0x0(31); subf 0,29,0; stw 0,0x0(31); 5:; lwz 9,0x0(31); lwz 10,0x8(31); rlwinm 11,9,2,0,29; stwx 28,11,10; addi 9,9,1; stw 9,0x0(31); lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"

extern "C" void _s80276F24_0();
extern "C" void _s80276F24_1();
extern "C" void _s80276F24_2();
extern "C" void _s80276F24_3();

struct AptActionInterpreter {
    void _FunctionAptActionInitArray_AptActionI();
};

void AptActionInterpreter::_FunctionAptActionInitArray_AptActionI() {
}
