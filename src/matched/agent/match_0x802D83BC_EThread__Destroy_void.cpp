// 0x802D83BC EThread::Destroy(void) (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 0,-22764(13); mr 31,3; cmpw 0,31; bne 0f; lwz 0,0x334(31); stw 0,-22764(13); b 1f; 0:; lwz 9,0x330(31); lwz 0,0x334(31); stw 0,0x334(9); 1:; lwz 0,-22760(13); cmpw 0,31; bne 2f; lwz 0,0x330(31); stw 0,-22760(13); b 3f; 2:; lwz 9,0x334(31); lwz 0,0x330(31); stw 0,0x330(9); 3:; mr 3,31; bl _s802D83BC_0; mr. 30,3; beq 4f; li 0,0; li 3,0; stw 0,0x318(31); bl _s802D83BC_1; b 5f; 4:; lwz 3,0x318(31); bl _s802D83BC_2; mr 3,31; bl _s802D83BC_3; stw 30,0x318(31); 5:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802D83BC_0();
extern "C" void _s802D83BC_1();
extern "C" void _s802D83BC_2();
extern "C" void _s802D83BC_3();
extern "C" void f_802D83BC() {}
