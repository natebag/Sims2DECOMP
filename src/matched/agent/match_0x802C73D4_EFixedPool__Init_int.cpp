// 0x802C73D4 EFixedPool::Init(int, (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 6,6; beqlr; addic. 9,5,-1; bltlr; mullw 0,9,4; neg 4,4; mr 10,0; add 11,0,6; 0:; lwz 0,0x0(3); addic. 9,9,-1; stwx 0,10,6; stw 11,0x0(3); add 10,10,4; add 11,11,4; bge 0b"
extern "C" void f_802C73D4() {}
