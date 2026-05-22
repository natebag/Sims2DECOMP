// 0x8011C65C cXPerson::~cXPerson(void) (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-192(1); mfspr 0,8; stmw 30,0xb8(1); stw 0,0xc4(1); lis 9,-32698; mr 31,3; addi 9,9,11720; lwz 8,0x0(31); stw 9,0x4(31); lis 11,-32698; addi 0,11,12696; lis 10,-32698; lwz 11,0x0(8); addi 10,10,4016; mr. 30,4; stw 0,0x18(11); lwz 9,0x0(31); stw 10,0x4(9); bne 1f; addi 8,1,8; mr 11,0; mr 7,8; li 0,168; 0:; lwz 10,0x0(11); addic. 0,0,-24; stw 10,0x0(8); lwz 10,0x4(11); stw 10,0x4(8); lwz 10,0x8(11); stw 10,0x8(8); lwz 10,0xc(11); stw 10,0xc(8); lwz 10,0x10(11); stw 10,0x10(8); lwz 10,0x14(11); addi 11,11,24; stw 10,0x14(8); addi 8,8,24; bne 0b; lwz 10,0x0(11); lis 9,-32698; lhz 0,0x31a0(9); stw 10,0x0(8); lwz 10,0x4(11); stw 10,0x4(8); lwz 9,0x0(31); lwz 11,0x0(9); stw 7,0x18(11); lwz 10,0x0(31); lwz 9,0x0(10); addi 9,9,-8; subf 9,9,31; add 0,0,9; sth 0,0x10(1); 1:; andi. 0,30,2; beq 2f; lwz 3,0x0(31); li 4,0; bl _s8011C65C_0; lwz 9,0x0(31); li 4,0; lwz 3,0x0(9); bl _s8011C65C_1; 2:; andi. 0,30,1; beq 3f; mr 3,31; bl _s8011C65C_2; 3:; lwz 0,0xc4(1); mtspr 8,0; lmw 30,0xb8(1); addi 1,1,192"
extern "C" void _s8011C65C_0();
extern "C" void _s8011C65C_1();
extern "C" void _s8011C65C_2();
extern "C" void f_8011C65C() {}
