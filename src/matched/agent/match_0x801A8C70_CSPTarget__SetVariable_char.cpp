// 0x801A8C70 CSPTarget::SetVariable(char (344 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; mr 31,3; lbz 3,0x0(30); mr 29,5; extsb 3,3; bl _s801A8C70_0; cmpwi 3,0; beq 0f; addi 30,30,1; 0:; lis 3,-32705; mr 4,30; addi 3,3,-6192; bl _s801A8C70_1; cmpwi 3,0; bne 1f; lwz 0,0x1a0(31); cmpwi 0,0; bne 8f; lis 9,-32697; lwz 11,0x5ef8(9); cmpwi 11,0; beq 8f; lwz 9,0x80(11); lis 4,-32705; lis 5,-32705; addi 4,4,-5352; lha 3,0x10(9); addi 5,5,-5340; lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; b 8f; 1:; lis 3,-32705; mr 4,30; addi 3,3,-6168; bl _s801A8C70_2; cmpwi 3,0; bne 7f; lwz 0,0x90(31); cmpwi 0,1; beq 4f; bgt 2f; cmpwi 0,0; beq 3f; b 8f; 2:; cmpwi 0,2; beq 5f; b 8f; 3:; lis 5,-32705; lwz 4,0x8c(31); addi 5,5,-5332; b 6f; 4:; lis 5,-32705; lwz 4,0x8c(31); addi 5,5,-5320; b 6f; 5:; lis 5,-32705; lwz 4,0x8c(31); addi 5,5,-5308; 6:; addi 6,31,132; addi 3,31,280; li 7,0; li 8,0; bl _s801A8C70_3; b 8f; 7:; lis 3,-32705; mr 4,30; addi 3,3,-6180; bl _s801A8C70_4; cmpwi 3,0; bne 8f; mr 3,29; bl _s801A8C70_5; mr 4,3; mr 3,31; bl _s801A8C70_6; 8:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801A8C70_0();
extern "C" void _s801A8C70_1();
extern "C" void _s801A8C70_2();
extern "C" void _s801A8C70_3();
extern "C" void _s801A8C70_4();
extern "C" void _s801A8C70_5();
extern "C" void _s801A8C70_6();
extern "C" void f_801A8C70() {}
