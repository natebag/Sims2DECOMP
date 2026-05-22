// 0x80379EE8 __AXDepopVoice (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 4,-22144(13); lha 0,0x52(3); lwz 5,-22132(13); add 0,4,0; lwz 4,-22120(13); stw 0,-22144(13); lwz 9,-22140(13); lha 0,0x54(3); lwz 8,-22128(13); add 0,5,0; lwz 7,-22116(13); stw 0,-22132(13); lwz 6,-22136(13); lha 0,0x56(3); lwz 5,-22124(13); add 0,4,0; lwz 4,-22112(13); stw 0,-22120(13); lha 0,0x58(3); add 0,9,0; stw 0,-22140(13); lha 0,0x5a(3); add 0,8,0; stw 0,-22128(13); lha 0,0x5c(3); add 0,7,0; stw 0,-22116(13); lha 0,0x5e(3); add 0,6,0; stw 0,-22136(13); lha 0,0x60(3); add 0,5,0; stw 0,-22124(13); lha 0,0x62(3); add 0,4,0; stw 0,-22112(13)"
extern "C" void f_80379EE8() {}
