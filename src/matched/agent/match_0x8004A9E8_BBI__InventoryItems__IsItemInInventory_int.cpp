// 0x8004A9E8 BBI::InventoryItems::IsItemInInventory(int) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 28,4; li 30,0; bl _s8004A9E8_0; mr 29,3; cmpw 30,29; bge 2f; 0:; lwz 3,0x0(31); addi 31,31,4; cmpwi 3,0; beq 1f; bl _s8004A9E8_1; cmpw 3,28; bne 1f; li 3,1; b 3f; 1:; addi 30,30,1; cmpw 30,29; blt 0b; 2:; li 3,0; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8004A9E8_0();
extern "C" void _s8004A9E8_1();
extern "C" void f_8004A9E8() {}
