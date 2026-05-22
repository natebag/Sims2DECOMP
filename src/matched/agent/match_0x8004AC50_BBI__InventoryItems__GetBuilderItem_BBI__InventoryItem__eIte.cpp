// 0x8004AC50 BBI::InventoryItems::GetBuilderItem(BBI::InventoryItem::eItemSubcategory, (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s8004AC50_0; cmpwi 3,-1; beq 0f; rlwinm 0,3,2,0,29; lwzx 3,31,0; b 1f; 0:; li 3,0; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8004AC50_0();
extern "C" void f_8004AC50() {}
