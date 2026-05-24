// 0x80275424 AptActionInterpreter::_FunctionAptActionSetProperty(AptActionInterpreter (296 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 31,3; mr 29,4; lwz 9,0x0(31); addi 6,1,8; lwz 0,0x8(31); addi 11,9,-2; addi 10,9,-1; rlwinm 11,11,2,0,29; rlwinm 10,10,2,0,29; add 11,11,0; rlwinm 9,9,2,0,29; add 9,9,0; add 10,10,0; lwz 4,0x8(29); lwz 5,-4(11); lwz 3,0x4(29); lwz 30,-4(10); lwz 28,-4(9); bl _s80275424_0; mr 3,30; bl _s80275424_1; lwz 4,0x8(1); cmpwi 4,0; beq 0f; lis 9,-32700; rlwinm 0,3,2,0,29; addi 9,9,-11540; lis 11,-32694; lwzx 6,9,0; addi 11,11,-11332; lwz 5,0x8(29); mr 7,28; rlwinm 6,6,2,0,29; mr 3,31; add 6,6,11; li 8,1; li 9,1; li 10,0; bl _s80275424_2; 0:; lwz 0,0x0(31); cmpwi 0,3; blt 2f; li 30,1; lis 28,-32704; lis 29,-32704; 1:; lwz 11,0x0(31); addi 4,28,6004; lwz 8,0x8(31); addi 5,29,5812; subf 11,30,11; li 6,180; rlwinm 11,11,2,0,29; addi 30,30,1; lwzx 10,11,8; lwz 9,0x8(10); lha 3,0x10(9); lwz 0,0x14(9); add 3,10,3; mtspr 8,0; blrl; cmpwi 30,3; ble 1b; lwz 9,0x0(31); addi 9,9,-3; stw 9,0x0(31); 2:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"

extern "C" void _s80275424_0();
extern "C" void _s80275424_1();
extern "C" void _s80275424_2();

struct AptActionInterpreter {
    void _FunctionAptActionSetProperty_AptActio();
};

void AptActionInterpreter::_FunctionAptActionSetProperty_AptActio() {
}
