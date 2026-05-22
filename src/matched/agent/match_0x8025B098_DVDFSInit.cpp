// 0x8025B098 __DVDFSInit (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32768; stw 3,-23512(13); lwz 0,0x38(3); stw 0,-23508(13); lwz 3,-23508(13); cmpwi 3,0; beqlr; lwz 0,0x8(3); stw 0,-23500(13); lwz 0,-23500(13); mulli 0,0,12; add 0,3,0; stw 0,-23504(13)"
extern "C" void f_8025B098() {}
