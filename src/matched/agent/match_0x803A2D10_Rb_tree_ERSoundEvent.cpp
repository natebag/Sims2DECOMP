// 0x803A2D10 _Rb_tree<ERSoundEvent (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 6,0x4(4); mr 7,5; mr 31,3; lwz 5,0x4(6); cmpwi 5,0; beq 3f; lwz 9,0x0(7); 0:; mr 6,5; lwz 0,0x10(6); cmplw 9,0; bge 1f; lwz 0,0x8(6); b 2f; 1:; lwz 0,0xc(6); 2:; mr. 5,0; bne 0b; 3:; mr 3,31; li 8,0; bl _s803A2D10_0; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s803A2D10_0();
extern "C" void f_803A2D10() {}
