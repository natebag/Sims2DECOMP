// 0x8014CAC0 cFixedWorldImpl::DeleteArrays(void) (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 3,0x2c(31); cmpwi 3,0; beq 0f; li 4,3; bl _s8014CAC0_0; 0:; lwz 3,0x38(31); li 30,0; stw 30,0x2c(31); cmpwi 3,0; beq 1f; li 4,3; bl _s8014CAC0_1; 1:; lwz 3,0x30(31); stw 30,0x38(31); cmpwi 3,0; beq 2f; li 4,3; bl _s8014CAC0_2; 2:; lwz 3,0x34(31); stw 30,0x30(31); cmpwi 3,0; beq 3f; li 4,3; bl _s8014CAC0_3; 3:; lwz 3,0x3c(31); stw 30,0x34(31); cmpwi 3,0; beq 4f; li 4,3; bl _s8014CAC0_4; 4:; lwz 3,0x40(31); stw 30,0x3c(31); cmpwi 3,0; beq 5f; li 4,3; bl _s8014CAC0_5; 5:; stw 30,0x40(31); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8014CAC0_0();
extern "C" void _s8014CAC0_1();
extern "C" void _s8014CAC0_2();
extern "C" void _s8014CAC0_3();
extern "C" void _s8014CAC0_4();
extern "C" void _s8014CAC0_5();
extern "C" void f_8014CAC0() {}
