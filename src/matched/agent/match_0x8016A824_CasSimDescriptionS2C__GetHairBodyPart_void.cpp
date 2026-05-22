// 0x8016A824 CasSimDescriptionS2C::GetHairBodyPart(void) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x94(3); cmpwi 0,0; beq 0f; li 3,3; blr; 0:; lwz 3,0x90(3); cmpwi 3,1; beq 3f; bgt 1f; cmpwi 3,0; beq 2f; b 6f; 1:; cmpwi 3,2; beq 4f; cmpwi 3,3; beq 5f; b 6f; 2:; li 3,2; blr; 3:; li 3,4; blr; 4:; li 3,5; blr; 5:; li 3,6; blr; 6:; li 3,2"
extern "C" int f_8016A824() {}
