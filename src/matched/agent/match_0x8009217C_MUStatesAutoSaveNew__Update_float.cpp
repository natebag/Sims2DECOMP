// 0x8009217C MUStatesAutoSaveNew::Update(float) (352 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 3,0x8(31); lwz 8,0x90(3); cmpwi 8,0; bne 0f; lis 11,-32696; li 10,1; stw 8,0x58d8(11); addi 9,11,22744; stw 8,0x8(9); addi 11,9,8; lwz 0,0x4(9); li 4,2; addic 0,0,-1; subfe 0,0,0; rlwinm 0,0,0,29,29; stwx 10,11,0; b 4f; 0:; cmpwi 8,1; bne 3f; lwz 0,0x1c(31); cmpwi 0,1; bne 1f; mr 3,31; li 4,11; bl _s8009217C_0; li 0,2; stw 0,0x1c(31); b 8f; 1:; cmpwi 0,2; bne 2f; lwz 9,0x98(3); li 4,5; stw 8,0xac(9); lwz 11,0x8(31); lwz 3,0x98(11); bl _s8009217C_1; mr 3,31; li 4,14; bl _s8009217C_2; li 0,3; stw 0,0x1c(31); b 8f; 2:; cmpwi 0,3; bne 8f; b 6f; 3:; cmpwi 8,2; bne 8f; lwz 0,0x1c(31); cmpwi 0,1; bne 5f; lis 10,-32696; li 4,2; addi 11,10,22744; lwz 8,0x58d8(10); lwz 0,0x4(11); addi 7,11,8; rlwinm 0,0,2,0,29; stwx 8,7,0; lwz 9,0x4(11); lwz 0,0x58d8(10); addic 9,9,-1; subfe 9,9,9; rlwinm 9,9,0,29,29; subfic 11,0,0; adde 0,11,0; stwx 0,7,9; 4:; lwz 3,0x8(31); bl _s8009217C_3; b 8f; 5:; cmpwi 0,2; bne 7f; 6:; li 0,0; stw 0,0x90(3); b 8f; 7:; cmpwi 0,3; bne 8f; li 4,1; bl _s8009217C_4; 8:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8009217C_0();
extern "C" void _s8009217C_1();
extern "C" void _s8009217C_2();
extern "C" void _s8009217C_3();
extern "C" void _s8009217C_4();
extern "C" void f_8009217C() {}
