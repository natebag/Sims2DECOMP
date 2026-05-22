// 0x8004A144 BBI::InventoryItem::DoStream(ReconBuffer (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,3; mr. 30,4; li 3,0; beq 2f; mr 3,30; mr 4,31; li 5,1; lwz 29,0x8(30); bl _s8004A144_0; mr 3,30; addi 4,31,1; li 5,1; bl _s8004A144_1; mr 3,30; addi 4,31,2; li 5,1; bl _s8004A144_2; mr 3,30; addi 4,31,3; li 5,1; bl _s8004A144_3; addi 4,31,4; mr 3,30; li 5,1; bl _s8004A144_4; lwz 9,0xc(30); cmpwi 9,0; bne 1f; lwz 0,0x8(30); stb 9,0x8(1); subf 0,29,0; subfic 31,0,8; cmpwi 31,0; ble 1f; 0:; mr 3,30; addi 4,1,8; li 5,1; bl _s8004A144_5; addic. 31,31,-1; bgt 0b; 1:; li 3,1; 2:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s8004A144_0();
extern "C" void _s8004A144_1();
extern "C" void _s8004A144_2();
extern "C" void _s8004A144_3();
extern "C" void _s8004A144_4();
extern "C" void _s8004A144_5();
extern "C" void f_8004A144() {}
