// 0x8036FF10 IsSjisTrailByte (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 0,3,0,24,31; cmplwi 0,64; li 4,0; addi 5,4,0; blt 0f; cmplwi 0,252; bgt 0f; li 5,1; 0:; cmpwi 5,0; beq 1f; rlwinm 0,3,0,24,31; cmplwi 0,127; beq 1f; li 4,1; 1:; mr 3,4"
extern "C" int f_8036FF10() {}
