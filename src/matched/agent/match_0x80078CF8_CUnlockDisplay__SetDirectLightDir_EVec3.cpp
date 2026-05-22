// 0x80078CF8 CUnlockDisplay::SetDirectLightDir(EVec3, (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,6; mr 29,3; mr 31,4; cmpwi 30,3; bgt 3f; lwz 0,0x440(29); addi 9,30,1; cmpw 9,0; ble 0f; stw 9,0x440(29); 0:; rlwinm 0,30,2,0,29; addi 9,29,1192; stwx 5,9,0; lis 11,-32707; lfs f13,0x5fec(11); lfs f0,0x0(31); fcmpu 0,f0,f13; bne 1f; lfs f0,0x4(31); fcmpu 0,f0,f13; bne 1f; lfs f0,0x8(31); fcmpu 0,f0,f13; beq 2f; 1:; mr 3,31; mr 4,31; bl _s80078CF8_0; 2:; mulli 9,30,12; lwz 0,0x0(31); lwz 11,0x8(31); lwz 10,0x4(31); add 9,9,29; stw 0,0x4b8(9); addi 9,9,1208; stw 11,0x8(9); stw 10,0x4(9); 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80078CF8_0();
extern "C" void f_80078CF8() {}
