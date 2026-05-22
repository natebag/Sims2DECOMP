// 0x80253884 UpdatePriority (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); 0:; lwz 0,0x2cc(3); cmpwi 0,0; bgt 4f; lwz 5,0x2d4(3); lwz 4,0x2f4(3); b 3f; 1:; lwz 6,0x0(4); cmplwi 6,0; beq 2f; lwz 0,0x2d0(6); cmpw 0,5; bge 2f; mr 5,0; 2:; lwz 4,0x10(4); 3:; cmplwi 4,0; bne 1b; lwz 0,0x2d0(3); addi 4,5,0; cmpw 0,5; beq 4f; bl _s80253884_0; cmplwi 3,0; bne 0b; 4:; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s80253884_0();
extern "C" void f_80253884() {}
