// 0x800559FC GetHandleFromISimInstance(ISimInstance (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32697; mr 11,3; lwz 9,0x5e94(9); cmpwi 9,0; li 3,-1; beqlr; lwz 3,0x4(9); cmpwi 3,0; bne 1f; li 3,-1; blr; 0:; lwz 3,0x18(3); blr; 1:; lwz 3,0x4(3); cmpwi 3,0; beq 3f; 2:; lwz 0,0x1c(3); cmpw 11,0; beq 0b; lwz 3,0x10(3); cmpwi 3,0; bne 2b; 3:; li 3,-1"
extern "C" int f_800559FC() {}
