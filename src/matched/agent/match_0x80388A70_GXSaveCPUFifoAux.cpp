// 0x80388A70 __GXSaveCPUFifoAux (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); mr 31,3; bl _s80388A70_0; lwz 4,-22000(13); lwz 4,0xc(4); addis 0,4,-32768; stw 0,0x0(31); lwz 4,-22000(13); lwz 4,0x10(4); addis 0,4,-32768; stw 0,0x4(31); lwz 4,-22000(13); lwz 0,0x14(4); rlwinm 4,0,0,6,4; addis 0,4,-32768; stw 0,0x18(31); lbz 0,-21948(13); cmplwi 0,0; beq 0f; lwz 5,-21996(13); lhz 4,0x3a(5); lhz 5,0x38(5); rlwimi 5,4,16,0,15; addis 0,5,-32768; stw 0,0x14(31); lwz 5,-21996(13); lhz 4,0x32(5); lhz 0,0x30(5); rlwimi 0,4,16,0,15; stw 0,0x1c(31); b 1f; 0:; lwz 4,0x14(31); lwz 0,0x18(31); subf 0,4,0; stw 0,0x1c(31); lwz 4,0x1c(31); cmpwi 4,0; bge 1f; lwz 0,0x8(31); add 0,4,0; stw 0,0x1c(31); 1:; bl _s80388A70_1; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80388A70_0();
extern "C" void _s80388A70_1();
extern "C" void f_80388A70() {}
