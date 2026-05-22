// 0x800AD17C Behavior::IsDefaultParam(BehaviorNodeParam (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x0(3); li 9,0; cmpwi 0,-1; bne 0f; lwz 0,0x4(3); subfic 9,0,-1; subfic 11,9,0; adde 9,11,9; 0:; mr 3,9"
extern "C" int f_800AD17C() {}
