// 0x803853A0 __CARDEnablePerm (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 0,-25334(13); rlwinm 6,3,0,24,31; and. 0,0,6; beq 0f; li 5,1; b 1f; 0:; li 5,0; 1:; cmpwi 4,0; beq 2f; lbz 0,-25334(13); or 0,0,3; stb 0,-25334(13); b 3f; 2:; lbz 0,-25334(13); andc 0,0,6; stb 0,-25334(13); 3:; mr 3,5"
extern "C" void f_803853A0() {}
