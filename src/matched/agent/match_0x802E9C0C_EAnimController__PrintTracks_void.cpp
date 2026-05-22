// 0x802E9C0C EAnimController::PrintTracks(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x40(3); cmpwi 0,0; blelr; mtspr 9,0; 0:; bdnz 0b"
extern "C" int f_802E9C0C() {}
