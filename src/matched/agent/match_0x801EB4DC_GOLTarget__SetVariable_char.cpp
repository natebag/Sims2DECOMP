// 0x801EB4DC GOLTarget::SetVariable(char (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; mr 31,3; lbz 9,0x0(30); mr 29,5; addi 9,9,-48; cmplwi 9,1; bgt 0f; addi 30,30,1; 0:; lis 3,-32704; mr 4,30; addi 3,3,-29208; bl _s801EB4DC_0; cmpwi 3,0; bne 1f; lwz 30,0x94(31); mr 3,29; bl _s801EB4DC_1; cmpw 3,30; stw 3,0x94(31); beq 2f; mr 3,31; bl _s801EB4DC_2; b 2f; 1:; lis 3,-32704; mr 4,30; addi 3,3,-29196; bl _s801EB4DC_3; cmpwi 3,0; bne 2f; mr 3,29; bl _s801EB4DC_4; stw 3,0x98(31); 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801EB4DC_0();
extern "C" void _s801EB4DC_1();
extern "C" void _s801EB4DC_2();
extern "C" void _s801EB4DC_3();
extern "C" void _s801EB4DC_4();
extern "C" void f_801EB4DC() {}
