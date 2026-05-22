// 0x8004A59C BBI::InventoryItems::DeleteItem(BBI::InventoryItem (388 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; mr. 31,4; li 3,0; beq 10f; mr 3,31; li 30,-1; bl _s8004A59C_0; cmpwi 3,2; beq 2f; bgt 0f; cmpwi 3,1; beq 1f; b 5f; 0:; cmpwi 3,3; bne 5f; 1:; mr 3,31; bl _s8004A59C_1; mr 30,3; mr 3,31; bl _s8004A59C_2; mr 5,3; mr 4,30; mr 3,29; bl _s8004A59C_3; b 4f; 2:; mr 3,31; bl _s8004A59C_4; cmpwi 3,1; bne 3f; mr 3,31; bl _s8004A59C_5; mr 30,3; mr 3,31; bl _s8004A59C_6; mr 5,3; mr 4,30; mr 3,29; bl _s8004A59C_7; b 4f; 3:; mr 3,31; bl _s8004A59C_8; mr 30,3; mr 3,31; bl _s8004A59C_9; mr 5,3; mr 4,30; mr 3,29; bl _s8004A59C_10; 4:; mr 30,3; 5:; cmpwi 30,-1; bne 6f; li 3,0; b 10f; 6:; rlwinm 31,30,2,0,29; lwzx 11,29,31; cmpwi 11,0; beq 7f; lwz 9,0x8(11); li 4,3; lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 7:; li 0,0; addi 30,30,1; stwx 0,29,31; cmpwi 30,35; bgt 9f; rlwinm 9,30,2,0,29; lwzx 0,29,9; cmpwi 0,0; beq 9f; addi 0,9,-4; li 10,0; add 11,0,29; 8:; lwzx 0,9,29; addi 30,30,1; cmpwi 30,35; stw 0,0x0(11); stwx 10,9,29; addi 11,11,4; addi 9,9,4; bgt 9f; lwzx 0,9,29; cmpwi 0,0; bne 8b; 9:; li 3,1; 10:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8004A59C_0();
extern "C" void _s8004A59C_1();
extern "C" void _s8004A59C_2();
extern "C" void _s8004A59C_3();
extern "C" void _s8004A59C_4();
extern "C" void _s8004A59C_5();
extern "C" void _s8004A59C_6();
extern "C" void _s8004A59C_7();
extern "C" void _s8004A59C_8();
extern "C" void _s8004A59C_9();
extern "C" void _s8004A59C_10();
extern "C" void f_8004A59C() {}
