// 0x802D5A10 ETypeInfo::IsDerivedFrom(ETypeInfo (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="0:; cmpw 3,4; beq 1f; lwz 3,0x18(3); cmpwi 3,0; bne 0b; li 3,0; blr; 1:; li 3,1"
extern "C" int f_802D5A10() {}
