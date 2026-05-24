// 0x802FC4B0 ESubModelShader::ReadNormals(unsigned (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); lwz 0,0x10(3); mr 30,4; mr 27,30; mr 31,5; andi. 9,0,8; beq 2f; lwz 4,0x18(31); lis 5,-32702; lis 7,-32702; addi 5,5,-2744; rlwinm 4,4,2,0,29; addi 7,7,-2600; li 6,1867; li 29,0; bl _s802FC4B0_0; lwz 0,0x18(31); stw 3,0x8(31); cmplw 29,0; bge 1f; li 28,0; 0:; lwz 3,0x8(31); mr 4,30; li 5,4; addi 29,29,1; add 3,28,3; addi 30,30,4; bl _s802FC4B0_1; addi 28,28,4; lwz 0,0x18(31); cmplw 29,0; blt 0b; 1:; lwz 4,0x18(31); lwz 3,0x8(31); rlwinm 4,4,2,0,29; bl _s802FC4B0_2; 2:; subf 3,27,30; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s802FC4B0_0();
extern "C" void _s802FC4B0_1();
extern "C" void _s802FC4B0_2();

struct ESubModelShader {
    void ReadNormals();
};

void ESubModelShader::ReadNormals() {
}
