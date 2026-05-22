// 0x80016BD4 ESimsCam::SetMode(ESimsCam::CameraMode) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32697; lwz 0,0x4(3); addi 9,9,24012; addi 9,9,280; rlwinm 0,0,2,0,29; lwzx 9,9,0; cmpwi 9,0; beq 1f; lwz 0,0x160(9); li 9,0; cmpwi 0,0; beq 0f; cmpwi 0,8; beq 0f; li 9,1; 0:; cmpwi 9,0; bnelr; 1:; cmpwi 4,2; bne 2f; lwz 4,0x3d0(3); 2:; lwz 0,0x3cc(3); stw 4,0x3cc(3); stw 0,0x3d0(3)"
extern "C" void f_80016BD4() {}
