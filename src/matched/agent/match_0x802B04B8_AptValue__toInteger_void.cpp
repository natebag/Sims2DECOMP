// 0x802B04B8 AptValue::toInteger(void) (256 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); mr 9,3; lwz 0,0x0(9); andis. 11,0,2048; bne 0f; li 3,0; b 8f; 0:; rlwinm 0,0,0,25,31; cmpwi 0,6; beq 6f; bgt 1f; cmpwi 0,1; beq 2f; cmpwi 0,5; beq 5f; b 7f; 1:; cmpwi 0,7; beq 5f; cmpwi 0,42; bne 7f; 2:; lwz 0,0x0(9); mr 3,9; rlwinm 0,0,0,25,31; cmpwi 0,1; beq 3f; lwz 3,0x24(9); 3:; lwz 9,0xc(3); addi 11,3,12; lhz 0,0x2(9); cmpwi 0,2; ble 4f; lbz 0,0x8(9); addi 3,9,8; cmpwi 0,48; bne 4f; lbz 0,0x1(3); cmpwi 0,120; bne 4f; li 4,0; li 5,16; bl _s802B04B8_0; b 8f; 4:; lwz 3,0x0(11); addi 3,3,8; bl _s802B04B8_1; b 8f; 5:; lwz 3,0xc(9); b 8f; 6:; lfs f0,0xc(9); fctiwz f13,f0; stfd f13,0x8(1); lwz 3,0xc(1); b 8f; 7:; lwz 0,-22936(13); li 3,1; cmpw 9,0; bne 8f; li 3,0; 8:; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s802B04B8_0();
extern "C" void _s802B04B8_1();
extern "C" void f_802B04B8() {}
