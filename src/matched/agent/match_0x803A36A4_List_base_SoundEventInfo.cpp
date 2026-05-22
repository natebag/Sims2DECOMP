// 0x803A36A4 _List_base<SoundEventInfo, (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 9,0x4(30); lwz 31,0x0(9); cmpw 31,9; beq 2f; 0:; mr 3,31; lwz 31,0x0(31); cmpwi 3,0; beq 1f; li 4,20; bl _s803A36A4_0; 1:; lwz 0,0x4(30); cmpw 31,0; bne 0b; 2:; lwz 9,0x4(30); stw 9,0x0(9); lwz 11,0x4(30); stw 11,0x4(11); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s803A36A4_0();
extern "C" void f_803A36A4() {}
