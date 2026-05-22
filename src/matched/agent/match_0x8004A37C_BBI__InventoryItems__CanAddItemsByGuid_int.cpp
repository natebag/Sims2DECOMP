// 0x8004A37C BBI::InventoryItems::CanAddItemsByGuid(int, (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,5; mr 29,3; mr 5,6; mr. 30,4; beq 1f; cmpwi 31,0; li 3,0; ble 2f; mr 3,29; mr 4,30; bl _s8004A37C_0; mr. 3,3; beq 0f; bl _s8004A37C_1; add 3,3,31; cmpwi 7,3,99; cror 31,30,28; mfcr 3; rlwinm 3,3,0,31,31; b 2f; 0:; lwz 11,-21508(13); cmpwi 11,0; beq 1f; lwz 9,0x0(11); mr 4,30; lha 3,0x78(9); lwz 0,0x7c(9); add 3,11,3; mtspr 8,0; blrl; mr. 3,3; beq 1f; lwz 0,0x38(3); li 3,0; cmpwi 0,0; beq 2f; mr 3,0; bl _s8004A37C_2; mr 4,3; mr 3,29; bl _s8004A37C_3; addi 3,3,1; cmpwi 3,12; bgt 1f; cmpwi 7,31,99; cror 31,30,28; mfcr 3; rlwinm 3,3,0,31,31; b 2f; 1:; li 3,0; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8004A37C_0();
extern "C" void _s8004A37C_1();
extern "C" void _s8004A37C_2();
extern "C" void _s8004A37C_3();
extern "C" void f_8004A37C() {}
