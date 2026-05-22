// 0x80336054 ENgcMovie::PlayerSkip(void) (424 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32691; li 30,0; addi 31,9,14656; lwz 0,0xa0(31); cmpwi 0,0; beq 11f; lbz 0,0xa4(31); cmpwi 0,4; bne 11f; bl _s80336054_0; lbz 0,0xa7(31); cmpwi 0,0; beq 2f; lbz 0,0xa6(31); lwz 11,0xf4(31); lwz 9,0xc0(31); xori 0,0,1; andi. 10,0,1; add 11,11,9; beq 0f; lwz 0,0x50(31); cmpw 11,0; bne 0f; lwz 3,0xfc(31); cmpwi 3,0; beq 2f; bl _s80336054_1; stw 30,0xfc(31); b 2f; 0:; lis 9,-32691; addi 31,9,14656; lwz 3,0xfc(31); cmpwi 3,0; beq 1f; bl _s80336054_2; 1:; li 3,1; li 30,1; bl _s80336054_3; lwz 9,0xf4(31); stw 3,0xfc(31); addi 9,9,1; stw 9,0xf4(31); 2:; lis 9,-32691; addi 11,9,14656; lwz 9,0xf8(11); cmpwi 9,0; beq 3f; lwz 9,0xc(9); lwz 0,0xc0(11); add 11,9,0; b 4f; 3:; lwz 9,0xc0(11); addi 11,9,-1; 4:; lis 9,-32691; addi 9,9,14656; lbz 0,0xa6(9); xori 0,0,1; andi. 10,0,1; beq 5f; lwz 9,0x50(9); addi 9,9,-1; cmpw 11,9; bne 5f; li 0,0; b 9f; 5:; lis 9,-32691; addi 31,9,14656; lwz 3,0xf8(31); cmpwi 3,0; beq 6f; bl _s80336054_4; 6:; li 3,1; bl _s80336054_5; lbz 0,0xa7(31); stw 3,0xf8(31); cmpwi 0,0; beq 8f; lwz 9,0xf0(31); addi 9,9,1; stw 9,0xf0(31); bl _s80336054_6; cmpwi 3,0; li 3,1; bne 7f; li 3,0; 7:; lwz 9,0xd8(31); addi 9,9,-1; stw 9,0xd8(31); bl _s80336054_7; 8:; li 0,1; 9:; cmpwi 30,0; bne 10f; cmpwi 0,0; beq 11f; 10:; li 3,1; b 12f; 11:; li 3,0; 12:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80336054_0();
extern "C" void _s80336054_1();
extern "C" void _s80336054_2();
extern "C" void _s80336054_3();
extern "C" void _s80336054_4();
extern "C" void _s80336054_5();
extern "C" void _s80336054_6();
extern "C" void _s80336054_7();
extern "C" void f_80336054() {}
