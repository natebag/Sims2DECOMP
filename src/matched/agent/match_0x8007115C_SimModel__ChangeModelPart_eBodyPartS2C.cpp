// 0x8007115C SimModel::ChangeModelPart(eBodyPartS2C, (328 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; mfcr 12; stmw 27,0x2c(1); stw 0,0x44(1); stw 12,0x28(1); mr 30,3; mr 29,4; mr 31,6; mr 28,7; mr. 5,5; bne 1f; rlwinm 0,29,2,0,29; addi 9,30,104; lwzx 11,9,0; cmpwi 11,0; beq 0f; bl _s8007115C_0; li 3,1; b 7f; 0:; li 3,0; b 7f; 1:; rlwinm 0,29,2,0,29; addi 9,30,104; lwzx 9,9,0; cmpwi 9,0; beq 2f; lwz 9,0x120(9); cmpwi 9,0; beq 2f; lwz 0,0x8(9); li 3,0; cmpw 0,5; beq 7f; 2:; mr 4,29; mr 3,30; bl _s8007115C_1; cmpwi 4,31,0; mr 27,3; addi 5,1,8; lwz 3,0x138(30); mr 4,29; li 6,7; mr 31,5; cmpwi 3,28,0; bl _s8007115C_2; addi 28,1,32; 3:; lwz 5,0x0(31); addi 31,31,4; cmpwi 5,26; beq 4f; mr 3,30; mr 4,29; li 6,0; bl _s8007115C_3; 4:; cmplw 31,28; ble 3b; beq cr4,5f; mr 3,30; mr 4,29; bl _s8007115C_4; 5:; mr 3,30; mr 4,29; bl _s8007115C_5; mr 3,30; bl _s8007115C_6; beq cr3,6f; mulli 11,29,10; lis 9,-32696; addi 9,9,22168; mr 3,30; add 11,11,9; lbz 4,0x1(11); bl _s8007115C_7; 6:; mr 3,27; 7:; lwz 0,0x44(1); lwz 12,0x28(1); mtspr 8,0; lmw 27,0x2c(1); mtcrf 24,12; addi 1,1,64"
extern "C" void _s8007115C_0();
extern "C" void _s8007115C_1();
extern "C" void _s8007115C_2();
extern "C" void _s8007115C_3();
extern "C" void _s8007115C_4();
extern "C" void _s8007115C_5();
extern "C" void _s8007115C_6();
extern "C" void _s8007115C_7();
extern "C" void f_8007115C() {}
