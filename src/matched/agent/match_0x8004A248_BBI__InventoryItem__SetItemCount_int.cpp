// 0x8004A248 BBI::InventoryItem::SetItemCount(int) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr 31,4; bl _s8004A248_0; cmpwi 31,0; bge 0f; li 31,0; b 1f; 0:; cmpwi 31,99; ble 1f; li 31,99; 1:; stb 31,0x1(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8004A248_0();
extern "C" void f_8004A248() {}
