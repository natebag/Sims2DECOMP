// 0x802FC3B8 ESubModelShader::ReadNormalsOld(unsigned (248 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 25,0x14(1); stw 0,0x34(1); lwz 0,0x10(3); mr 28,4; mr 25,28; mr 31,5; andi. 9,0,8; beq 2f; lwz 4,0x18(31); lis 5,-32702; lis 7,-32702; addi 5,5,-2744; rlwinm 4,4,2,0,29; addi 7,7,-2600; li 6,1829; li 27,0; bl _s802FC3B8_0; lwz 0,0x18(31); stw 3,0x8(31); cmplw 27,0; bge 1f; addi 30,1,8; li 26,127; li 29,0; 0:; mr 4,28; mr 3,30; li 5,3; addi 27,27,1; bl _s802FC3B8_1; addi 28,28,3; stb 26,0x3(30); lwz 11,0x8(31); lbz 0,0x8(1); stbx 0,29,11; lwz 9,0x8(31); lbz 0,0x1(30); add 9,29,9; stb 0,0x1(9); lwz 11,0x8(31); lbz 0,0x2(30); add 11,29,11; stb 0,0x2(11); lwz 9,0x8(31); lbz 0,0x3(30); add 9,29,9; stb 0,0x3(9); addi 29,29,4; lwz 0,0x18(31); cmplw 27,0; blt 0b; 1:; lwz 4,0x18(31); lwz 3,0x8(31); rlwinm 4,4,2,0,29; bl _s802FC3B8_2; 2:; subf 3,25,28; lwz 0,0x34(1); mtspr 8,0; lmw 25,0x14(1); addi 1,1,48"

extern "C" void _s802FC3B8_0();
extern "C" void _s802FC3B8_1();
extern "C" void _s802FC3B8_2();

struct ESubModelShader {
    void ReadNormalsOld();
};

void ESubModelShader::ReadNormalsOld() {
}
