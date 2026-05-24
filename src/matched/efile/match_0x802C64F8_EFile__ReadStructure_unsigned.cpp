// 0x802C64F8 EFile::ReadStructure(unsigned (456 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 25,0x1c(1); stw 0,0x3c(1); mr 30,3; mr 28,4; li 0,1; rlwinm 3,28,2,0,29; stw 0,0x0(30); li 26,0; bl _s802C64F8_0; addi 25,1,20; stw 3,0x4(30); cmplw 26,28; bge 3f; li 27,0; 0:; lwz 9,0x28(30); addi 4,1,12; li 5,4; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,30,3; blrl; lwz 3,0xc(1); bl _s802C64F8_1; lwz 9,0x28(30); mr 29,3; addi 4,1,8; li 5,2; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,30,3; blrl; lhz 0,0x8(1); addi 4,1,16; li 5,4; sth 0,0x16(29); lwz 9,0x28(30); lha 3,0x18(9); lwz 0,0x1c(9); add 3,30,3; mtspr 8,0; blrl; lwz 9,0x10(1); addi 9,9,-1; cmpwi 9,-1; stw 9,0x10(1); beq 2f; mr 31,27; 1:; lwz 9,0x0(29); addi 27,27,4; addi 26,26,1; mtspr 8,9; blrl; lwz 9,0x4(30); stwx 3,31,9; addi 31,31,4; lwz 9,0x10(1); addi 9,9,-1; cmpwi 9,-1; stw 9,0x10(1); bne 1b; 2:; cmplw 26,28; blt 0b; 3:; li 31,0; cmplw 31,28; bge 5f; li 29,0; 4:; lwz 9,0x4(30); mr 4,30; addi 31,31,1; lwzx 11,29,9; addi 29,29,4; lwz 9,0x0(11); lwz 0,0x4c(9); lha 3,0x48(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x28(30); addi 4,1,10; li 5,1; lha 3,0x18(9); lwz 0,0x1c(9); add 3,30,3; mtspr 8,0; blrl; cmplw 31,28; blt 4b; 5:; lwz 9,0x28(30); mr 4,25; li 5,4; lha 3,0x18(9); lwz 0,0x1c(9); add 3,30,3; mtspr 8,0; blrl; lwz 9,0x14(1); lwz 3,0x4(30); rlwinm 9,9,2,0,29; cmpwi 3,0; lwzx 31,9,3; beq 6f; bl _s802C64F8_2; 6:; li 0,0; mr 3,31; stw 0,0x0(30); lwz 0,0x3c(1); mtspr 8,0; lmw 25,0x1c(1); addi 1,1,56"

extern "C" void _s802C64F8_0();
extern "C" void _s802C64F8_1();
extern "C" void _s802C64F8_2();

struct EFile {
    void ReadStructure();
};

void EFile::ReadStructure() {
}
