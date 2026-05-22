// 0x800A8ED8 AmbientScorePlayer::AddSoundBasedOnProbability(vector<ERAmbientSound (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,5; mr 29,3; mr 30,4; cmpwi 31,99; bgt 0f; cmpwi 6,0; beq 1f; 0:; bl _s800A8ED8_0; divwu 0,3,31; mullw 0,0,31; b 2f; 1:; bl _s800A8ED8_1; li 0,100; divwu 0,3,0; mulli 0,0,100; 2:; subf 3,0,3; cmpw 3,31; ble 4f; b 6f; 3:; mr 3,29; mr 4,9; bl _s800A8ED8_2; b 7f; 4:; lwz 0,0x4(30); lwz 4,0x0(30); cmpw 4,0; beq 6f; mr 11,0; 5:; lwz 9,0x0(4); lbz 0,0x1b(9); cmpw 3,0; ble 3b; addi 4,4,4; subf 3,0,3; cmpw 4,11; bne 5b; 6:; li 3,0; 7:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800A8ED8_0();
extern "C" void _s800A8ED8_1();
extern "C" void _s800A8ED8_2();
extern "C" void f_800A8ED8() {}
