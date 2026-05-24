// 0x80276640 AptActionInterpreter::_FunctionAptActionDefineLocal(AptActionInterpreter (316 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; lwz 9,0x0(30); lwz 0,0x8(30); addi 11,9,-1; lwz 3,0x30(30); rlwinm 9,9,2,0,29; rlwinm 11,11,2,0,29; add 9,9,0; add 11,11,0; cmpwi 3,0; lwz 29,-4(9); lwz 6,-4(11); beq 2f; lwz 0,0x0(6); mr 4,6; rlwinm 0,0,0,25,31; cmpwi 0,1; beq 0f; lwz 4,0x24(6); 0:; lwz 0,-26960(13); addi 31,4,12; cmpwi 0,0; bne 1f; bl _s80276640_0; 1:; lwz 3,-26960(13); mr 4,31; mr 5,29; addi 3,3,12; bl _s80276640_1; b 4f; 2:; lwz 0,0x0(6); lwz 5,0x8(4); rlwinm 0,0,0,25,31; lwz 4,0x4(4); cmpwi 0,1; beq 3f; lwz 6,0x24(6); 3:; addi 6,6,12; mr 7,29; mr 3,30; li 8,0; li 9,1; li 10,0; bl _s80276640_2; 4:; lwz 0,0x0(30); cmpwi 0,2; blt 6f; li 31,1; lis 28,-32704; lis 29,-32704; 5:; lwz 11,0x0(30); addi 4,28,6004; lwz 8,0x8(30); addi 5,29,5812; subf 11,31,11; li 6,180; rlwinm 11,11,2,0,29; addi 31,31,1; lwzx 10,11,8; lwz 9,0x8(10); lha 3,0x10(9); lwz 0,0x14(9); add 3,10,3; mtspr 8,0; blrl; cmpwi 31,2; ble 5b; lwz 9,0x0(30); addi 9,9,-2; stw 9,0x0(30); 6:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s80276640_0();
extern "C" void _s80276640_1();
extern "C" void _s80276640_2();

struct AptActionInterpreter {
    void _FunctionAptActionDefineLocal_AptActio();
};

void AptActionInterpreter::_FunctionAptActionDefineLocal_AptActio() {
}
