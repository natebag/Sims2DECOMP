// 0x803209C4 ERShader::CanColorBeModified(void) (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x14(3); cmpwi 0,0; beq 0f; mr 9,0; b 1f; 0:; lwz 3,0x18(3); li 9,0; cmpwi 3,0; beq 1f; lwz 9,0x14(3); 1:; lwz 0,0xb4(9); lwz 3,0x74(9); or 3,3,0; rlwinm 3,3,27,31,31"
extern "C" int f_803209C4() {}
