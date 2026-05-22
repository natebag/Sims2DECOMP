// 0x802D7EF4 ENgcSNFile::BufferReadRequest(unsigned (292 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 31,3; mr 28,4; mr 29,5; li 26,0; li 27,1; 0:; lwz 0,0x30(31); lwz 9,0x14(31); mr 4,0; add 0,29,0; cmplw 0,9; ble 1f; subf 0,9,0; subf. 29,0,29; bne 1f; li 3,0; b 7f; 1:; lwz 0,0x3c(31); cmpwi 0,0; beq 4f; lwz 9,0x14(31); rlwinm 0,4,0,30,31; li 30,2048; subf 4,0,4; stw 0,0x38(31); cmplw 30,9; ble 2f; mr 30,9; 2:; subf 9,4,9; cmplwi 9,2047; bgt 3f; addi 0,9,31; rlwinm 30,0,0,0,26; 3:; lwz 3,0x2c(31); li 5,0; bl _s802D7EF4_0; lwz 3,0x2c(31); mr 5,30; lwz 4,0x34(31); bl _s802D7EF4_1; stw 26,0x3c(31); 4:; lwz 0,0x38(31); subfic 3,0,2048; cmpw 29,3; ble 5f; mr 30,3; stw 27,0x3c(31); b 6f; 5:; mr 30,29; 6:; lwz 0,0x34(31); mr 3,28; lwz 4,0x38(31); mr 5,30; add 4,0,4; crxor 6,6,6; bl _s802D7EF4_2; lwz 9,0x38(31); cmpwi 30,0; lwz 0,0x30(31); add 9,9,30; add 0,0,30; stw 9,0x38(31); stw 0,0x30(31); beq 0b; mr 3,30; 7:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s802D7EF4_0();
extern "C" void _s802D7EF4_1();
extern "C" void _s802D7EF4_2();
extern "C" void f_802D7EF4() {}
