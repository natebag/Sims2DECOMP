// 0x8026F824 AptActionInterpreter::getName(AptCIH (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,4; mr 30,3; lis 4,-32704; addi 3,1,8; addi 4,4,5608; bl _s8026F824_0; lwz 11,0x8(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x0(31); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 0f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026F824_1; 0:; lwz 4,0x8(1); stw 4,0x0(31); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 1f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026F824_2; 1:; mr 3,30; mr 4,31; li 5,1; bl _s8026F824_3; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"

extern "C" void _s8026F824_0();
extern "C" void _s8026F824_1();
extern "C" void _s8026F824_2();
extern "C" void _s8026F824_3();

struct AptActionInterpreter {
    void getName_AptCIH();
};

void AptActionInterpreter::getName_AptCIH() {
}
