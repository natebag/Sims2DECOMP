// 0x8004A524 BBI::InventoryItems::RemoveItemsByGuid(int, (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; mr 30,5; mr 5,6; bl _s8004A524_0; mr. 31,3; li 3,0; beq 2f; mr 3,31; bl _s8004A524_1; subf. 4,30,3; ble 0f; mr 3,31; bl _s8004A524_2; b 1f; 0:; mr 3,31; bl _s8004A524_3; mr 30,3; mr 4,31; mr 3,29; bl _s8004A524_4; 1:; mr 3,30; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8004A524_0();
extern "C" void _s8004A524_1();
extern "C" void _s8004A524_2();
extern "C" void _s8004A524_3();
extern "C" void _s8004A524_4();
extern "C" void f_8004A524() {}
