// 0x8004A720 BBI::InventoryItems::Clear(void) (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,3; bl _s8004A720_0; mr. 0,3; mtspr 9,0; ble 2f; mfspr 30,9; li 28,0; li 31,0; 0:; lwzx 11,31,29; cmpwi 11,0; beq 1f; lwz 9,0x8(11); li 4,3; lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 1:; stwx 28,31,29; addic. 30,30,-1; addi 31,31,4; bne 0b; 2:; li 3,1; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8004A720_0();
extern "C" void f_8004A720() {}
