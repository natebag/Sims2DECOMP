// 0x801BE460 K2YTarget::GetName(void) (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,-30256(13); li 3,0; cmpwi 0,4; beq 4f; bgt 0f; cmpwi 0,2; beq 2f; bgt 3f; b 9f; 0:; cmpwi 0,7; beq 7f; bgt 1f; cmpwi 0,5; beq 5f; cmpwi 0,6; beq 6f; b 9f; 1:; cmpwi 0,8; beq 8f; b 9f; 2:; lis 3,-32705; addi 3,3,5044; bl _s801BE460_0; b 9f; 3:; lis 3,-32705; addi 3,3,5064; bl _s801BE460_1; b 9f; 4:; lis 3,-32705; addi 3,3,5080; bl _s801BE460_2; b 9f; 5:; lis 3,-32705; addi 3,3,5100; bl _s801BE460_3; b 9f; 6:; lis 3,-32705; addi 3,3,7728; bl _s801BE460_4; b 9f; 7:; lis 3,-32705; addi 3,3,7740; bl _s801BE460_5; b 9f; 8:; lis 3,-32705; addi 3,3,7756; bl _s801BE460_6; 9:; cmpwi 3,0; bne 10f; lis 9,-32705; addi 3,9,6544; 10:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801BE460_0();
extern "C" void _s801BE460_1();
extern "C" void _s801BE460_2();
extern "C" void _s801BE460_3();
extern "C" void _s801BE460_4();
extern "C" void _s801BE460_5();
extern "C" void _s801BE460_6();
extern "C" void f_801BE460() {}
