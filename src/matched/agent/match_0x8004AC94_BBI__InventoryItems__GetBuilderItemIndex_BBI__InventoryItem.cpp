// 0x8004AC94 BBI::InventoryItems::GetBuilderItemIndex(BBI::InventoryItem::eItemSubcategory, (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 31,3; mr 26,4; mr 27,5; bl _s8004AC94_0; li 29,0; mr 28,3; cmplw 29,28; bge 2f; mr 30,31; 0:; lwz 31,0x0(30); addi 30,30,4; cmpwi 31,0; beq 1f; mr 3,31; bl _s8004AC94_1; cmpw 3,26; bne 1f; mr 3,31; bl _s8004AC94_2; cmpw 3,27; bne 1f; mr 3,29; b 3f; 1:; addi 29,29,1; cmplw 29,28; blt 0b; 2:; li 3,-1; 3:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s8004AC94_0();
extern "C" void _s8004AC94_1();
extern "C" void _s8004AC94_2();
extern "C" void f_8004AC94() {}
