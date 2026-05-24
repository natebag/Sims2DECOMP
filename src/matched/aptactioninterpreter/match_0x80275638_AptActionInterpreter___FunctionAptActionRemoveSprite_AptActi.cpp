// 0x80275638 AptActionInterpreter::_FunctionAptActionRemoveSprite(AptActionInterpreter (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); mr 31,3; mr 11,4; lwz 9,0x0(31); lwz 0,0x8(31); rlwinm 9,9,2,0,29; add 9,9,0; lwz 5,-4(9); lwz 0,0x0(5); andis. 9,0,2048; beq 1f; lwz 4,0x8(11); addi 6,1,8; lwz 3,0x4(11); bl _s80275638_0; lwz 4,0x8(1); cmpwi 4,0; beq 1f; lwz 0,0x0(4); li 11,0; rlwinm 9,0,0,25,31; addi 9,9,-12; cmplwi 9,7; bgt 0f; rlwinm 11,0,5,31,31; 0:; cmpwi 11,0; beq 1f; lwz 9,0x48(4); lwz 3,0x4c(9); addi 3,3,36; bl _s80275638_1; 1:; lwz 9,0x0(31); cmpwi 9,0; ble 2f; lwz 0,0x8(31); rlwinm 9,9,2,0,29; lis 4,-32704; lis 5,-32704; add 9,9,0; addi 4,4,5964; lwz 11,-4(9); addi 5,5,5812; li 6,160; lwz 9,0x8(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; lwz 9,0x0(31); addi 9,9,-1; stw 9,0x0(31); 2:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"

extern "C" void _s80275638_0();
extern "C" void _s80275638_1();

struct AptActionInterpreter {
    void _FunctionAptActionRemoveSprite_AptActi();
};

void AptActionInterpreter::_FunctionAptActionRemoveSprite_AptActi() {
}
