// 0x803652E8 LLTracerPop (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 10,-25840(13); mr 8,3; cmpwi 10,0; beq 0f; addi 10,10,-1; lis 9,-32690; addi 9,9,-6668; rlwinm 0,10,2,0,29; lwzx 11,9,0; li 3,0; stw 10,-25840(13); stw 11,0x90(8); blr; 0:; li 3,-1"
extern "C" void f_803652E8() {}
