// 0x802FC24C ESubModelShader::ReadTexcoords(unsigned (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lwz 0,0x10(3); mr 31,4; mr 28,31; mr 29,5; andi. 9,0,2; beq 2f; li 9,2; andi. 11,0,64; beq 0f; li 9,4; 0:; andi. 11,0,16; li 0,4; beq 1f; li 0,2; 1:; lwz 30,0x18(29); lis 5,-32702; lis 7,-32702; addi 5,5,-2744; mullw 30,30,9; addi 7,7,-2636; li 6,1765; mullw 30,30,0; mr 4,30; bl _s802FC24C_0; mr 0,3; mr 4,31; stw 0,0x4(29); mr 5,30; add 31,31,30; bl _s802FC24C_1; lwz 3,0x4(29); mr 4,30; bl _s802FC24C_2; 2:; subf 3,28,31; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s802FC24C_0();
extern "C" void _s802FC24C_1();
extern "C" void _s802FC24C_2();

struct ESubModelShader {
    void ReadTexcoords();
};

void ESubModelShader::ReadTexcoords() {
}
