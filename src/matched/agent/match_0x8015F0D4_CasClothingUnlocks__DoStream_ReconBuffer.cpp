// 0x8015F0D4 CasClothingUnlocks::DoStream(ReconBuffer (248 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 23,0xc(1); stw 0,0x34(1); mr 25,3; mr 26,4; cmpwi 5,15; ble 6f; mr 27,25; li 24,0; addi 23,25,1280; 0:; add 30,25,24; li 29,32; 1:; li 31,0; mr 28,30; 2:; add 4,28,31; mr 3,26; li 5,1; addi 31,31,1; bl _s8015F0D4_0; cmpwi 31,39; ble 2b; addi 30,30,40; addic. 29,29,-1; bne 1b; addi 27,27,1280; addi 24,24,1280; cmpw 27,23; ble 0b; li 11,0; 3:; mulli 9,11,240; li 29,0; addi 27,11,1; addi 9,9,2560; add 28,25,9; 4:; mulli 0,29,30; li 31,0; addi 29,29,1; add 30,28,0; 5:; add 4,30,31; mr 3,26; li 5,1; addi 31,31,1; bl _s8015F0D4_1; cmpwi 31,29; ble 5b; cmpwi 29,7; ble 4b; mr 11,27; cmpwi 11,1; ble 3b; b 7f; 6:; lwz 0,0xc(26); cmpwi 0,0; bne 7f; mr 3,25; bl _s8015F0D4_2; 7:; lwz 0,0x34(1); mtspr 8,0; lmw 23,0xc(1); addi 1,1,48"
extern "C" void _s8015F0D4_0();
extern "C" void _s8015F0D4_1();
extern "C" void _s8015F0D4_2();
extern "C" void f_8015F0D4() {}
