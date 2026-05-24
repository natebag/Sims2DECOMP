// 0x8022A908 EIPortalPointLight::Read(EStream (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 30,0x20(1); stw 0,0x2c(1); mr 31,3; mr 30,4; bl _s8022A908_0; lis 9,-32688; lhz 0,-13178(9); cmpwi 0,0; bne 1f; addi 4,1,8; mr 3,30; bl _s8022A908_1; mr 30,3; addi 4,31,196; lwz 9,0x18(30); li 5,4; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x18(30); addi 4,31,200; li 5,4; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x18(30); addi 4,1,24; li 5,1; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,30,3; blrl; lbz 0,0x18(1); li 9,1; cmpwi 0,0; bne 0f; li 9,0; 0:; stw 9,0xcc(31); 1:; mr 3,31; addi 4,1,8; bl _s8022A908_2; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x20(1); addi 1,1,40"

extern "C" void _s8022A908_0();
extern "C" void _s8022A908_1();
extern "C" void _s8022A908_2();

struct EIPortalPointLight {
    void Read_EStream();
};

void EIPortalPointLight::Read_EStream() {
}
