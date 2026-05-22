// 0x800D9484 cXObject::~cXObject(void) (360 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-200(1); mfspr 0,8; stmw 29,0xbc(1); stw 0,0xcc(1); mr 31,3; lis 9,-32698; addi 9,9,4016; lwz 10,0x0(31); lis 11,-32698; stw 9,0x4(31); addi 11,11,5344; mr. 29,4; stw 11,0x18(10); bne 1f; addi 8,1,8; li 0,168; mr 7,8; 0:; lwz 10,0x0(11); addic. 0,0,-24; stw 10,0x0(8); lwz 10,0x4(11); stw 10,0x4(8); lwz 10,0x8(11); stw 10,0x8(8); lwz 10,0xc(11); stw 10,0xc(8); lwz 10,0x10(11); stw 10,0x10(8); lwz 10,0x14(11); addi 11,11,24; stw 10,0x14(8); addi 8,8,24; bne 0b; lwz 10,0x0(11); lis 9,-32698; lhz 0,0x14e8(9); stw 10,0x0(8); lwz 10,0x4(11); stw 10,0x4(8); lwz 11,0x0(31); stw 7,0x18(11); lwz 9,0x0(31); addi 9,9,-8; subf 9,9,31; add 0,0,9; sth 0,0x10(1); 1:; lwz 3,-21488(13); lwz 9,0x0(3); lha 0,0xd8(9); lwz 9,0xdc(9); add 3,3,0; mtspr 8,9; blrl; mr 30,3; mr 4,31; bl _s800D9484_0; cmpwi 3,0; bne 2f; mr 3,30; mr 4,31; bl _s800D9484_1; 2:; lwz 4,0x0(31); lwz 0,0x10(4); cmpwi 0,0; beq 3f; lwz 3,-21432(13); addi 4,4,16; bl _s800D9484_2; 3:; lwz 11,0x0(31); li 0,0; lwz 3,-21432(13); mr 4,31; stw 0,0x10(11); lwz 9,0x0(31); stw 0,0x14(9); bl _s800D9484_3; andi. 0,29,2; beq 4f; lwz 3,0x0(31); li 4,0; bl _s800D9484_4; 4:; andi. 0,29,1; beq 5f; mr 3,31; bl _s800D9484_5; 5:; lwz 0,0xcc(1); mtspr 8,0; lmw 29,0xbc(1); addi 1,1,200"
extern "C" void _s800D9484_0();
extern "C" void _s800D9484_1();
extern "C" void _s800D9484_2();
extern "C" void _s800D9484_3();
extern "C" void _s800D9484_4();
extern "C" void _s800D9484_5();
extern "C" void f_800D9484() {}
