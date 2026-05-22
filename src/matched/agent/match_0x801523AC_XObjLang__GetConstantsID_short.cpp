// 0x801523AC XObjLang::GetConstantsID(short, (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 0,3,19,29,31; cmpwi 0,1; beq 2f; bgt 0f; cmpwi 0,0; beq 1f; b 4f; 0:; cmpwi 0,2; beq 3f; b 4f; 1:; li 0,4096; sth 0,0x0(4); b 5f; 2:; li 0,8192; sth 0,0x0(4); b 5f; 3:; li 0,256; sth 0,0x0(4); b 5f; 4:; li 3,0; blr; 5:; lhz 0,0x0(4); rlwinm 9,3,25,26,31; rlwinm 11,3,0,25,31; add 0,0,9; li 3,1; sth 0,0x0(4); stw 11,0x0(5)"
extern "C" void f_801523AC() {}
