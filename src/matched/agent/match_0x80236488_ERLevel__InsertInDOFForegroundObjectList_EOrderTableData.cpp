// 0x80236488 ERLevel::InsertInDOFForegroundObjectList(EOrderTableData (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; bl _s80236488_0; mr. 3,3; beq 4f; addis 8,31,3; mr 11,3; mr 9,30; li 10,48; 0:; lwz 0,0x0(9); addic. 10,10,-24; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); lwz 0,0xc(9); stw 0,0xc(11); lwz 0,0x10(9); stw 0,0x10(11); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(11); addi 11,11,24; bne 0b; lwz 0,0x0(9); stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 9,-7444(8); cmpwi 9,0; beq 1f; lwz 4,0x0(30); lwz 0,0x0(9); cmpw 4,0; bgt 2f; 1:; stw 9,0x28(3); stw 3,-7444(8); b 4f; 2:; mr 11,9; lwz 9,0x28(11); cmpwi 9,0; beq 3f; lwz 0,0x0(9); cmpw 4,0; bgt 2b; 3:; lwz 0,0x28(11); stw 0,0x28(3); stw 3,0x28(11); 4:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80236488_0();
extern "C" void f_80236488() {}
