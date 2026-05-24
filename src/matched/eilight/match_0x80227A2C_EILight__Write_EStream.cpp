// 0x80227A2C EILight::Write(EStream (276 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); mr 30,3; mr 31,4; bl _s80227A2C_0; lwz 0,0x88(30); li 9,0; cmpwi 0,0; beq 0f; li 9,1; 0:; stb 9,0x8(1); addi 4,1,8; lwz 9,0x18(31); li 5,1; lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,31,3; blrl; lwz 0,0x7c(30); li 9,0; cmpwi 0,0; beq 1f; li 9,1; 1:; stb 9,0x8(1); addi 4,1,8; lwz 9,0x18(31); li 5,1; lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,31,3; blrl; lwz 0,0x80(30); li 9,0; cmpwi 0,0; beq 2f; li 9,1; 2:; stb 9,0x8(1); addi 4,1,8; lwz 9,0x18(31); li 5,1; lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x18(31); addi 4,1,16; li 5,4; lfs f0,0x8c(30); lha 3,0x38(9); lwz 0,0x3c(9); add 3,31,3; stfs f0,0x10(1); mtspr 8,0; blrl; addi 4,30,144; mr 3,31; bl _s80227A2C_1; lwz 4,0x84(30); bl _s80227A2C_2; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"

extern "C" void _s80227A2C_0();
extern "C" void _s80227A2C_1();
extern "C" void _s80227A2C_2();

struct EILight {
    void Write_EStream();
};

void EILight::Write_EStream() {
}
