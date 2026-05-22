// 0x800A8524 AmbientScorePlayer::SetListenerCount(int) (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stw 0,0x2c(1); lwz 5,0x20(3); lis 9,-18725; addi 3,3,32; ori 9,9,28087; lwz 11,0x4(3); addi 6,1,8; subf 0,5,11; mullw 0,0,9; srawi 0,0,2; cmplw 4,0; bge 2f; mulli 0,4,28; add 0,0,5; lwz 11,0x4(3); mr 9,0; cmpw 0,11; beq 1f; 0:; addi 9,9,28; cmpw 9,11; bne 0b; 1:; stw 0,0x4(3); b 3f; 2:; subf 5,0,4; mr 4,11; bl _s800A8524_0; 3:; lwz 0,0x2c(1); mtspr 8,0; addi 1,1,40"
extern "C" void _s800A8524_0();
extern "C" void f_800A8524() {}
