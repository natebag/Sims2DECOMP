// 0x8004AB10 BBI::InventoryItems::AddBuilderItem(BBI::InventoryItem::eItemSubcategory, (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 30,3; mr 28,4; mr 27,5; mr. 26,6; li 3,0; beq 3f; mr 3,30; bl _s8004AB10_0; mr. 31,3; bne 1f; mr 3,30; li 4,2; bl _s8004AB10_1; cmpwi 3,11; li 3,0; bgt 3f; mr 3,30; bl _s8004AB10_2; mr 29,3; cmpwi 29,-1; li 3,0; beq 3f; mr 4,28; mr 5,27; mr 3,30; bl _s8004AB10_3; mr. 31,3; bne 0f; li 3,0; b 3f; 0:; rlwinm 0,29,2,0,29; stwx 31,30,0; 1:; mr 3,31; mr 30,26; bl _s8004AB10_4; add 4,3,26; cmpwi 4,99; ble 2f; addi 30,4,-99; 2:; mr 3,31; bl _s8004AB10_5; mr 3,30; 3:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s8004AB10_0();
extern "C" void _s8004AB10_1();
extern "C" void _s8004AB10_2();
extern "C" void _s8004AB10_3();
extern "C" void _s8004AB10_4();
extern "C" void _s8004AB10_5();
extern "C" void f_8004AB10() {}
