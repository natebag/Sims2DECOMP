// 0x8022D150 EIStaticModel::ChangeShader(unsigned (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 23,0xc(1); stw 0,0x34(1); mr 27,3; mr 23,4; lwz 9,0x120(27); mr 24,5; cmpwi 9,0; beq 4f; lwz 0,0x40(9); li 8,0; lwz 30,0x118(27); cmpw 8,0; bge 4f; 0:; lwz 11,0x120(27); mulli 10,8,24; li 28,0; lwz 9,0x3c(11); addi 26,8,1; add 31,9,10; lwz 0,0x4(31); cmpw 28,0; bge 3f; lis 25,-32692; li 29,0; 1:; lwz 9,0x0(31); add 9,9,29; lwz 0,0xc(9); cmpw 0,23; bne 2f; lwz 3,0x4(30); bl _s8022D150_0; addi 3,25,-17444; mr 4,24; li 5,0; li 6,0; bl _s8022D150_1; stw 3,0x4(30); 2:; lwz 0,0x4(31); addi 28,28,1; addi 30,30,16; addi 29,29,112; cmpw 28,0; blt 1b; 3:; lwz 9,0x120(27); mr 8,26; lwz 0,0x40(9); cmpw 8,0; blt 0b; 4:; lwz 0,0x34(1); mtspr 8,0; lmw 23,0xc(1); addi 1,1,48"

extern "C" void _s8022D150_0();
extern "C" void _s8022D150_1();

struct EIStaticModel {
    void ChangeShader();
};

void EIStaticModel::ChangeShader() {
}
