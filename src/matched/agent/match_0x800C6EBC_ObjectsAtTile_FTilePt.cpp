// 0x800C6EBC ObjectsAtTile(FTilePt (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 29,0x24(1); stw 0,0x34(1); mr 30,3; addi 3,1,8; bl _s800C6EBC_0; addi 29,1,8; addi 3,1,16; mr 4,29; li 5,0; bl _s800C6EBC_1; addi 9,1,16; lwz 11,0x10(1); lwz 10,0x8(9); mr 3,29; lwz 0,0x4(9); li 4,2; stw 11,0x0(30); stw 0,0x4(30); stw 10,0x8(30); bl _s800C6EBC_2; mr 3,30; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x24(1); addi 1,1,48"
extern "C" void _s800C6EBC_0();
extern "C" void _s800C6EBC_1();
extern "C" void _s800C6EBC_2();
extern "C" void f_800C6EBC() {}
