// 0x801E9138 GetVar_GetCount::GetVar_GetCount(char (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 9,-32698; mr 30,3; addi 9,9,32728; mr 29,5; stw 9,0x8(30); mr 3,4; stw 4,0x0(30); bl _s801E9138_0; lis 9,-32698; stw 3,0x4(30); addi 9,9,32376; lis 4,-32704; stw 9,0x8(30); addi 4,4,-30836; mr 5,29; addi 3,30,12; crxor 6,6,6; bl _s801E9138_1; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801E9138_0();
extern "C" void _s801E9138_1();
extern "C" void f_801E9138() {}
