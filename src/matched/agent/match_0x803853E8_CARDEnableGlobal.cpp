// 0x803853E8 __CARDEnableGlobal (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 0,-25334(13); rlwinm. 0,0,0,26,26; beq 0f; li 4,1; b 1f; 0:; li 4,0; 1:; cmpwi 3,0; beq 2f; lbz 0,-25334(13); ori 0,0,32; stb 0,-25334(13); b 3f; 2:; lbz 0,-25334(13); rlwinm 0,0,0,27,25; stb 0,-25334(13); 3:; mr 3,4"
extern "C" void f_803853E8() {}
