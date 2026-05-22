// 0x8039B200 VMBASESetPageLocked (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 4,0; beq 0f; lwz 4,-21528(13); li 0,1; stbx 0,4,3; blr; 0:; lwz 4,-21528(13); li 0,0; stbx 0,4,3"
extern "C" void f_8039B200() {}
