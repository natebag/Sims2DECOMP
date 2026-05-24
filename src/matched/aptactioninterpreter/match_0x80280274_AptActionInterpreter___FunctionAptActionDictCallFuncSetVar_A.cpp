// 0x80280274 AptActionInterpreter::_FunctionAptActionDictCallFuncSetVar(AptActionInterpreter (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,4; mr 31,3; lwz 9,0x0(30); lis 4,-32704; lis 5,-32704; li 6,138; lbz 11,0x0(9); addi 5,5,5812; addi 9,9,1; addi 4,4,5760; stw 9,0x0(30); rlwinm 11,11,2,0,29; lwz 10,0x38(31); lwz 9,0x0(31); lwzx 8,11,10; lwz 7,0x8(31); rlwinm 11,9,2,0,29; addi 9,9,1; stwx 8,11,7; stw 9,0x0(31); lwz 11,0x8(8); lwz 0,0xc(11); lha 3,0x8(11); mtspr 8,0; add 3,8,3; blrl; mr 3,31; mr 4,30; bl _s80280274_0; mr 3,31; mr 4,30; bl _s80280274_1; lwz 3,-27600(13); lwz 0,0x4(3); cmpwi 0,0; beq 0f; lwz 0,0x0(31); cmpwi 0,0; bne 0f; bl _s80280274_2; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s80280274_0();
extern "C" void _s80280274_1();
extern "C" void _s80280274_2();

struct AptActionInterpreter {
    void _FunctionAptActionDictCallFuncSetVar_A();
};

void AptActionInterpreter::_FunctionAptActionDictCallFuncSetVar_A() {
}
