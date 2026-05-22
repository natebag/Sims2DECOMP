// 0x8022BAAC EIStaticModel::Write(EStream (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 30,4; mr 29,3; bl _s8022BAAC_0; lwz 9,0x18(30); addi 4,1,8; li 5,4; lwz 0,0x110(29); lha 3,0x38(9); lwz 9,0x3c(9); add 3,30,3; stw 0,0x8(1); mtspr 8,9; blrl; mr 3,30; addi 4,29,128; bl _s8022BAAC_1; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s8022BAAC_0();
extern "C" void _s8022BAAC_1();
extern "C" void f_8022BAAC() {}
