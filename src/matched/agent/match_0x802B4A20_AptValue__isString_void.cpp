// 0x802B4A20 AptValue::isString(void) (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x0(3); li 9,0; rlwinm 0,3,0,25,31; cmpwi 0,1; beq 0f; cmpwi 0,42; bne 1f; 0:; andis. 0,3,2048; beq 1f; li 9,1; 1:; mr 3,9"
extern "C" int f_802B4A20() {}
