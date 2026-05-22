// 0x8016170C CasGenetics::LoadGrandparentPortraits(void) (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; mfcr 12; stmw 24,0x18(1); stw 0,0x3c(1); stw 12,0x14(1); mr 28,3; lwz 9,0x0(28); lwz 0,0x4(28); subf 0,9,0; rlwinm. 9,0,30,2,31; beq 0f; lwz 9,0x10(28); lwz 0,0x14(28); subf 0,9,0; rlwinm. 9,0,30,2,31; bne 1f; 0:; li 3,0; b 4f; 1:; li 9,0; addi 25,1,8; lis 24,-32692; 2:; addi 26,9,1; li 31,0; cmpwi 4,9,1; rlwinm 27,9,4,0,27; li 29,0; 3:; addi 3,1,8; mr 5,31; mfcr 4; rlwinm 4,4,19,31,31; addi 31,31,1; bl _s8016170C_0; lwz 3,0x8(1); bl _s8016170C_1; mr 4,3; li 6,0; lwzx 30,27,28; li 5,0; addi 3,24,-7364; bl _s8016170C_2; lwzx 9,30,29; addi 29,29,4; stw 3,0x4(9); mr 3,25; lwz 4,0x8(1); bl _s8016170C_3; cmpwi 31,25; ble 3b; mr 9,26; cmpwi 9,1; ble 2b; li 3,1; 4:; lwz 0,0x3c(1); lwz 12,0x14(1); mtspr 8,0; lmw 24,0x18(1); mtcrf 8,12; addi 1,1,56"
extern "C" void _s8016170C_0();
extern "C" void _s8016170C_1();
extern "C" void _s8016170C_2();
extern "C" void _s8016170C_3();
extern "C" void f_8016170C() {}
