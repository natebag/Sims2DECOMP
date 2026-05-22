// 0x80208ECC InteractorModule::FloorPainter::CurrentSelectionIsValid(int (624 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 23,0x24(1); stw 0,0x4c(1); li 0,0; mr 23,4; stw 0,0x0(23); mr 28,3; lbz 0,0x60(28); andi. 9,0,1; beq 6f; addi 4,1,16; addi 5,1,20; addi 6,1,24; addi 7,1,28; li 26,0; bl _s80208ECC_0; addi 3,1,8; bl _s80208ECC_1; lwz 29,0x10(1); lwz 0,0x18(1); lwz 24,0x98(28); lwz 27,-21488(13); cmpw 29,0; bgt 4f; 0:; lwz 30,0x14(1); addi 25,29,1; lwz 0,0x1c(1); cmpw 30,0; bgt 3f; 1:; addi 3,1,8; mr 5,30; li 6,1; mr 4,29; bl _s80208ECC_2; lwz 9,0x0(27); addi 4,1,8; lha 3,0x88(9); lwz 0,0x8c(9); add 3,27,3; mtspr 8,0; blrl; mr 31,3; addi 4,1,8; mr 3,28; mr 5,31; bl _s80208ECC_3; cmpwi 3,0; beq 2f; cmpw 31,24; beq 2f; addi 26,26,1; 2:; lwz 0,0x1c(1); addi 30,30,1; cmpw 30,0; ble 1b; 3:; lwz 0,0x18(1); mr 29,25; cmpw 29,0; ble 0b; 4:; stw 26,0x0(23); lwz 0,0xa4(28); cmpwi 0,0; beq 5f; lwz 0,0x7c(28); li 31,0; cmpw 26,0; bgt 14f; cmpwi 26,0; beq 14f; li 31,1; b 14f; 5:; cmpwi 26,0; b 13f; 6:; andi. 9,0,2; beq 15f; lfs f1,0x24(28); li 4,1; lfs f2,0x20(28); addi 3,1,8; bl _s80208ECC_4; lwz 3,-21488(13); addi 4,1,8; lwz 9,0x0(3); lha 0,0xe8(9); lwz 9,0xec(9); add 3,3,0; mtspr 8,9; blrl; mr 31,3; lwz 3,-21472(13); cmpwi 3,0; beq 7f; mr 4,31; bl _s80208ECC_5; b 8f; 7:; li 3,0; 8:; li 27,0; cmpwi 3,0; beq 11f; cmpwi 31,0; beq 11f; addi 26,3,4; lwz 4,0x4(3); lwz 0,0x4(26); lwz 25,0x98(28); cmpw 4,0; beq 11f; lwz 29,-21488(13); mr 30,4; 9:; lwz 9,0x0(29); mr 4,30; lha 3,0x88(9); lwz 0,0x8c(9); add 3,29,3; mtspr 8,0; blrl; mr 31,3; addi 4,1,8; mr 3,28; mr 5,31; bl _s80208ECC_6; cmpwi 3,0; beq 10f; cmpw 31,25; beq 10f; addi 27,27,1; 10:; lwz 0,0x4(26); addi 30,30,3; cmpw 30,0; bne 9b; 11:; stw 27,0x0(23); lwz 0,0xa4(28); cmpwi 0,0; beq 12f; lwz 0,0x7c(28); cmpw cr7,27,0; cror 31,30,28; mfcr 31; rlwinm 31,31,0,31,31; b 14f; 12:; cmpwi 27,0; 13:; li 31,1; bgt 14f; li 31,0; 14:; addi 3,1,8; li 4,2; bl _s80208ECC_7; mr 3,31; b 16f; 15:; li 3,1; 16:; lwz 0,0x4c(1); mtspr 8,0; lmw 23,0x24(1); addi 1,1,72"
extern "C" void _s80208ECC_0();
extern "C" void _s80208ECC_1();
extern "C" void _s80208ECC_2();
extern "C" void _s80208ECC_3();
extern "C" void _s80208ECC_4();
extern "C" void _s80208ECC_5();
extern "C" void _s80208ECC_6();
extern "C" void _s80208ECC_7();
extern "C" void f_80208ECC() {}
