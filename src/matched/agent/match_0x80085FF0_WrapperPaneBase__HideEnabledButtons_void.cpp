// 0x80085FF0 WrapperPaneBase::HideEnabledButtons(void) (308 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 24,0x8(1); stw 0,0x2c(1); mr 29,3; lwz 0,0x4(29); andi. 9,0,65280; beq 4f; lwz 8,0x38(29); cmpwi 8,0; beq 0f; lis 9,-32697; lis 4,-32707; lwz 3,0x5e80(9); addi 4,4,29260; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s80085FF0_0; b 1f; 0:; lis 9,-32697; lis 4,-32707; lis 8,-32707; lwz 3,0x5e80(9); addi 4,4,29260; addi 8,8,29280; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s80085FF0_1; 1:; lis 9,-32697; lis 11,-32702; addi 24,9,24012; addi 25,11,15952; li 30,0; addi 28,29,64; li 26,256; lis 27,-32707; li 31,0; 2:; lwzx 9,31,28; cmpwi 9,0; beq 3f; lwz 0,0x4(9); andi. 9,0,1; beq 3f; lwz 9,0x4(29); slw 0,26,30; and. 11,9,0; beq 3f; lwz 3,0xb4(24); addi 4,27,29428; lwzx 8,31,25; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s80085FF0_2; 3:; addi 30,30,1; addi 31,31,4; cmpwi 30,6; ble 2b; lis 9,-32697; lis 4,-32707; lwz 3,0x5e80(9); addi 4,4,29300; li 5,0; li 6,0; li 7,0; crxor 6,6,6; bl _s80085FF0_3; 4:; lwz 0,0x2c(1); mtspr 8,0; lmw 24,0x8(1); addi 1,1,40"
extern "C" void _s80085FF0_0();
extern "C" void _s80085FF0_1();
extern "C" void _s80085FF0_2();
extern "C" void _s80085FF0_3();
extern "C" void f_80085FF0() {}
