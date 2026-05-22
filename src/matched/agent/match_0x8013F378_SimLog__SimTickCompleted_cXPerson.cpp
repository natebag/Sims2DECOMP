// 0x8013F378 SimLog::SimTickCompleted(cXPerson (348 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 29,3; mr 30,4; lwz 0,0x0(29); cmpwi 0,0; beq 6f; bl _s8013F378_0; mr. 28,3; beq 6f; lwz 9,0x4(30); addi 31,28,20; lha 3,0xe8(9); lwz 0,0xec(9); add 3,30,3; mtspr 8,0; blrl; mr 27,3; mr 3,28; mr 4,27; bl _s8013F378_1; cmpwi 3,0; bne 3f; mr 3,29; mr 4,28; bl _s8013F378_2; mr. 29,3; beq 6f; lwz 0,0x0(29); li 9,1; cmpwi 0,0; bne 0f; li 9,0; 0:; cmpwi 9,0; bne 1f; li 0,1; stw 0,0x38(31); 1:; mr 3,31; mr 4,30; bl _s8013F378_3; lwz 0,0x28(31); cmpwi 0,0; beq 2f; mr 3,29; mr 4,31; bl _s8013F378_4; 2:; mr 3,28; mr 5,27; mr 4,30; bl _s8013F378_5; 3:; lwz 9,0x28(31); addi 9,9,1; stw 9,0x28(31); lwz 11,0x4(30); lha 3,0x1c8(11); lwz 0,0x1cc(11); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,0; beq 4f; lwz 9,0x30(31); addi 9,9,1; stw 9,0x30(31); b 6f; 4:; lwz 9,0x0(30); lwz 10,0x0(9); lwz 11,0x18(10); lha 3,0x68(11); lwz 0,0x6c(11); add 3,10,3; mtspr 8,0; blrl; cmpwi 3,44; beq 5f; cmpwi 3,64; bne 6f; 5:; lwz 9,0x2c(31); addi 9,9,1; stw 9,0x2c(31); 6:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8013F378_0();
extern "C" void _s8013F378_1();
extern "C" void _s8013F378_2();
extern "C" void _s8013F378_3();
extern "C" void _s8013F378_4();
extern "C" void _s8013F378_5();
extern "C" void f_8013F378() {}
