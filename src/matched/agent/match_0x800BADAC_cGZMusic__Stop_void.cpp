// 0x800BADAC cGZMusic::Stop(void) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,-24468(13); mr 10,3; lwz 0,0x40c(11); cmpw 0,10; bne 1f; lwz 0,0x8(10); cmpwi 0,0; beq 0f; li 9,1; li 0,0; stw 0,0x40c(11); stw 9,0x414(11); stw 9,0x410(11); 0:; lwz 9,-24468(13); li 0,0; stw 0,0x418(9); 1:; li 0,0; li 3,1; stw 0,0x8(10)"
extern "C" void f_800BADAC() {}
