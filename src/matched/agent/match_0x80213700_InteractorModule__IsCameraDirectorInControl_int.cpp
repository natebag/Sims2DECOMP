// 0x80213700 InteractorModule::IsCameraDirectorInControl(int) (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32697; rlwinm 3,3,2,0,29; addi 9,9,24012; addi 9,9,280; lwzx 9,9,3; cmpwi 9,0; beq 1f; lwz 0,0x160(9); li 9,0; cmpwi 0,0; beq 0f; cmpwi 0,8; beq 0f; li 9,1; 0:; cmpwi 9,0; li 3,1; bnelr; 1:; li 3,0"
extern "C" int f_80213700() {}
