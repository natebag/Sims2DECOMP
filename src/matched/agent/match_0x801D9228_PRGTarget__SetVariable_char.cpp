// 0x801D9228 PRGTarget::SetVariable(char (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,4; mr 30,3; lbz 3,0x0(31); mr 29,5; extsb 3,3; bl _s801D9228_0; cmpwi 3,0; beq 0f; addi 31,31,1; 0:; lwz 3,-29700(13); mr 4,31; bl _s801D9228_1; cmpwi 3,0; beq 1f; lis 3,-32705; mr 4,31; addi 3,3,18768; bl _s801D9228_2; cmpwi 3,0; bne 2f; 1:; mr 3,30; bl _s801D9228_3; b 3f; 2:; lis 3,-32705; mr 4,31; addi 3,3,18748; bl _s801D9228_4; cmpwi 3,0; bne 3f; mr 3,30; mr 4,31; mr 5,29; bl _s801D9228_5; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801D9228_0();
extern "C" void _s801D9228_1();
extern "C" void _s801D9228_2();
extern "C" void _s801D9228_3();
extern "C" void _s801D9228_4();
extern "C" void _s801D9228_5();
extern "C" void f_801D9228() {}
