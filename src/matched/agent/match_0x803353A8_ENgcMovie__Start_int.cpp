// 0x803353A8 ENgcMovie::Start(int, (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; cmpwi 4,-1; bne 1f; lwz 9,0x24(31); lwz 11,0x28(31); lhz 0,0x4(9); cmplw 11,0; ble 0f; li 0,0; stw 0,0x18(31); b 2f; 0:; subf 0,11,0; rlwinm 0,0,31,1,31; stw 0,0x18(31); b 2f; 1:; stw 4,0x18(31); 2:; cmpwi 5,-1; bne 4f; lwz 9,0x24(31); lwz 11,0x2c(31); lhz 0,0x6(9); cmplw 11,0; ble 3f; li 0,0; stw 0,0x1c(31); b 5f; 3:; subf 0,11,0; rlwinm 0,0,31,1,31; stw 0,0x1c(31); b 5f; 4:; stw 5,0x1c(31); 5:; mr 3,31; bl _s803353A8_0; lwz 0,0x18(31); lwz 9,0x1c(31); stw 0,0x0(31); stw 9,0x4(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s803353A8_0();
extern "C" void f_803353A8() {}
