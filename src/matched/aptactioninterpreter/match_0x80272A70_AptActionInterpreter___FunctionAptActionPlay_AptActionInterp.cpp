// 0x80272A70 AptActionInterpreter::_FunctionAptActionPlay(AptActionInterpreter (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,4; lwz 30,0x4(31); lwz 0,0x0(30); andis. 9,0,2048; beq 5f; mr 3,30; li 29,0; bl _s80272A70_0; cmpwi 3,19; bne 0f; mr 3,30; bl _s80272A70_1; subfic 0,3,0; adde 29,0,3; 0:; cmpwi 29,0; bne 5f; lwz 11,0x8(31); cmpwi 11,0; beq 2f; lwz 0,0x0(11); li 10,0; rlwinm 9,0,0,25,31; addi 9,9,-12; cmplwi 9,7; bgt 1f; rlwinm 10,0,5,31,31; 1:; cmpwi 10,0; beq 2f; lwz 9,0x4c(11); b 4f; 2:; lwz 11,0x4(31); li 0,0; lwz 4,0x0(11); rlwinm 9,4,0,25,31; addi 9,9,-12; cmplwi 9,7; bgt 3f; rlwinm 0,4,5,31,31; 3:; cmpwi 0,0; beq 5f; lwz 9,0x4c(30); 4:; lwz 0,0x1c(9); ori 0,0,64; stw 0,0x1c(9); 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s80272A70_0();
extern "C" void _s80272A70_1();

struct AptActionInterpreter {
    void _FunctionAptActionPlay_AptActionInterp();
};

void AptActionInterpreter::_FunctionAptActionPlay_AptActionInterp() {
}
