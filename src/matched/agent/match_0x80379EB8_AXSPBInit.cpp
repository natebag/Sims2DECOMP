// 0x80379EB8 __AXSPBInit (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stw 0,-22112(13); stw 0,-22116(13); stw 0,-22120(13); stw 0,-22124(13); stw 0,-22128(13); stw 0,-22132(13); stw 0,-22136(13); stw 0,-22140(13); stw 0,-22144(13)"
extern "C" void f_80379EB8() {}
