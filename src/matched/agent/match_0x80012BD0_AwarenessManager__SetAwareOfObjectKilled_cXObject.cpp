// 0x80012BD0 AwarenessManager::SetAwareOfObjectKilled(cXObject (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,3; lwz 0,0x1c(9); cmpwi 0,0; beq 0f; cmpw 0,4; bne 0f; lwz 0,0x0(9); li 3,1; ori 0,0,2048; stw 0,0x0(9); blr; 0:; li 3,0"
extern "C" void f_80012BD0() {}
