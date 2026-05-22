// 0x802D59DC ETypeInfo::Find(unsigned (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,-26848(13); 0:; cmpwi 9,0; beq 2f; lwz 0,0x10(9); cmplw 3,0; bge 1f; lwz 9,0x1c(9); b 0b; 1:; ble 2f; lwz 9,0x20(9); b 0b; 2:; mr 3,9"
extern "C" int f_802D59DC() {}
