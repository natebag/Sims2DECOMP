// 0x802FCED4 ESubModelShader::Read(unsigned (888 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 19,0x2c(1); stw 0,0x64(1); mr 28,3; mr 31,4; mr 21,5; bl _s802FCED4_0; mr 19,31; mr 4,31; li 5,4; addi 3,28,16; addi 31,31,4; bl _s802FCED4_1; li 30,0; addi 3,1,24; mr 4,31; li 5,4; addi 31,31,4; bl _s802FCED4_2; lwz 4,0x18(1); lis 3,-32692; li 6,0; li 5,0; addi 3,3,-17444; bl _s802FCED4_3; lwz 0,0x18(1); mr 4,31; stw 3,0x8(28); li 5,4; stw 0,0xc(28); addi 3,1,28; bl _s802FCED4_4; addi 31,31,4; lwz 4,0x1c(1); li 5,0; addi 3,28,20; bl _s802FCED4_5; lwz 5,0x1c(1); li 4,0; lwz 3,0x14(28); mulli 5,5,52; bl _s802FCED4_6; b 1f; 0:; mr 4,31; addi 3,1,8; li 5,1; addi 30,30,1; crxor 6,6,6; bl _s802FCED4_7; addi 31,31,1; 1:; lwz 0,0x1c(1); cmplw 30,0; blt 0b; mr 4,31; addi 3,28,36; li 5,4; addi 31,31,4; bl _s802FCED4_8; li 22,0; lwz 0,0x1c(1); li 23,0; li 25,0; li 27,0; cmpwi 0,0; li 26,0; li 30,0; beq 2f; lwz 30,0x14(28); 2:; li 24,0; addi 20,28,20; stb 24,0x2a(30); 3:; mr 4,31; addi 3,1,16; li 5,1; addi 31,31,1; bl _s802FCED4_9; lbz 29,0x10(1); cmpwi 29,3; beq 12f; bgt 4f; cmpwi 29,1; beq 9f; bgt 10f; cmpwi 29,0; beq 5f; b 15f; 4:; cmpwi 29,5; beq 13f; blt 11f; cmpwi 29,6; beq 14f; b 15f; 5:; mr 4,31; li 5,4; addi 3,30,24; addi 31,31,4; bl _s802FCED4_10; lwz 3,0x18(30); li 4,0; lwz 5,0x10(28); mr 6,27; bl _s802FCED4_11; mr 4,31; mr 6,27; mr 5,30; mr 3,28; bl _s802FCED4_12; add 31,31,3; mr 5,30; mr 4,31; mr 3,28; bl _s802FCED4_13; add 31,31,3; mr 5,30; mr 4,31; mr 3,28; bl _s802FCED4_14; add 31,31,3; cmpwi 21,57; bgt 6f; mr 4,31; mr 3,28; mr 5,30; bl _s802FCED4_15; b 7f; 6:; mr 4,31; mr 3,28; mr 5,30; bl _s802FCED4_16; 7:; add 31,31,3; mr 4,31; mr 5,30; mr 6,27; mr 3,28; bl _s802FCED4_17; addi 24,24,1; add 31,31,3; bl _s802FCED4_18; mr 4,31; mr 5,30; mr 3,28; addi 6,1,32; bl _s802FCED4_19; sth 3,0x28(30); addi 30,30,52; lwz 0,0x20(1); lwz 9,0x1c(1); add 31,31,0; cmplw 24,9; blt 8f; li 30,0; 8:; cmpwi 30,0; beq 15f; stb 26,0x2a(30); b 15f; 9:; mr 4,31; li 5,2; addi 3,1,18; addi 31,31,2; bl _s802FCED4_20; addi 23,23,1; mr 4,31; addi 3,1,20; li 5,1; addi 31,31,1; bl _s802FCED4_21; lbz 11,0x14(1); addi 9,30,36; lbz 0,0x13(1); stbx 0,9,11; stw 29,0x2c(30); lbz 9,0x2b(30); addi 9,9,1; stb 9,0x2b(30); b 15f; 10:; addi 25,25,1; li 26,1; cmpwi 30,0; beq 11f; stb 26,0x2a(30); 11:; li 27,1; b 15f; 12:; addi 25,25,1; li 26,0; cmpwi 30,0; beq 13f; stb 26,0x2a(30); 13:; li 27,0; b 15f; 14:; li 22,1; 15:; cmpwi 22,0; beq 3b; lwz 0,0x1c(1); cmpwi 0,1; bne 16f; cmpwi 23,0; bne 16f; cmpwi 25,0; bne 16f; lwz 0,0x10(28); ori 0,0,1; stw 0,0x10(28); 16:; lwz 0,0x4(20); subf 4,19,31; cmpwi 0,0; ble 18f; lwz 9,0x14(28); mtspr 9,0; lwz 11,-26728(13); addi 3,9,24; 17:; lwz 0,0x0(3); addi 3,3,52; add 11,11,0; bdnz 17b; stw 11,-26728(13); 18:; mr 3,4; lwz 0,0x64(1); mtspr 8,0; lmw 19,0x2c(1); addi 1,1,96"

extern "C" void _s802FCED4_0();
extern "C" void _s802FCED4_1();
extern "C" void _s802FCED4_2();
extern "C" void _s802FCED4_3();
extern "C" void _s802FCED4_4();
extern "C" void _s802FCED4_5();
extern "C" void _s802FCED4_6();
extern "C" void _s802FCED4_7();
extern "C" void _s802FCED4_8();
extern "C" void _s802FCED4_9();
extern "C" void _s802FCED4_10();
extern "C" void _s802FCED4_11();
extern "C" void _s802FCED4_12();
extern "C" void _s802FCED4_13();
extern "C" void _s802FCED4_14();
extern "C" void _s802FCED4_15();
extern "C" void _s802FCED4_16();
extern "C" void _s802FCED4_17();
extern "C" void _s802FCED4_18();
extern "C" void _s802FCED4_19();
extern "C" void _s802FCED4_20();
extern "C" void _s802FCED4_21();

struct ESubModelShader {
    void Read();
};

void ESubModelShader::Read() {
}
