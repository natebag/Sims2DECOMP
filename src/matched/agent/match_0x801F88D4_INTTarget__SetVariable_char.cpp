// 0x801F88D4 INTTarget::SetVariable(char (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 29,0x2c(1); stw 0,0x3c(1); mr 31,4; mr 30,3; lbz 3,0x0(31); extsb 3,3; bl _s801F88D4_0; cmpwi 3,0; beq 0f; addi 31,31,1; 0:; lwz 3,-28636(13); mr 4,31; bl _s801F88D4_1; mr. 3,3; bne 1f; lwz 4,-28528(13); lis 5,-32704; stw 3,0x8c(30); addi 5,5,-22828; lwz 6,0x98(30); addi 3,30,200; bl _s801F88D4_2; li 0,1; stw 0,0x90(30); b 4f; 1:; lwz 3,-28624(13); mr 4,31; bl _s801F88D4_3; mr. 29,3; bne 2f; stw 29,0x8c(30); addi 3,30,200; lwz 4,-28672(13); li 5,0; lwz 6,0x98(30); bl _s801F88D4_4; stw 29,0x88(30); b 4f; 2:; lwz 3,-28648(13); mr 4,31; bl _s801F88D4_5; cmpwi 3,0; bne 3f; lwz 0,0xb0(30); lis 4,-32704; addi 4,4,-30836; addi 3,1,8; mr 5,0; stw 0,0xa8(30); crxor 6,6,6; bl _s801F88D4_6; addi 3,30,188; addi 4,1,8; bl _s801F88D4_7; b 4f; 3:; lwz 3,-28612(13); mr 4,31; bl _s801F88D4_8; mr. 3,3; bne 4f; stw 3,0x90(30); 4:; lwz 0,0x3c(1); mtspr 8,0; lmw 29,0x2c(1); addi 1,1,56"
extern "C" void _s801F88D4_0();
extern "C" void _s801F88D4_1();
extern "C" void _s801F88D4_2();
extern "C" void _s801F88D4_3();
extern "C" void _s801F88D4_4();
extern "C" void _s801F88D4_5();
extern "C" void _s801F88D4_6();
extern "C" void _s801F88D4_7();
extern "C" void _s801F88D4_8();
extern "C" void f_801F88D4() {}
