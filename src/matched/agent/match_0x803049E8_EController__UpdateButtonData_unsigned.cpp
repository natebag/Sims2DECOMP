// 0x803049E8 EController::UpdateButtonData(unsigned (296 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 30,3; li 29,0; lwz 11,0x1fc(30); li 26,1; lwz 0,0x0(11); stw 0,0x4(11); lwz 9,0x1fc(30); stw 4,0x0(9); lwz 11,0x1fc(30); lwz 9,0x4(11); lwz 0,0x0(11); andc 27,0,9; andc 28,9,0; 0:; lwz 3,0x1fc(30); mr 4,29; slw 31,26,29; bl _s803049E8_0; cmpwi 3,0; bne 3f; and. 0,27,31; beq 1f; and. 0,28,31; bne 2f; lwz 3,0x1fc(30); mr 4,29; li 5,1; bl _s803049E8_1; lwz 3,0x1fc(30); mr 4,29; li 5,1; bl _s803049E8_2; b 3f; 1:; and. 0,28,31; beq 3f; 2:; and. 0,27,31; bne 3f; lwz 3,0x1fc(30); mr 4,29; li 5,0; bl _s803049E8_3; lwz 3,0x1fc(30); mr 4,29; li 5,1; bl _s803049E8_4; 3:; addi 29,29,1; cmpwi 29,31; ble 0b; lwz 9,0x1fc(30); lwz 0,0x8(9); lwz 11,0x0(9); or 0,0,11; stw 0,0x8(9); lwz 11,0x1fc(30); lwz 9,0x10(11); lwz 0,0x0(11); orc 0,9,0; stw 0,0x10(11); lwz 9,0x1fc(30); lwz 0,0x20(9); or 0,0,28; stw 0,0x20(9); lwz 11,0x1fc(30); lwz 0,0x18(11); or 0,0,27; stw 0,0x18(11); lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s803049E8_0();
extern "C" void _s803049E8_1();
extern "C" void _s803049E8_2();
extern "C" void _s803049E8_3();
extern "C" void _s803049E8_4();
extern "C" void f_803049E8() {}
