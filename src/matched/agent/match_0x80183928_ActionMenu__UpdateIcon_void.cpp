// 0x80183928 ActionMenu::UpdateIcon(void) (488 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lbz 0,0xa0(31); addi 9,31,112; lbz 30,0x7(31); rlwinm 0,0,2,0,29; lwzx 3,9,0; bl _s80183928_0; mr 4,30; bl _s80183928_1; mr 30,3; lwz 5,0x50(30); cmpwi 5,0; beq 2f; lwz 10,0x0(31); cmpwi 10,0; beq 1f; lwz 0,0xa8(31); addi 9,13,-31472; lwz 11,0x0(10); rlwinm 0,0,2,0,29; lwzx 4,9,0; cmpwi 11,0; beq 0f; lwz 3,0x1c(10); cmpwi 3,0; beq 0f; lwz 6,0x7c(10); li 7,0; bl _s80183928_2; 0:; lwz 10,0x0(31); addi 9,13,-31464; lwz 0,0xa8(31); lwz 11,0x0(10); rlwinm 0,0,2,0,29; lwz 5,0x50(30); lwzx 4,9,0; cmpwi 11,0; beq 1f; lwz 3,0x1c(10); cmpwi 3,0; beq 1f; lwz 6,0x7c(10); li 7,0; bl _s80183928_3; 1:; li 0,1; b 8f; 2:; lwz 5,0x54(30); cmpwi 5,0; beq 5f; lwz 10,0x0(31); cmpwi 10,0; beq 4f; lwz 0,0xa8(31); addi 9,13,-31472; lwz 11,0x0(10); rlwinm 0,0,2,0,29; lwzx 4,9,0; cmpwi 11,0; beq 3f; lwz 3,0x1c(10); cmpwi 3,0; beq 3f; lwz 6,0x7c(10); li 7,0; bl _s80183928_4; 3:; lwz 10,0x0(31); addi 9,13,-31464; lwz 0,0xa8(31); lwz 11,0x0(10); rlwinm 0,0,2,0,29; lwz 5,0x54(30); lwzx 4,9,0; cmpwi 11,0; beq 4f; lwz 3,0x1c(10); cmpwi 3,0; beq 4f; lwz 6,0x7c(10); li 7,0; bl _s80183928_5; 4:; li 0,1; b 8f; 5:; lwz 0,0xa4(31); cmpwi 0,0; beq 9f; lwz 3,0x0(31); cmpwi 3,0; beq 7f; lwz 0,0xa8(31); addi 9,13,-31472; lwz 11,0x0(3); rlwinm 0,0,2,0,29; lwzx 4,9,0; cmpwi 11,0; beq 6f; lwz 3,0x1c(3); cmpwi 3,0; beq 6f; bl _s80183928_6; 6:; lwz 3,0x0(31); addi 9,13,-31464; lwz 0,0xa8(31); lwz 11,0x0(3); rlwinm 0,0,2,0,29; lwzx 4,9,0; cmpwi 11,0; beq 7f; lwz 3,0x1c(3); cmpwi 3,0; beq 7f; bl _s80183928_7; 7:; li 0,0; 8:; stw 0,0xa4(31); 9:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80183928_0();
extern "C" void _s80183928_1();
extern "C" void _s80183928_2();
extern "C" void _s80183928_3();
extern "C" void _s80183928_4();
extern "C" void _s80183928_5();
extern "C" void _s80183928_6();
extern "C" void _s80183928_7();
extern "C" void f_80183928() {}
