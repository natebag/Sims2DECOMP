// 0x80228468 EInstance::Read(EStream (344 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); lis 9,-32688; mr 31,3; lhz 0,-18506(9); mr 30,4; cmpwi 0,0; beq 0f; cmpwi 0,1; beq 1f; b 2f; 0:; lwz 9,0x18(30); li 5,4; addi 4,31,88; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,30,3; blrl; mr 3,30; addi 4,31,4; bl _s80228468_0; addi 4,31,56; bl _s80228468_1; mr 30,3; li 5,4; lwz 9,0x18(30); addi 4,31,92; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,30,3; blrl; addi 4,31,60; mr 3,30; bl _s80228468_2; mr 30,3; addi 4,1,8; lwz 9,0x18(30); li 5,4; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x18(30); addi 4,1,12; li 5,4; lha 3,0x30(9); lwz 0,0x34(9); add 3,30,3; mtspr 8,0; blrl; b 2f; 1:; lwz 9,0x18(30); li 5,4; addi 4,31,88; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,30,3; blrl; mr 3,30; addi 4,31,4; bl _s80228468_3; addi 4,31,56; bl _s80228468_4; mr 30,3; addi 4,31,92; lwz 9,0x18(30); li 5,4; lha 3,0x30(9); lwz 0,0x34(9); add 3,30,3; mtspr 8,0; blrl; mr 3,30; addi 4,31,60; bl _s80228468_5; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"

extern "C" void _s80228468_0();
extern "C" void _s80228468_1();
extern "C" void _s80228468_2();
extern "C" void _s80228468_3();
extern "C" void _s80228468_4();
extern "C" void _s80228468_5();

struct EInstance {
    void Read_EStream();
};

void EInstance::Read_EStream() {
}
