// 0x802B4BF4 AptValue::isCIH(bool) (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x0(3); li 0,0; rlwinm 9,3,0,25,31; addi 9,9,-12; cmplwi 9,7; bgt 1f; cmpwi 4,0; bne 0f; andis. 9,3,2048; beq 1f; 0:; li 0,1; 1:; mr 3,0"
extern "C" int f_802B4BF4() {}
