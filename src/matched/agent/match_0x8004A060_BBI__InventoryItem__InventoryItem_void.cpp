// 0x8004A060 BBI::InventoryItem::InventoryItem(void) (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 11,-32698; mr 9,3; li 0,0; addi 11,11,-18144; li 10,0; stw 11,0x8(9); stb 0,0x3(9); stw 10,0x4(9); stb 0,0x0(9); stb 0,0x1(9); stb 0,0x2(9)"
extern "C" void f_8004A060() {}
