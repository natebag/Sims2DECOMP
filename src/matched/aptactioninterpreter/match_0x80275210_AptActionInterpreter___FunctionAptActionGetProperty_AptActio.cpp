// 0x80275210 AptActionInterpreter::_FunctionAptActionGetProperty(AptActionInterpreter (532 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 31,3; mr 30,4; lwz 11,0x0(31); addi 6,1,8; lwz 0,0x8(31); addi 9,11,-1; lwz 3,0x4(30); rlwinm 9,9,2,0,29; rlwinm 11,11,2,0,29; add 9,9,0; add 11,11,0; lwz 5,-4(9); lwz 4,0x8(30); lwz 29,-4(11); bl _s80275210_0; lwz 0,0x8(1); cmpwi 0,0; beq 2f; mr 3,29; lis 27,-32704; bl _s80275210_1; lis 9,-32700; rlwinm 3,3,2,0,29; addi 9,9,-11540; lis 11,-32694; lwzx 6,9,3; addi 11,11,-11332; lwz 5,0x8(30); mr 3,31; rlwinm 6,6,2,0,29; lwz 4,0x8(1); add 6,6,11; li 7,1; li 8,1; li 9,0; bl _s80275210_2; lwz 0,0x0(31); mr 29,3; cmpwi 0,2; blt 1f; li 30,1; lis 28,-32704; 0:; lwz 11,0x0(31); addi 4,28,6004; lwz 8,0x8(31); addi 5,27,5812; subf 11,30,11; li 6,180; rlwinm 11,11,2,0,29; addi 30,30,1; lwzx 10,11,8; lwz 9,0x8(10); lha 3,0x10(9); lwz 0,0x14(9); add 3,10,3; mtspr 8,0; blrl; cmpwi 30,2; ble 0b; lwz 9,0x0(31); addi 9,9,-2; stw 9,0x0(31); 1:; lwz 9,0x0(31); lis 4,-32704; lwz 10,0x8(31); lis 5,-32704; rlwinm 11,9,2,0,29; addi 4,4,5760; stwx 29,11,10; addi 9,9,1; stw 9,0x0(31); addi 5,5,5812; li 6,138; lwz 9,0x8(29); lha 3,0x8(9); lwz 0,0xc(9); add 3,29,3; mtspr 8,0; blrl; b 5f; 2:; lwz 0,0x0(31); lis 27,-32704; cmpwi 0,2; blt 4f; li 30,1; lis 28,-32704; 3:; lwz 11,0x0(31); addi 4,28,6004; lwz 8,0x8(31); addi 5,27,5812; subf 11,30,11; li 6,180; rlwinm 11,11,2,0,29; addi 30,30,1; lwzx 10,11,8; lwz 9,0x8(10); lha 3,0x10(9); lwz 0,0x14(9); add 3,10,3; mtspr 8,0; blrl; cmpwi 30,2; ble 3b; lwz 9,0x0(31); addi 9,9,-2; stw 9,0x0(31); 4:; lwz 9,0x0(31); lis 4,-32704; lwz 10,-22936(13); lis 5,-32704; lwz 8,0x8(31); rlwinm 11,9,2,0,29; addi 9,9,1; addi 4,4,5760; stwx 10,11,8; addi 5,5,5812; stw 9,0x0(31); li 6,138; lwz 9,0x8(10); lha 3,0x8(9); lwz 0,0xc(9); add 3,10,3; mtspr 8,0; blrl; 5:; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"

extern "C" void _s80275210_0();
extern "C" void _s80275210_1();
extern "C" void _s80275210_2();

struct AptActionInterpreter {
    void _FunctionAptActionGetProperty_AptActio();
};

void AptActionInterpreter::_FunctionAptActionGetProperty_AptActio() {
}
