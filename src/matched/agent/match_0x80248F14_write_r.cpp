// 0x80248F14 _write_r (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; li 0,0; mr 3,4; stw 0,-21340(13); mr 4,5; mr 5,6; bl _s80248F14_0; cmpwi 3,-1; bne 0f; lwz 0,-21340(13); cmpwi 0,0; beq 0f; stw 0,0x0(31); 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80248F14_0();
extern "C" void f_80248F14() {}
