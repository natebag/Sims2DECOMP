// 0x80173E5C CasSimState::GetNextSleeveStyle(eBodyPartS2C, (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 4,14; beq 8f; cmpwi 6,0; beq 6f; cmpwi 5,1; beq 4f; bgt 0f; cmpwi 5,0; beq 5f; b 11f; 0:; cmpwi 5,2; beq 3f; 1:; cmpwi 5,3; bne 11f; 2:; li 3,2; blr; 3:; li 3,1; blr; 4:; li 3,0; blr; 5:; li 3,3; blr; 6:; cmpwi 5,1; beq 2b; bgt 7f; cmpwi 5,0; beq 3b; b 11f; 7:; cmpwi 5,2; beq 5b; cmpwi 5,3; bne 11f; b 4b; 8:; cmpwi 6,0; beq 9f; cmpwi 5,2; beq 4b; bgt 1b; cmpwi 5,0; bne 11f; b 5b; 9:; cmpwi 5,2; beq 5b; bgt 10f; cmpwi 5,0; beq 2b; b 11f; 10:; cmpwi 5,3; beq 4b; 11:; li 3,3"
extern "C" int f_80173E5C() {}
