// 0x8022E5A8 EIStaticSubModel::Load(EFile (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr 31,4; bl _s8022E5A8_0; mr 3,30; mr 4,31; bl _s8022E5A8_1; lis 9,-32688; lhz 0,-13098(9); cmpwi 0,0; bne 0f; lwz 9,0x28(31); addi 4,30,144; li 5,4; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x28(31); addi 4,30,124; li 5,4; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x28(31); addi 4,30,128; li 5,12; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x28(31); addi 4,30,140; li 5,4; lha 3,0x18(9); lwz 0,0x1c(9); add 3,31,3; mtspr 8,0; blrl; 0:; mr 3,30; bl _s8022E5A8_2; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8022E5A8_0();
extern "C" void _s8022E5A8_1();
extern "C" void _s8022E5A8_2();
extern "C" void f_8022E5A8() {}
