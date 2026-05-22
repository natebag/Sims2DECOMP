// 0x802E9C24 EAnimController::AnimateTrack(EACTrack (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 11,4; mr 10,3; lwz 0,0x30(11); li 31,0; andis. 9,0,2048; bne 2f; lwz 0,0xa8(11); cmpwi 0,1; bne 1f; lwz 0,0x7c(11); li 9,1; cmpwi 0,0; bne 0f; li 9,0; 0:; cmpwi 9,0; beq 1f; lis 9,-32702; lfs f13,0x50(11); lfs f0,-4592(9); fcmpu 0,f13,f0; ble 1f; mr 3,10; mr 4,11; li 31,1; bl _s802E9C24_0; b 2f; 1:; lwz 0,0x28(11); cmpwi 0,0; beq 2f; mr 5,6; mr 4,11; lwz 7,0xc(10); mtspr 8,0; lwz 3,0x2c(11); lwz 6,0x24(10); blrl; 2:; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802E9C24_0();
extern "C" void f_802E9C24() {}
