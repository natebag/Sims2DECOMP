// 0x8004A878 BBI::InventoryItems::CountItemsByCategory(BBI::InventoryItem::eItemCategory) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,4; mr 31,3; cmpwi 29,3; bgt 0f; cmpwi 29,1; bge 1f; 0:; li 3,0; b 5f; 1:; mr 3,31; li 28,0; bl _s8004A878_0; cmpw 28,3; bge 4f; mr 30,31; mr 31,3; 2:; lwz 3,0x0(30); addi 30,30,4; cmpwi 3,0; beq 3f; bl _s8004A878_1; cmpw 3,29; bne 3f; addi 28,28,1; 3:; addic. 31,31,-1; bne 2b; 4:; mr 3,28; 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8004A878_0();
extern "C" void _s8004A878_1();
extern "C" void f_8004A878() {}
