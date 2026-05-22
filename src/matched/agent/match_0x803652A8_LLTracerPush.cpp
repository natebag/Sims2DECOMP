// 0x803652A8 LLTracerPush (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-25840(13); cmpwi 0,7; bgt 0f; addi 10,13,-25840; lwz 8,0x90(3); lwz 11,0x0(10); lis 9,-32690; addi 9,9,-6668; li 3,0; rlwinm 0,11,2,0,29; addi 11,11,1; stwx 8,9,0; stw 11,0x0(10); blr; 0:; li 3,-1"
extern "C" void f_803652A8() {}
