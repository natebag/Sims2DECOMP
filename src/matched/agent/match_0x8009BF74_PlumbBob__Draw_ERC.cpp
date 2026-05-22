// 0x8009BF74 PlumbBob::Draw(ERC (520 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 0,0; beq 0f; lwz 30,0x0(31); bl _s8009BF74_0; mr 4,30; bl _s8009BF74_1; li 0,0; stw 0,0x0(31); stw 0,0x8(31); 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16; blr; blr; blr; stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 9,0x0(30); lwz 11,0xc(9); addi 11,11,-1; stw 11,0xc(9); lwz 3,0x0(30); lwz 0,0xc(3); cmpwi 0,0; bne 1f; li 4,2; bl _s8009BF74_2; lwz 30,0x0(30); bl _s8009BF74_3; mr 4,30; bl _s8009BF74_4; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16; blr; lwz 9,0x0(3); lwz 3,0xc(9); blr; stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s8009BF74_5; cmpwi 3,0; bne 2f; li 3,0; b 3f; 2:; lwz 9,0x0(31); lwz 3,0x0(9); 3:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16; blr; lwz 9,0x0(3); lwz 3,0x0(9); blr; lwz 3,0x0(3); addi 3,3,4; blr; stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; bl _s8009BF74_6; cmplw 30,3; blt 4f; bl _s8009BF74_7; 4:; mr 3,31; bl _s8009BF74_8; lbzx 3,3,30; extsb 3,3; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16; blr; stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; bl _s8009BF74_9; cmplw 30,3; li 3,0; bge 5f; mr 3,31; bl _s8009BF74_10; lbzx 3,3,30; extsb 3,3; 5:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 5,0; li 6,-1; bl _s8009BF74_11; subfic 0,3,0; adde 3,0,3; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 0,3; li 5,0; mr 3,4; mr 4,0; bl _s8009BF74_12; subfic 0,3,0; adde 3,0,3; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8009BF74_0();
extern "C" void _s8009BF74_1();
extern "C" void _s8009BF74_2();
extern "C" void _s8009BF74_3();
extern "C" void _s8009BF74_4();
extern "C" void _s8009BF74_5();
extern "C" void _s8009BF74_6();
extern "C" void _s8009BF74_7();
extern "C" void _s8009BF74_8();
extern "C" void _s8009BF74_9();
extern "C" void _s8009BF74_10();
extern "C" void _s8009BF74_11();
extern "C" void _s8009BF74_12();
extern "C" void f_8009BF74() {}
