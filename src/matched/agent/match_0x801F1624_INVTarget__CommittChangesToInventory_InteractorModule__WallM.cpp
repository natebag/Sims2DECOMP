// 0x801F1624 INVTarget::CommittChangesToInventory(InteractorModule::WallManipulator::CallbackData (592 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; mfcr 12; stmw 25,0xc(1); stw 0,0x2c(1); stw 12,0x8(1); mr 28,3; mr. 29,4; beq 17f; lwz 5,0xc(29); cmpwi 5,-1; bne 1f; lwz 6,0x10(29); cmpwi 6,0; ble 0f; lwz 3,0x90(28); li 4,4; li 5,-1; bl _s801F1624_0; b 3f; 0:; bge 3f; lwz 3,0x90(28); neg 6,6; li 4,4; li 5,-1; bl _s801F1624_1; b 3f; 1:; lwz 6,0x10(29); cmpwi 6,0; ble 2f; lwz 3,0x90(28); li 4,2; bl _s801F1624_2; b 3f; 2:; bge 3f; lwz 3,0x90(28); neg 6,6; li 4,2; bl _s801F1624_3; 3:; addi 9,29,20; lis 11,-32697; lwz 0,0x4(9); mr 25,9; lwz 10,0x14(29); li 8,0; lwz 9,0x5ea8(11); addi 27,29,36; subf 0,10,0; mr 7,10; lwz 31,0x0(9); addi 26,29,52; srawi. 9,0,3; ble 10f; cmpwi 4,31,0; 4:; li 5,0; addi 30,8,1; b 7f; 5:; rlwinm 11,5,2,0,29; rlwinm 9,8,3,0,28; lwzx 10,31,11; add 6,7,9; lwzx 11,7,9; lwz 0,0xc(10); cmpw 0,11; bne 6f; lwz 6,0x4(6); cmpwi 6,0; beq 9f; lwz 3,0x90(28); li 4,2; bl _s801F1624_4; b 9f; 6:; addi 5,5,1; 7:; li 0,0; beq cr4,8f; lwz 0,-4(31); 8:; cmpw 5,0; blt 5b; 9:; lwz 9,0x14(29); mr 8,30; lwz 0,0x4(25); mr 7,9; subf 0,9,0; srawi 0,0,3; cmpw 8,0; blt 4b; 10:; lwz 9,0x24(29); li 30,0; lwz 0,0x4(27); subf 0,9,0; srawi. 9,0,3; ble 13f; li 31,0; 11:; lwz 11,0x24(29); add 9,11,31; lwz 6,0x4(9); cmpwi 6,0; beq 12f; lwzx 5,11,31; li 4,5; lwz 3,0x90(28); bl _s801F1624_5; 12:; lwz 0,0x4(27); addi 30,30,1; lwz 9,0x24(29); addi 31,31,8; subf 0,9,0; srawi 0,0,3; cmpw 30,0; blt 11b; 13:; lwz 9,0x34(29); li 30,0; lwz 0,0x4(26); subf 0,9,0; srawi. 9,0,3; ble 17f; li 31,0; 14:; lwz 11,0x34(29); add 9,11,31; lwz 6,0x4(9); cmpwi 6,0; ble 15f; lwzx 5,11,31; li 4,1; lwz 3,0x90(28); bl _s801F1624_6; b 16f; 15:; bge 16f; lwzx 5,11,31; neg 6,6; lwz 3,0x90(28); li 4,1; bl _s801F1624_7; 16:; lwz 0,0x4(26); addi 30,30,1; lwz 9,0x34(29); addi 31,31,8; subf 0,9,0; srawi 0,0,3; cmpw 30,0; blt 14b; 17:; lwz 0,0x2c(1); lwz 12,0x8(1); mtspr 8,0; lmw 25,0xc(1); mtcrf 8,12; addi 1,1,40"
extern "C" void _s801F1624_0();
extern "C" void _s801F1624_1();
extern "C" void _s801F1624_2();
extern "C" void _s801F1624_3();
extern "C" void _s801F1624_4();
extern "C" void _s801F1624_5();
extern "C" void _s801F1624_6();
extern "C" void _s801F1624_7();
extern "C" void f_801F1624() {}
