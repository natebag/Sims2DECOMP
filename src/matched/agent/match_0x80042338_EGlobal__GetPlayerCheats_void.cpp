// 0x80042338 EGlobal::GetPlayerCheats(void) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x400(3); cmpwi 0,0; bne 0f; lhz 3,0x9c(3); blr; 0:; li 3,0; ori 3,3,65535"
extern "C" int f_80042338() {}
