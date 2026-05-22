// 0x8016B8BC CasSimPartsS2C::GetTextureIDFromVector(VECTOR<unsigned (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 4,0x0(4); li 0,0; cmpwi 7,4,0; beq cr7,0f; lwz 0,-4(4); 0:; cmpw 0,5; bgt 2f; cmpwi 6,0; beq 3f; li 9,0; beq cr7,1f; lwz 9,-4(4); 1:; cmpw 5,9; blt 3f; li 3,0; blr; 2:; rlwinm 9,5,2,0,29; lwzx 3,4,9; blr; 3:; li 3,0"
extern "C" int f_8016B8BC() {}
