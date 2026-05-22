// 0x8004B148 BBI::InventoryItems::CreateNewItemFromSelector(ObjSelector (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr. 29,4; li 3,0; beq 2f; lwz 3,0x38(29); cmpwi 3,0; bne 1f; 0:; li 3,0; b 2f; 1:; bl _s8004B148_0; mr 31,3; cmpwi 31,3; bgt 0b; cmpwi 31,1; blt 0b; li 3,12; bl _s8004B148_1; bl _s8004B148_2; mr 30,3; mr 4,31; bl _s8004B148_3; li 4,1; mr 3,30; bl _s8004B148_4; mr 3,29; bl _s8004B148_5; mr 4,3; mr 3,30; bl _s8004B148_6; mr 3,30; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8004B148_0();
extern "C" void _s8004B148_1();
extern "C" void _s8004B148_2();
extern "C" void _s8004B148_3();
extern "C" void _s8004B148_4();
extern "C" void _s8004B148_5();
extern "C" void _s8004B148_6();
extern "C" void f_8004B148() {}
