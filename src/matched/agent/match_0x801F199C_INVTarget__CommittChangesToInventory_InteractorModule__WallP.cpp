// 0x801F199C INVTarget::CommittChangesToInventory(InteractorModule::WallPainter::CallbackData (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 28,3; mr. 30,4; beq 4f; lwz 6,0x10(30); cmpwi 6,0; ble 0f; lwz 3,0x90(28); li 4,5; lwz 5,0xc(30); bl _s801F199C_0; b 1f; 0:; bge 1f; lwz 3,0x90(28); neg 6,6; lwz 5,0xc(30); li 4,5; bl _s801F199C_1; 1:; addi 9,30,20; lwz 11,0x14(30); lwz 0,0x4(9); mr 27,9; li 29,0; subf 0,11,0; srawi. 9,0,3; ble 4f; li 31,0; 2:; lwz 11,0x14(30); add 9,11,31; lwz 6,0x4(9); cmpwi 6,0; beq 3f; lwzx 5,11,31; li 4,5; lwz 3,0x90(28); bl _s801F199C_2; 3:; lwz 0,0x4(27); addi 29,29,1; lwz 9,0x14(30); addi 31,31,8; subf 0,9,0; srawi 0,0,3; cmpw 29,0; blt 2b; 4:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s801F199C_0();
extern "C" void _s801F199C_1();
extern "C" void _s801F199C_2();
extern "C" void f_801F199C() {}
