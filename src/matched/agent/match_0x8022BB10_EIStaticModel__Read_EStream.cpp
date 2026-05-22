// 0x8022BB10 EIStaticModel::Read(EStream (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr 31,4; bl _s8022BB10_0; lis 9,-32688; lhz 0,-19434(9); cmpwi 0,0; bne 0f; lwz 9,0x18(31); addi 4,30,272; li 5,4; lha 3,0x30(9); lwz 0,0x34(9); add 3,31,3; mtspr 8,0; blrl; mr 3,31; addi 4,30,128; bl _s8022BB10_1; 0:; mr 3,30; li 4,0; li 5,0; bl _s8022BB10_2; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8022BB10_0();
extern "C" void _s8022BB10_1();
extern "C" void _s8022BB10_2();
extern "C" void f_8022BB10() {}
