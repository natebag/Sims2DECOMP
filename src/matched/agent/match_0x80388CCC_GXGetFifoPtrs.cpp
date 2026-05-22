// 0x80388CCC GXGetFifoPtrs (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-21960(13); cmplw 3,0; bne 0f; lwz 6,-22000(13); lwz 0,0x14(6); rlwinm 6,0,0,6,4; addis 0,6,-32768; stw 0,0x18(3); 0:; lwz 0,-21956(13); cmplw 3,0; bne 1f; lwz 7,-21996(13); lhz 6,0x3a(7); lhz 7,0x38(7); rlwimi 7,6,16,0,15; addis 0,7,-32768; stw 0,0x14(3); lwz 7,-21996(13); lhz 6,0x32(7); lhz 0,0x30(7); rlwimi 0,6,16,0,15; stw 0,0x1c(3); b 2f; 1:; lwz 6,0x14(3); lwz 0,0x18(3); subf 0,6,0; stw 0,0x1c(3); lwz 6,0x1c(3); cmpwi 6,0; bge 2f; lwz 0,0x8(3); add 0,6,0; stw 0,0x1c(3); 2:; lwz 0,0x14(3); stw 0,0x0(4); lwz 0,0x18(3); stw 0,0x0(5)"
extern "C" void f_80388CCC() {}
