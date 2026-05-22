// 0x802B4AF0 AptValue::isScriptFunction(void) (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x0(3); li 0,0; rlwinm 9,3,0,25,31; addi 9,9,-43; cmplwi 9,2; bgt 0f; rlwinm 0,3,5,31,31; 0:; mr 3,0"
extern "C" int f_802B4AF0() {}
