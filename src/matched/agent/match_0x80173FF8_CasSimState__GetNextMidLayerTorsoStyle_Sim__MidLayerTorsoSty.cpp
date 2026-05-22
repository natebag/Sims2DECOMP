// 0x80173FF8 CasSimState::GetNextMidLayerTorsoStyle(Sim::MidLayerTorsoStyleS2C, (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 3,4; cmpwi 5,0; beq 7f; cmpwi 3,2; beq 3f; bgt 0f; cmpwi 3,0; beq 1f; cmpwi 3,1; beq 2f; blr; 0:; cmpwi 3,4; beq 5f; blt 4f; cmpwi 3,5; beq 6f; blr; 1:; li 3,1; blr; 2:; li 3,2; blr; 3:; li 3,0; blr; 4:; li 3,4; blr; 5:; li 3,5; blr; 6:; li 3,3; blr; 7:; cmpwi 3,2; beq 1b; bgt 8f; cmpwi 3,0; beq 2b; cmpwi 3,1; beq 3b; blr; 8:; cmpwi 3,4; beq 6b; blt 5b; cmpwi 3,5; beq 4b"
extern "C" int f_80173FF8() {}
