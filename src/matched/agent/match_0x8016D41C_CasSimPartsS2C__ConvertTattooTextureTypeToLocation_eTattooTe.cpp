// 0x8016D41C CasSimPartsS2C::ConvertTattooTextureTypeToLocation(eTattooTextureTypeS2C) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 4,1; beq 2f; bgt 0f; cmpwi 4,0; beq 1f; b 4f; 0:; cmpwi 4,2; beq 3f; b 4f; 1:; li 3,0; blr; 2:; li 3,1; blr; 3:; li 3,2; blr; 4:; li 3,1"
extern "C" int f_8016D41C() {}
