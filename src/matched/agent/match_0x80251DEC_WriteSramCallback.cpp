// 0x80251DEC WriteSramCallback (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 3,-32694; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); addi 31,3,-24704; stw 30,0x10(1); addi 30,31,64; lwz 4,0x40(31); add 3,31,4; subfic 5,4,64; bl _s80251DEC_0; stw 3,0x4c(31); lwz 0,0x4c(31); cmpwi 0,0; beq 0f; li 0,64; stw 0,0x0(30); 0:; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80251DEC_0();
extern "C" void f_80251DEC() {}
