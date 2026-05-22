// 0x801CFFC8 O2TTarget::StartScreenWizard(char (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; mr 3,5; bl _s801CFFC8_0; cmpwi 3,1; bne 0f; lwz 0,0x0(31); lis 9,-32705; addi 4,9,14728; cmpwi 0,0; beq 1f; lwz 3,0x1c(31); cmpwi 3,0; beq 1f; lis 5,16979; lwz 6,0x7c(31); ori 5,5,896; li 7,0; bl _s801CFFC8_1; b 1f; 0:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,14728; cmpwi 0,0; beq 1f; lwz 3,0x1c(31); cmpwi 3,0; beq 1f; lis 5,-18456; lwz 6,0x7c(31); ori 5,5,8486; li 7,0; bl _s801CFFC8_2; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s801CFFC8_0();
extern "C" void _s801CFFC8_1();
extern "C" void _s801CFFC8_2();
extern "C" void f_801CFFC8() {}
