// 0x800AD724 cBoxX::~cBoxX(void) (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; lis 9,-32698; lwz 3,0x68(30); addi 9,9,-5864; stw 9,0x78(30); li 29,0; mr 28,4; stw 29,-32088(13); cmpwi 3,0; beq 0f; bl _s800AD724_0; stw 29,0x68(30); 0:; addi 31,30,32; lwz 0,0x8(31); cmpwi 0,0; beq 1f; lwz 9,0x4(31); mr 3,31; lwz 4,0x4(9); bl _s800AD724_1; lwz 9,0x4(31); stw 9,0x8(9); lwz 11,0x4(31); stw 29,0x4(11); lwz 9,0x4(31); stw 9,0xc(9); stw 29,0x8(31); 1:; lwz 3,0x4(31); cmpwi 3,0; beq 2f; li 4,24; bl _s800AD724_2; 2:; andi. 0,28,1; beq 3f; mr 3,30; bl _s800AD724_3; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800AD724_0();
extern "C" void _s800AD724_1();
extern "C" void _s800AD724_2();
extern "C" void _s800AD724_3();
extern "C" void f_800AD724() {}
