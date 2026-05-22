// 0x8015BB9C ObjectDataID::operator!=(ObjectDataID (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s8015BB9C_0; xori 3,3,1; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8015BB9C_0();
extern "C" void f_8015BB9C() {}
