// 0x802B3E78 AptValue::CanCreateScriptObject(void) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x0(3); rlwinm 0,0,0,25,31; cmpwi 0,30; bgt 1f; cmpwi 0,29; bge 4f; cmpwi 0,22; bgt 0f; cmpwi 0,21; bge 4f; cmpwi 0,1; beq 4f; cmpwi 0,9; beq 4f; b 5f; 0:; cmpwi 0,27; bgt 5f; cmpwi 0,26; b 3f; 1:; cmpwi 0,36; bgt 2f; cmpwi 0,35; bge 4f; cmpwi 0,33; beq 4f; b 5f; 2:; cmpwi 0,44; bgt 5f; cmpwi 0,41; 3:; blt 5f; 4:; li 3,1; blr; 5:; li 3,0"
extern "C" int f_802B3E78() {}
