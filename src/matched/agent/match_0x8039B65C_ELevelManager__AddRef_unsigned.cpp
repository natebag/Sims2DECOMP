// 0x8039B65C ELevelManager::AddRef(unsigned (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="blr; lwz 0,-21536(13); subf 4,0,3; rlwinm 0,4,19,7,9; oris 3,0,32256; rlwinm 0,4,6,10,19; or 3,3,0"
extern "C" int f_8039B65C() {}
