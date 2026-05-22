// 0x8004A904 BBI::InventoryItems::GetItemsByCategory(BBI::InventoryItem::eItemCategory, (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 24,0x8(1); stw 0,0x2c(1); mr 28,3; mr 24,4; mr 25,6; mr. 31,5; li 3,0; beq 3f; mr 3,28; mr 30,31; bl _s8004A904_0; li 29,0; mr 26,3; li 27,0; li 31,0; b 1f; 0:; addi 31,31,4; addi 27,27,1; 1:; cmpw 27,26; bge 2f; lwzx 3,31,28; cmpwi 3,0; beq 0b; bl _s8004A904_1; cmpw 3,24; bne 0b; lwzx 0,31,28; addi 29,29,1; cmpw 29,25; stw 0,0x0(30); addi 30,30,4; blt 0b; 2:; mr 3,29; 3:; lwz 0,0x2c(1); mtspr 8,0; lmw 24,0x8(1); addi 1,1,40"
extern "C" void _s8004A904_0();
extern "C" void _s8004A904_1();
extern "C" void f_8004A904() {}
