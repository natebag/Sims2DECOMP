// 0x8004A468 BBI::InventoryItems::AddItemsByGuid(int, (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 28,5; mr 30,3; mr 5,6; mr. 27,4; beq 0f; cmpwi 28,0; li 3,0; beq 4f; mr 3,30; mr 4,27; bl _s8004A468_0; mr. 31,3; bne 2f; mr 3,30; bl _s8004A468_1; mr 29,3; cmpwi 29,-1; li 3,0; beq 4f; mr 4,27; mr 3,30; bl _s8004A468_2; mr. 31,3; bne 1f; 0:; li 3,0; b 4f; 1:; rlwinm 0,29,2,0,29; stwx 31,30,0; 2:; mr 3,31; mr 30,28; bl _s8004A468_3; add 4,3,28; cmpwi 4,99; ble 3f; addi 30,4,-99; 3:; mr 3,31; bl _s8004A468_4; mr 3,30; 4:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8004A468_0();
extern "C" void _s8004A468_1();
extern "C" void _s8004A468_2();
extern "C" void _s8004A468_3();
extern "C" void _s8004A468_4();
extern "C" void f_8004A468() {}
