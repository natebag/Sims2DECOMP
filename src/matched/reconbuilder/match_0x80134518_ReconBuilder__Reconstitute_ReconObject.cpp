// 0x80134518 ReconBuilder::Reconstitute(ReconObject (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 27,4; mr 25,3; lwz 9,0x0(27); mr 31,5; lwz 11,0xc(31); mr 28,6; lwz 0,0x1c(9); mr 26,7; lha 3,0x18(9); addi 29,11,128; mtspr 8,0; lha 30,0x80(11); add 3,27,3; add 30,31,30; blrl; lwz 0,0x4(29); mr 4,3; lis 6,-32749; mr 5,28; mr 3,30; addi 6,6,18108; mtspr 8,0; blrl; mr. 5,3; bne 0f; mr 3,31; bl _s80134518_0; b 1f; 0:; mr 3,25; mr 4,27; mr 6,26; bl _s80134518_1; li 3,0; 1:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"

extern "C" void _s80134518_0();
extern "C" void _s80134518_1();

struct ReconBuilder {
    void Reconstitute_ReconObject();
};

void ReconBuilder::Reconstitute_ReconObject() {
}
