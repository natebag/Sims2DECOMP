// 0x802EFED0 EAnimController::SetAllTrackSpeed(float) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x40(3); li 10,0; cmpw 10,0; bgelr; lis 9,-32702; li 8,0; lfs f0,-4316(9); fcmpu 7,f1,f0; 0:; lwz 0,0x44(3); add 11,8,0; lwz 9,0x30(11); andis. 0,9,1024; beq 1f; bgt cr7,3f; b 2f; 1:; ble cr7,3f; 2:; stfs f1,0x4c(11); b 4f; 3:; fneg f0,f1; stfs f0,0x4c(11); 4:; lwz 0,0x40(3); addi 10,10,1; addi 8,8,176; cmpw 10,0; blt 0b"
extern "C" void f_802EFED0() {}
