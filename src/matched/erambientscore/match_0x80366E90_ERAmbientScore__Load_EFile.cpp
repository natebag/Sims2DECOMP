// 0x80366E90 ERAmbientScore::Load(EFile (580 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 26,0x48(1); stw 0,0x64(1); mr 29,4; mr 27,3; lwz 9,0x28(29); addi 4,27,20; li 5,4; li 30,0; lwz 0,0x1c(9); addi 26,27,44; lha 3,0x18(9); mtspr 8,0; add 3,29,3; blrl; lwz 9,0x28(29); addi 4,27,24; li 5,4; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,29,3; blrl; lwz 9,0x28(29); addi 4,27,28; li 5,4; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,29,3; blrl; lwz 9,0x28(29); addi 4,1,64; stw 30,0x40(1); li 5,4; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,29,3; blrl; lwz 3,0x40(1); bl _s80366E90_0; lwz 5,0x40(1); mr 4,3; stw 4,0x20(27); lwz 9,0x28(29); lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,29,3; blrl; lwz 9,0x28(29); addi 4,27,36; li 5,4; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,29,3; blrl; lwz 9,0x28(29); addi 4,27,40; li 5,1; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,29,3; blrl; lwz 9,0x28(29); addi 4,27,41; li 5,1; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,29,3; blrl; lwz 9,0x28(29); addi 4,27,42; li 5,1; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,29,3; blrl; lwz 9,0x28(29); addi 4,1,68; stw 30,0x44(1); li 5,4; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,29,3; blrl; lwz 31,0x44(1); addi 3,1,8; bl _s80366E90_1; lwz 4,0x4(26); lis 9,-15124; lwz 5,0x2c(27); ori 9,9,20165; subf 0,5,4; mullw 0,0,9; srawi 0,0,2; cmplw 31,0; bge 2f; mulli 0,31,52; add 28,0,5; lwz 31,0x4(26); mr 30,28; cmpw 28,31; beq 1f; 0:; mr 3,30; li 4,2; bl _s80366E90_2; addi 30,30,52; cmpw 30,31; bne 0b; 1:; stw 28,0x4(26); b 3f; 2:; subf 5,0,31; mr 3,26; addi 6,1,8; bl _s80366E90_3; 3:; addi 3,1,8; li 4,2; bl _s80366E90_4; li 30,0; lwz 0,0x44(1); cmpw 30,0; bge 5f; li 31,0; 4:; lwz 3,0x2c(27); mr 4,29; addi 30,30,1; add 3,3,31; bl _s80366E90_5; addi 31,31,52; lwz 0,0x44(1); cmpw 30,0; blt 4b; 5:; lwz 0,0x64(1); mtspr 8,0; lmw 26,0x48(1); addi 1,1,96"

extern "C" void _s80366E90_0();
extern "C" void _s80366E90_1();
extern "C" void _s80366E90_2();
extern "C" void _s80366E90_3();
extern "C" void _s80366E90_4();
extern "C" void _s80366E90_5();

struct ERAmbientScore {
    void Load_EFile();
};

void ERAmbientScore::Load_EFile() {
}
