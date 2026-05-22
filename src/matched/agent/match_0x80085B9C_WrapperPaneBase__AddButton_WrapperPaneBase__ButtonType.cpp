// 0x80085B9C WrapperPaneBase::AddButton(WrapperPaneBase::ButtonType, (800 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 21,0x1c(1); stw 0,0x4c(1); mr 26,3; mr 24,4; rlwinm 28,24,2,0,29; addi 27,26,64; lwzx 31,27,28; mr 21,5; mr 22,6; cmpwi 31,0; bne 12f; li 3,112; li 25,1; bl _s80085B9C_0; addi 29,26,8; lis 11,-32707; mr 30,3; lfs f0,0x72e4(11); li 0,2; lis 11,-32698; stw 0,0x0(30); addi 11,11,-11112; stfs f0,0x18(30); addi 9,30,32; stw 11,0x1c(30); stfs f0,0xc(30); mr 3,9; stfs f0,0x10(30); addi 23,1,8; stfs f0,0x14(30); stw 25,0x4(30); stw 31,0x8(30); stw 31,0x24(9); bl _s80085B9C_1; mr 3,30; stw 31,0x6c(30); bl _s80085B9C_2; mr 3,30; bl _s80085B9C_3; lis 9,-32698; mr 3,30; addi 9,9,-11832; stw 9,0x1c(30); bl _s80085B9C_4; stwx 30,27,28; mr 3,30; stw 25,0x4(30); li 4,5; bl _s80085B9C_5; lwz 30,0x4(29); lwz 0,0xc(29); lwzx 9,27,28; cmpw 30,0; stw 9,0x8(1); beq 0f; stw 9,0x0(30); mr 25,28; lwz 9,0x4(29); addi 9,9,4; stw 9,0x4(29); b 11f; 0:; lwz 0,0x8(26); addi 10,1,16; stw 25,0x10(1); addi 11,1,12; subf 0,0,30; srawi 9,0,2; stw 9,0xc(1); cmplwi 9,1; bge 1f; mr 11,10; 1:; lwz 0,0x0(11); add. 0,9,0; beq 3f; rlwinm 0,0,2,0,29; mr 28,0; cmplwi 0,128; ble 2f; mr 3,28; bl _s80085B9C_6; mr 31,3; b 4f; 2:; mr 3,28; bl _s80085B9C_7; mr 31,3; b 4f; 3:; li 31,0; li 28,0; 4:; lwz 4,0x0(29); cmpw 30,4; beq 5f; subf 30,4,30; mr 3,31; mr 5,30; bl _s80085B9C_8; add 0,3,30; b 6f; 5:; mr 0,31; 6:; lwz 9,0x10(1); mr 30,0; rlwinm 25,24,2,0,29; addi 27,26,64; mtspr 9,9; cmpwi 9,0; beq 8f; 7:; lwz 0,0x0(23); stw 0,0x0(30); addi 30,30,4; bdnz 7b; 8:; lwz 3,0x0(29); lwz 0,0xc(29); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 10f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 9f; bl _s80085B9C_9; b 10f; 9:; bl _s80085B9C_10; 10:; add 0,28,31; stw 31,0x0(29); stw 0,0xc(29); stw 30,0x4(29); 11:; lwzx 0,27,25; cmpwi 0,0; beq 15f; 12:; rlwinm 0,24,2,0,29; addi 9,26,64; lwzx 3,9,0; mr 4,22; mr 25,0; bl _s80085B9C_11; cmpwi 21,0; beq 15f; li 0,256; lwz 9,0x4(26); slw 0,0,24; and. 11,9,0; bne 15f; lwz 8,0x38(26); cmpwi 8,0; beq 13f; lis 9,-32697; lis 4,-32707; lwz 3,0x5e80(9); addi 4,4,29260; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s80085B9C_12; b 14f; 13:; lis 9,-32697; lis 4,-32707; lis 8,-32707; lwz 3,0x5e80(9); addi 4,4,29260; addi 8,8,29280; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s80085B9C_13; 14:; lis 9,-32702; lis 30,-32697; addi 9,9,15952; addi 30,30,24012; lwzx 8,9,25; lis 4,-32707; lwz 3,0xb4(30); lis 9,-32707; addi 9,9,29404; addi 4,4,29388; li 5,0; li 6,0; li 7,2; crxor 6,6,6; bl _s80085B9C_14; lwz 3,0xb4(30); lis 4,-32707; addi 4,4,29300; li 5,0; li 6,0; li 7,0; crxor 6,6,6; bl _s80085B9C_15; lwz 9,0x4(26); li 0,256; slw 0,0,24; or 9,9,0; stw 9,0x4(26); 15:; lwz 0,0x4c(1); mtspr 8,0; lmw 21,0x1c(1); addi 1,1,72"
extern "C" void _s80085B9C_0();
extern "C" void _s80085B9C_1();
extern "C" void _s80085B9C_2();
extern "C" void _s80085B9C_3();
extern "C" void _s80085B9C_4();
extern "C" void _s80085B9C_5();
extern "C" void _s80085B9C_6();
extern "C" void _s80085B9C_7();
extern "C" void _s80085B9C_8();
extern "C" void _s80085B9C_9();
extern "C" void _s80085B9C_10();
extern "C" void _s80085B9C_11();
extern "C" void _s80085B9C_12();
extern "C" void _s80085B9C_13();
extern "C" void _s80085B9C_14();
extern "C" void _s80085B9C_15();
extern "C" void f_80085B9C() {}
