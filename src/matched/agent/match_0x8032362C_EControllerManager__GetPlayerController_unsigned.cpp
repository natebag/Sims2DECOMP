// 0x8032362C EControllerManager::GetPlayerController(unsigned (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s8032362C_0; cmpwi 3,-1; beq 0f; lis 9,-32688; rlwinm 0,3,2,0,29; addi 9,9,-12424; lwzx 3,9,0; b 1f; 0:; li 3,0; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8032362C_0();
extern "C" void f_8032362C() {}
