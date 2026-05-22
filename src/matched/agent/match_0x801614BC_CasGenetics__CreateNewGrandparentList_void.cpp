// 0x801614BC CasGenetics::CreateNewGrandparentList(void) (592 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-144(1); mfspr 0,8; mfcr 12; stmw 20,0x60(1); stw 0,0x94(1); stw 12,0x5c(1); mr 25,3; lis 20,-32706; lis 21,-32706; bl _s801614BC_0; li 0,0; addi 23,1,72; stw 0,0x48(1); li 9,0; addi 24,1,40; 0:; cmpwi 4,9,1; li 27,0; rlwinm 26,9,4,0,27; addi 22,9,1; 1:; li 3,8; bl _s801614BC_1; bl _s801614BC_2; stw 3,0x48(1); li 3,292; bl _s801614BC_3; bl _s801614BC_4; lwz 9,0x48(1); mfcr 0; rlwinm 0,0,19,31,31; stw 3,0x0(9); stw 0,0x84(3); bne cr4,2f; lis 9,-32706; addi 6,9,-4160; b 3f; 2:; lis 9,-32706; addi 6,9,-4152; 3:; addi 3,1,8; li 4,32; addi 5,20,-4164; add 29,26,25; crxor 6,6,6; bl _s801614BC_5; mr 6,27; li 4,32; addi 5,21,-4144; mr 3,24; crxor 6,6,6; bl _s801614BC_6; lwz 9,0x48(1); li 5,32; addi 3,1,8; lwz 4,0x0(9); addi 4,4,4; bl _s801614BC_7; lwz 9,0x48(1); mr 3,24; li 5,32; lwz 4,0x0(9); addi 4,4,68; bl _s801614BC_8; lwz 30,0x4(29); lwz 0,0xc(29); cmpw 30,0; beq 4f; lwz 0,0x48(1); addi 27,27,1; stw 0,0x0(30); lwz 9,0x4(29); addi 9,9,4; stw 9,0x4(29); b 15f; 4:; lwzx 0,26,25; li 9,1; stw 9,0x50(1); addi 10,1,80; subf 0,0,30; addi 11,1,76; srawi 9,0,2; stw 9,0x4c(1); cmplwi 9,1; bge 5f; mr 11,10; 5:; lwz 0,0x0(11); add. 0,9,0; beq 7f; rlwinm 0,0,2,0,29; mr 28,0; cmplwi 0,128; ble 6f; mr 3,28; bl _s801614BC_9; mr 31,3; b 8f; 6:; mr 3,28; bl _s801614BC_10; mr 31,3; b 8f; 7:; li 31,0; li 28,0; 8:; lwz 4,0x0(29); cmpw 30,4; beq 9f; subf 30,4,30; mr 3,31; mr 5,30; bl _s801614BC_11; add 0,3,30; b 10f; 9:; mr 0,31; 10:; lwz 9,0x50(1); mr 30,0; addi 27,27,1; mtspr 9,9; cmpwi 9,0; beq 12f; 11:; lwz 0,0x0(23); stw 0,0x0(30); addi 30,30,4; bdnz 11b; 12:; lwz 3,0x0(29); lwz 0,0xc(29); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 14f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 13f; bl _s801614BC_12; b 14f; 13:; bl _s801614BC_13; 14:; add 0,28,31; stw 31,0x0(29); stw 0,0xc(29); stw 30,0x4(29); 15:; cmplwi 27,25; ble 1b; mr 9,22; cmplwi 9,1; ble 0b; lwz 0,0x94(1); lwz 12,0x5c(1); mtspr 8,0; lmw 20,0x60(1); mtcrf 8,12; addi 1,1,144"
extern "C" void _s801614BC_0();
extern "C" void _s801614BC_1();
extern "C" void _s801614BC_2();
extern "C" void _s801614BC_3();
extern "C" void _s801614BC_4();
extern "C" void _s801614BC_5();
extern "C" void _s801614BC_6();
extern "C" void _s801614BC_7();
extern "C" void _s801614BC_8();
extern "C" void _s801614BC_9();
extern "C" void _s801614BC_10();
extern "C" void _s801614BC_11();
extern "C" void _s801614BC_12();
extern "C" void _s801614BC_13();
extern "C" void f_801614BC() {}
