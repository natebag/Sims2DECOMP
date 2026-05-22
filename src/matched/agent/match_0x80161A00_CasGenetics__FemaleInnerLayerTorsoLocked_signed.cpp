// 0x80161A00 CasGenetics::FemaleInnerLayerTorsoLocked(signed (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 4,8; beq 0f; cmpwi 4,11; bne 1f; 0:; li 3,1; blr; 1:; li 3,0"
extern "C" int f_80161A00() {}
