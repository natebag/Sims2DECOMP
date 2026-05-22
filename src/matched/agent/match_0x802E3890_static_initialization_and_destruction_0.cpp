// 0x802E3890 __static_initialization_and_destruction_0 (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; ori 0,0,65535; cmpw 4,0; bnelr; cmpwi 3,0; beqlr; li 0,3; mtspr 9,0; 0:; bdnz 0b"
extern "C" int f_802E3890() {}
