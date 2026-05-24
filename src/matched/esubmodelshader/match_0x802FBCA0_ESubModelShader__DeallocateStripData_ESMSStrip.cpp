// 0x802FBCA0 ESubModelShader::DeallocateStripData(ESMSStrip (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,4; mr 30,3; lwz 0,0x20(31); cmpwi 0,0; beq 0f; li 0,0; stw 0,0x14(31); 0:; lwz 4,0x20(31); mr 3,30; li 5,0; bl _s802FBCA0_0; lwz 4,0x4(31); mr 3,30; li 5,0; bl _s802FBCA0_1; lwz 4,0x8(31); mr 3,30; li 5,0; bl _s802FBCA0_2; lwz 4,0xc(31); mr 3,30; li 5,0; bl _s802FBCA0_3; lwz 4,0x10(31); mr 3,30; li 5,0; bl _s802FBCA0_4; lwz 4,0x14(31); mr 3,30; li 5,1; bl _s802FBCA0_5; lwz 4,0x0(31); mr 3,30; li 5,1; bl _s802FBCA0_6; li 0,0; stw 0,0x10(31); stw 0,0x20(31); stw 0,0x14(31); stw 0,0x0(31); stw 0,0x4(31); stw 0,0x8(31); stw 0,0xc(31); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s802FBCA0_0();
extern "C" void _s802FBCA0_1();
extern "C" void _s802FBCA0_2();
extern "C" void _s802FBCA0_3();
extern "C" void _s802FBCA0_4();
extern "C" void _s802FBCA0_5();
extern "C" void _s802FBCA0_6();

struct ESubModelShader {
    void DeallocateStripData_ESMSStrip();
};

void ESubModelShader::DeallocateStripData_ESMSStrip() {
}
