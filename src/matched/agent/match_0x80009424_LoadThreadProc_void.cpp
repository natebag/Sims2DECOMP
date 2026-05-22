// 0x80009424 LoadThreadProc(void (368 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-536(1); mfspr 0,8; stmw 28,0x208(1); stw 0,0x21c(1); mr 31,3; addi 28,1,264; addi 29,1,8; bl _s80009424_0; addi 3,3,-1; add 4,31,3; cmplw 4,31; blt 3f; lbzx 0,31,3; b 1f; 0:; addi 4,4,-1; cmplw 4,31; blt 3f; lbz 0,0x0(4); 1:; extsb 0,0; cmpwi 0,47; beq 2f; cmpwi 0,92; bne 0b; 2:; cmplw 4,31; blt 3f; addi 4,4,1; mr 3,28; bl _s80009424_1; b 4f; 3:; mr 3,28; mr 4,31; bl _s80009424_2; 4:; addi 3,1,8; mr 4,28; bl _s80009424_3; lis 3,-32693; li 5,0; li 6,0; mr 4,29; addi 3,3,31260; bl _s80009424_4; mr 30,3; bl _s80009424_5; lwz 9,0x100(31); stw 3,0x4(9); mr 3,30; bl _s80009424_6; mr 4,28; mr 3,29; bl _s80009424_7; lis 4,-32707; mr 3,29; addi 4,4,-11128; bl _s80009424_8; lwz 9,0x100(31); mr 4,29; lwz 3,0x4(9); bl _s80009424_9; lwz 9,0x100(31); mr 4,28; stw 3,0x1c(9); mr 3,29; lwz 9,0x100(31); lwz 0,0x1c(9); stw 0,0x108(31); bl _s80009424_10; lis 4,-32707; mr 3,29; addi 4,4,-11120; bl _s80009424_11; lwz 9,0x100(31); mr 4,29; lwz 3,0x4(9); bl _s80009424_12; stw 3,0x10c(31); lwz 4,0x100(31); mr 3,28; bl _s80009424_13; addi 10,13,-32740; lis 11,-32697; lwz 9,0x0(10); addi 11,11,-1792; li 3,0; rlwinm 0,9,2,0,29; addi 9,9,1; stwx 31,11,0; stw 9,0x0(10); lwz 0,0x21c(1); mtspr 8,0; lmw 28,0x208(1); addi 1,1,536"
extern "C" void _s80009424_0();
extern "C" void _s80009424_1();
extern "C" void _s80009424_2();
extern "C" void _s80009424_3();
extern "C" void _s80009424_4();
extern "C" void _s80009424_5();
extern "C" void _s80009424_6();
extern "C" void _s80009424_7();
extern "C" void _s80009424_8();
extern "C" void _s80009424_9();
extern "C" void _s80009424_10();
extern "C" void _s80009424_11();
extern "C" void _s80009424_12();
extern "C" void _s80009424_13();
extern "C" void f_80009424() {}
