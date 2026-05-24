// 0x802FCDA4 ESubModelShader::ReadIndices(unsigned (304 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 26,0x18(1); stw 0,0x34(1); mr 28,3; mr 29,5; lwz 0,0x10(28); mr 31,4; lwz 9,0x18(29); mr 27,31; mr 26,6; andi. 0,0,32; stw 9,0xc(1); beq 0f; li 0,0; addi 3,1,12; stw 0,0x14(1); stw 0,0x10(1); li 5,4; bl _s802FCDA4_0; addi 31,31,4; addi 3,1,8; mr 4,31; li 5,1; addi 31,31,1; bl _s802FCDA4_1; addi 3,1,16; mr 4,31; li 5,4; addi 31,31,4; bl _s802FCDA4_2; addi 3,1,20; mr 4,31; li 5,4; addi 31,31,4; bl _s802FCDA4_3; lwz 4,0x10(1); lwz 11,-26392(13); stw 4,0x1c(29); lwz 9,0x0(11); lwz 0,0x124(9); lha 3,0x120(9); mtspr 8,0; add 3,11,3; blrl; lwz 30,0x10(1); mr 0,3; mr 4,31; mr 5,30; stw 0,0x20(29); bl _s802FCDA4_4; add 31,31,30; lwz 3,0x20(29); lwz 4,0x10(1); bl _s802FCDA4_5; lwz 9,0x14(1); mr 3,28; lwz 0,0x20(29); mr 5,29; lwz 6,0xc(1); mr 4,3; add 0,0,9; stw 0,0x14(29); lwz 7,0x10(28); rlwinm 7,7,26,31,31; bl _s802FCDA4_6; b 1f; 0:; stw 0,0x1c(29); 1:; subf 0,27,31; lwz 3,0xc(1); stw 0,0x0(26); lwz 0,0x34(1); mtspr 8,0; lmw 26,0x18(1); addi 1,1,48"

extern "C" void _s802FCDA4_0();
extern "C" void _s802FCDA4_1();
extern "C" void _s802FCDA4_2();
extern "C" void _s802FCDA4_3();
extern "C" void _s802FCDA4_4();
extern "C" void _s802FCDA4_5();
extern "C" void _s802FCDA4_6();

struct ESubModelShader {
    void ReadIndices();
};

void ESubModelShader::ReadIndices() {
}
