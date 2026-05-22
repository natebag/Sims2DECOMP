// 0x80041A7C EGlobal::RecalcHouse(void) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 3,0xc8(31); cmpwi 3,0; beq 0f; bl _s80041A7C_0; lwz 9,0xc8(31); lwz 3,0x4(9); bl _s80041A7C_1; 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80041A7C_0();
extern "C" void _s80041A7C_1();
extern "C" void f_80041A7C() {}
