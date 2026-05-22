// 0x801FDE64 PDATarget::GetVariable(char (320 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; mr 30,4; li 3,32; bl _s801FDE64_0; mr 31,3; li 0,0; lis 3,-32704; stb 0,0x0(31); addi 3,3,-20684; mr 4,30; bl _s801FDE64_1; cmpwi 3,0; bne 0f; lis 9,-32704; addi 11,9,-30832; lwz 10,-30832(9); lbz 8,0x6(11); lhz 0,0x4(11); stw 10,0x0(31); sth 0,0x4(31); stb 8,0x6(31); b 5f; 0:; lis 3,-32704; mr 4,30; addi 3,3,-20672; bl _s801FDE64_2; cmpwi 3,0; bne 2f; lwz 0,0x13c(29); cmpwi 0,0; bne 1f; lwz 0,0x140(29); cmpwi 0,0; bne 1f; lis 9,-32704; lhz 0,-30824(9); sth 0,0x0(31); b 5f; 1:; lis 9,-32704; lhz 0,-30820(9); sth 0,0x0(31); b 5f; 2:; lis 3,-32704; mr 4,30; addi 3,3,-20612; bl _s801FDE64_3; cmpwi 3,0; beq 3f; lis 3,-32704; mr 4,30; addi 3,3,-19992; bl _s801FDE64_4; cmpwi 3,0; beq 3f; lis 3,-32704; mr 4,30; addi 3,3,-19972; bl _s801FDE64_5; cmpwi 3,0; bne 5f; 3:; bl _s801FDE64_6; cmpwi 3,0; li 5,0; beq 4f; li 5,1; 4:; lis 4,-32704; mr 3,31; addi 4,4,-30836; crxor 6,6,6; bl _s801FDE64_7; 5:; mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801FDE64_0();
extern "C" void _s801FDE64_1();
extern "C" void _s801FDE64_2();
extern "C" void _s801FDE64_3();
extern "C" void _s801FDE64_4();
extern "C" void _s801FDE64_5();
extern "C" void _s801FDE64_6();
extern "C" void _s801FDE64_7();
extern "C" void f_801FDE64() {}
