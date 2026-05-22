// 0x8004AA80 BBI::InventoryItems::CanAddBuilderItem(BBI::InventoryItem::eItemSubcategory, (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr. 30,6; li 3,0; beq 2f; mr 3,31; bl _s8004AA80_0; mr. 3,3; beq 0f; bl _s8004AA80_1; add 3,3,30; cmpwi 7,3,99; cror 31,30,28; mfcr 3; rlwinm 3,3,0,31,31; b 2f; 0:; mr 3,31; li 4,2; bl _s8004AA80_2; addi 3,3,1; cmpwi 3,12; bgt 1f; cmpwi 7,30,99; cror 31,30,28; mfcr 3; rlwinm 3,3,0,31,31; b 2f; 1:; li 3,0; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8004AA80_0();
extern "C" void _s8004AA80_1();
extern "C" void _s8004AA80_2();
extern "C" void f_8004AA80() {}
