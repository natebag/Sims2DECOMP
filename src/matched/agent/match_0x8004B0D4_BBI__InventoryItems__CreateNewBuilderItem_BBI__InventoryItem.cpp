// 0x8004B0D4 BBI::InventoryItems::CreateNewBuilderItem(BBI::InventoryItem::eItemSubcategory, (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,5; mr. 30,4; li 3,0; beq 0f; li 3,12; bl _s8004B0D4_0; bl _s8004B0D4_1; mr. 31,3; li 3,0; beq 0f; li 4,2; mr 3,31; bl _s8004B0D4_2; mr 4,30; mr 3,31; bl _s8004B0D4_3; mr 4,29; mr 3,31; bl _s8004B0D4_4; mr 3,31; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8004B0D4_0();
extern "C" void _s8004B0D4_1();
extern "C" void _s8004B0D4_2();
extern "C" void _s8004B0D4_3();
extern "C" void _s8004B0D4_4();
extern "C" void f_8004B0D4() {}
