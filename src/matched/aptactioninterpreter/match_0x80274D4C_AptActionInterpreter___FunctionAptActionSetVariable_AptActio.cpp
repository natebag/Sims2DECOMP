// 0x80274D4C AptActionInterpreter::_FunctionAptActionSetVariable(AptActionInterpreter (332 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); lis 11,-32700; mr 31,3; lhz 9,-6476(11); addi 0,11,-6476; stw 0,0x8(1); addi 29,1,8; addi 9,9,1; mr 28,4; sth 9,-6476(11); mr 4,29; lwz 9,0x0(31); lwz 0,0x8(31); addi 11,9,-1; rlwinm 11,11,2,0,29; rlwinm 9,9,2,0,29; add 11,11,0; add 9,9,0; lwz 3,-4(11); lwz 30,-4(9); bl _s80274D4C_0; lwz 5,0x8(28); mr 6,29; lwz 4,0x4(28); mr 7,30; mr 3,31; li 8,1; li 9,1; li 10,0; bl _s80274D4C_1; lwz 0,0x0(31); cmpwi 0,2; blt 1f; li 30,1; lis 28,-32704; lis 29,-32704; 0:; lwz 11,0x0(31); addi 4,28,6004; lwz 8,0x8(31); addi 5,29,5812; subf 11,30,11; li 6,180; rlwinm 11,11,2,0,29; addi 30,30,1; lwzx 10,11,8; lwz 9,0x8(10); lha 3,0x10(9); lwz 0,0x14(9); add 3,10,3; mtspr 8,0; blrl; cmpwi 30,2; ble 0b; lwz 9,0x0(31); addi 9,9,-2; stw 9,0x0(31); 1:; lwz 3,-27600(13); lwz 0,0x4(3); cmpwi 0,0; beq 2f; lwz 0,0x0(31); cmpwi 0,0; bne 2f; bl _s80274D4C_2; 2:; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 3f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80274D4C_3; 3:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"

extern "C" void _s80274D4C_0();
extern "C" void _s80274D4C_1();
extern "C" void _s80274D4C_2();
extern "C" void _s80274D4C_3();

struct AptActionInterpreter {
    void _FunctionAptActionSetVariable_AptActio();
};

void AptActionInterpreter::_FunctionAptActionSetVariable_AptActio() {
}
