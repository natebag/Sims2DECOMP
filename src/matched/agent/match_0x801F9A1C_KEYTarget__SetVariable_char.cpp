// 0x801F9A1C KEYTarget::SetVariable(char (428 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 31,3; mr 30,4; lis 3,-32704; mr 28,5; addi 3,3,-22548; bl _s801F9A1C_0; cmpwi 3,0; bne 0f; mr 3,28; bl _s801F9A1C_1; stw 3,0x8c(31); b 6f; 0:; lis 3,-32704; mr 4,30; addi 3,3,-22536; bl _s801F9A1C_2; mr. 29,3; bne 1f; mr 3,31; bl _s801F9A1C_3; cmpwi 3,0; beq 6f; mr 3,31; bl _s801F9A1C_4; mr 31,3; bl _s801F9A1C_5; mr. 3,3; beq 6f; add 9,3,3; add 9,9,31; sth 29,-2(9); b 6f; 1:; lis 3,-32704; mr 4,30; addi 3,3,-22524; bl _s801F9A1C_6; cmpwi 3,0; bne 3f; mr 3,31; bl _s801F9A1C_7; cmpwi 3,0; beq 6f; mr 3,31; bl _s801F9A1C_8; mr 31,3; lis 4,-32697; addi 4,4,24012; mr 5,28; addi 3,1,8; crxor 6,6,6; bl _s801F9A1C_9; lwz 9,0x8(1); li 4,0; cmpwi 9,0; beq 2f; lwz 4,0x0(9); 2:; cmpwi 4,0; beq 6f; mr 3,31; bl _s801F9A1C_10; b 6f; 3:; lis 3,-32704; mr 4,30; addi 3,3,-22516; bl _s801F9A1C_11; cmpwi 3,0; bne 6f; mr 3,31; bl _s801F9A1C_12; cmpwi 3,0; beq 6f; mr 3,31; bl _s801F9A1C_13; mr. 31,3; beq 6f; mr 3,31; bl _s801F9A1C_14; rlwinm 3,3,1,0,30; add 3,3,31; lhz 0,-2(3); cmpwi 0,95; bne 5f; lwz 0,-31536(13); cmpwi 0,0; bne 4f; li 3,120; bl _s801F9A1C_15; bl _s801F9A1C_16; stw 3,-31536(13); 4:; lis 4,28199; lwz 3,-31536(13); ori 4,4,30903; bl _s801F9A1C_17; b 6f; 5:; lis 4,-32704; mr 3,31; addi 4,4,-22264; bl _s801F9A1C_18; 6:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s801F9A1C_0();
extern "C" void _s801F9A1C_1();
extern "C" void _s801F9A1C_2();
extern "C" void _s801F9A1C_3();
extern "C" void _s801F9A1C_4();
extern "C" void _s801F9A1C_5();
extern "C" void _s801F9A1C_6();
extern "C" void _s801F9A1C_7();
extern "C" void _s801F9A1C_8();
extern "C" void _s801F9A1C_9();
extern "C" void _s801F9A1C_10();
extern "C" void _s801F9A1C_11();
extern "C" void _s801F9A1C_12();
extern "C" void _s801F9A1C_13();
extern "C" void _s801F9A1C_14();
extern "C" void _s801F9A1C_15();
extern "C" void _s801F9A1C_16();
extern "C" void _s801F9A1C_17();
extern "C" void _s801F9A1C_18();
extern "C" void f_801F9A1C() {}
