// 0x801F71B8 INVTarget::GetOnMsgInvShpCanColor(char (516 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 28,0x28(1); stw 0,0x3c(1); mr 29,3; mr 28,4; addi 31,1,24; lbz 4,0x3251(29); mr 5,31; addi 6,1,32; li 30,0; bl _s801F71B8_0; lwz 0,0x20(1); cmpwi 0,9; beq 0f; blt 4f; cmpwi 0,10; beq 1f; cmpwi 0,11; beq 2f; b 4f; 0:; lwz 0,0x4(31); cmpwi 0,-1; beq 11f; mr 3,31; bl _s801F71B8_1; b 3f; 1:; mr 3,31; bl _s801F71B8_2; b 3f; 2:; mr 3,31; bl _s801F71B8_3; 3:; lis 30,-32692; mr 31,3; addi 30,30,-17444; mr 4,31; li 5,0; mr 3,30; li 6,0; bl _s801F71B8_4; lwz 0,0x3c(3); mr 4,31; mr 3,30; li 5,1; xori 30,0,2; subfic 9,30,0; adde 30,9,30; bl _s801F71B8_5; b 11f; 4:; lwz 3,0x18(1); bl _s801F71B8_6; lis 30,-32692; mr 31,3; addi 30,30,-17444; mr 4,31; li 5,0; li 6,0; mr 3,30; bl _s801F71B8_7; lwz 0,0x3c(3); mr 4,31; mr 3,30; li 5,1; xori 30,0,2; subfic 9,30,0; adde 30,9,30; bl _s801F71B8_8; cmpwi 30,0; beq 11f; lwz 3,0x18(1); bl _s801F71B8_9; addi 4,1,8; bl _s801F71B8_10; cmpwi 3,0; beq 7f; lwz 0,0x84(29); addi 9,13,-28688; lwz 11,0x0(29); rlwinm 0,0,2,0,29; lwz 5,0x8(1); lwzx 4,9,0; cmpwi 11,0; lwz 6,0xc(1); lwz 7,0x10(1); beq 5f; lwz 3,0x20(29); cmpwi 3,0; beq 5f; lwz 8,0x7c(29); li 9,0; bl _s801F71B8_11; b 6f; 5:; li 3,0; 6:; stw 3,0x3258(29); b 10f; 7:; lwz 0,0x3258(29); cmpwi 0,0; beq 10f; lwz 0,0x84(29); addi 9,13,-28688; lwz 11,0x0(29); rlwinm 0,0,2,0,29; lwzx 4,9,0; cmpwi 11,0; beq 8f; lwz 3,0x20(29); cmpwi 3,0; beq 8f; bl _s801F71B8_12; b 9f; 8:; li 3,0; 9:; xori 0,3,1; stw 0,0x3258(29); 10:; li 0,0; stb 0,0x3252(29); 11:; cmpwi 30,0; li 5,0; beq 12f; li 5,1; 12:; lis 4,-32704; mr 3,28; addi 4,4,-30836; crxor 6,6,6; bl _s801F71B8_13; lwz 0,0x3c(1); mtspr 8,0; lmw 28,0x28(1); addi 1,1,56"
extern "C" void _s801F71B8_0();
extern "C" void _s801F71B8_1();
extern "C" void _s801F71B8_2();
extern "C" void _s801F71B8_3();
extern "C" void _s801F71B8_4();
extern "C" void _s801F71B8_5();
extern "C" void _s801F71B8_6();
extern "C" void _s801F71B8_7();
extern "C" void _s801F71B8_8();
extern "C" void _s801F71B8_9();
extern "C" void _s801F71B8_10();
extern "C" void _s801F71B8_11();
extern "C" void _s801F71B8_12();
extern "C" void _s801F71B8_13();
extern "C" void f_801F71B8() {}
