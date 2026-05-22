// 0x8014CB7C cFixedWorldImpl::Save(iResFile (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lwz 3,0x2c(31); lis 5,16754; ori 5,5,29305; li 6,11; li 7,1; bl _s8014CB7C_0; mr. 3,3; bne 0f; lwz 3,0x38(31); lis 5,16754; mr 4,30; ori 5,5,29305; li 6,12; li 7,1; bl _s8014CB7C_1; lwz 3,0x34(31); lis 5,16754; mr 4,30; ori 5,5,29305; li 6,8; li 7,1; bl _s8014CB7C_2; mr. 3,3; bne 0f; li 3,0; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8014CB7C_0();
extern "C" void _s8014CB7C_1();
extern "C" void _s8014CB7C_2();
extern "C" void f_8014CB7C() {}
