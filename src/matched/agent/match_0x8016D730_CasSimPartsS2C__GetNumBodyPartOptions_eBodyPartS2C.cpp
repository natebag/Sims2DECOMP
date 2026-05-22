// 0x8016D730 CasSimPartsS2C::GetNumBodyPartOptions(eBodyPartS2C) (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 4,13; beq 6f; bgt 2f; cmpwi 4,7; beq 7f; bgt 0f; cmpwi 4,1; beq 5f; bgt 6f; cmpwi 4,0; beq 5f; b 10f; 0:; cmpwi 4,10; beq 7f; bgt 1f; cmpwi 4,8; beq 6f; cmpwi 4,9; beq 8f; b 10f; 1:; cmpwi 4,11; beq 6f; cmpwi 4,12; beq 7f; b 10f; 2:; cmpwi 4,19; beq 6f; bgt 3f; cmpwi 4,17; bgt 5f; cmpwi 4,16; bge 5f; cmpwi 4,14; beq 9f; cmpwi 4,15; beq 6f; b 10f; 3:; cmpwi 4,24; bgt 4f; cmpwi 4,22; bge 5f; cmpwi 4,20; beq 5f; cmpwi 4,21; beq 9f; b 10f; 4:; cmpwi 4,25; bne 10f; 5:; li 3,0; blr; 6:; li 3,4; blr; 7:; li 3,2; blr; 8:; li 3,6; blr; 9:; li 3,3; blr; 10:; li 3,0"
extern "C" int f_8016D730() {}
