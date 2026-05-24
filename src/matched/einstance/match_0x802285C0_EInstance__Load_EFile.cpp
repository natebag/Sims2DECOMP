// 0x802285C0 EInstance::Load(EFile (444 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); lis 9,-32688; mr 31,3; lhz 0,-18506(9); mr 30,4; cmpwi 0,0; beq 0f; cmpwi 0,1; beq 1f; b 2f; 0:; lwz 9,0x28(30); li 5,4; addi 4,31,88; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,30,3; blrl; mr 3,30; addi 4,31,4; bl _s802285C0_0; addi 4,31,56; bl _s802285C0_1; mr 30,3; addi 4,31,92; lwz 9,0x28(30); li 5,4; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x28(30); addi 4,31,60; li 5,12; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x28(30); addi 4,31,72; li 5,12; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x28(30); addi 4,1,8; li 5,4; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x28(30); addi 4,1,12; li 5,4; lha 3,0x18(9); lwz 0,0x1c(9); add 3,30,3; mtspr 8,0; blrl; b 2f; 1:; lwz 9,0x28(30); li 5,4; addi 4,31,88; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,30,3; blrl; mr 3,30; addi 4,31,4; bl _s802285C0_2; addi 4,31,56; bl _s802285C0_3; mr 30,3; addi 4,31,92; lwz 9,0x28(30); li 5,4; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x28(30); addi 4,31,60; li 5,12; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x28(30); addi 4,31,72; li 5,12; lha 3,0x18(9); lwz 0,0x1c(9); add 3,30,3; mtspr 8,0; blrl; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"

extern "C" void _s802285C0_0();
extern "C" void _s802285C0_1();
extern "C" void _s802285C0_2();
extern "C" void _s802285C0_3();

struct EInstance {
    void Load_EFile();
};

void EInstance::Load_EFile() {
}
