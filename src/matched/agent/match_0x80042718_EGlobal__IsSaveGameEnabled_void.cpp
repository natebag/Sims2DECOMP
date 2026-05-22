// 0x80042718 EGlobal::IsSaveGameEnabled(void) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32697; li 10,1; lwz 11,0x5bc8(9); lhz 0,0xc8(11); cmpwi 0,0; bne 0f; li 10,0; 0:; cmpwi 10,0; li 3,0; bne 2f; lis 9,-32697; lwz 9,0x5ee4(9); lwz 0,0x160(9); cmpwi 0,1; bne 1f; lwz 0,0x234(9); cmpwi 0,0; bne 2f; 1:; li 3,1; 2:; lis 9,-32697; lwz 0,0x5c70(9); cmpwi 0,0; beqlr; cmpwi 3,0; li 3,0; beqlr; lis 9,-32697; lwz 9,0x5ee8(9); lwz 0,0x160(9); cmpwi 0,1; bne 3f; lwz 0,0x234(9); cmpwi 0,0; bnelr; 3:; li 3,1"
extern "C" int f_80042718() {}
