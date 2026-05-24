// 0x80229970 EIPointAmbLight::Read(EStream (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; mr 30,4; bl _s80229970_0; lis 9,-32688; lhz 0,-13258(9); cmpwi 0,0; bne 1f; mr 3,30; addi 4,31,172; bl _s80229970_1; mr 30,3; addi 4,31,184; lwz 9,0x18(30); li 5,4; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x18(30); addi 4,31,188; li 5,4; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x18(30); addi 4,1,8; li 5,1; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,30,3; blrl; lbz 0,0x8(1); li 9,1; cmpwi 0,0; bne 0f; li 9,0; 0:; stw 9,0xc0(31); 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"

extern "C" void _s80229970_0();
extern "C" void _s80229970_1();

struct EIPointAmbLight {
    void Read_EStream();
};

void EIPointAmbLight::Read_EStream() {
}
