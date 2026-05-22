// 0x802BDD30 EAStringC::UTF8_Mid(int) (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 29,3; mr 27,4; mr. 30,5; bge 0f; li 30,0; 0:; lwz 9,0x0(27); li 31,0; cmpw 31,30; addi 28,9,8; mr 3,28; bge 2f; 1:; addi 4,1,8; bl _s802BDD30_0; lwz 0,0x8(1); cmpwi 0,0; beq 3f; addi 31,31,1; cmpw 31,30; blt 1b; 2:; cmpwi 3,0; bne 4f; lis 11,-32700; addi 0,11,-6476; stw 0,0x0(29); lhz 9,-6476(11); addi 9,9,1; sth 9,-6476(11); b 5f; 3:; li 3,0; b 2b; 4:; subf 5,28,3; mr 4,27; mr 3,29; bl _s802BDD30_1; 5:; mr 3,29; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s802BDD30_0();
extern "C" void _s802BDD30_1();
extern "C" void f_802BDD30() {}
