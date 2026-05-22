// 0x80117CDC cTrack::Stop(void) (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x34(31); cmpwi 0,0; li 3,1; beq 2f; lwz 3,0x50(31); cmpwi 3,0; beq 0f; bl _s80117CDC_0; cmpwi 3,0; beq 0f; li 4,15; li 5,0; mr 3,31; bl _s80117CDC_1; li 4,14; li 5,9; mr 3,31; bl _s80117CDC_2; li 4,16; li 5,100; mr 3,31; bl _s80117CDC_3; li 0,1; mr 3,31; stw 0,0x84(31); li 4,12; li 5,1; bl _s80117CDC_4; b 1f; 0:; mr 3,31; bl _s80117CDC_5; 1:; li 3,1; 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80117CDC_0();
extern "C" void _s80117CDC_1();
extern "C" void _s80117CDC_2();
extern "C" void _s80117CDC_3();
extern "C" void _s80117CDC_4();
extern "C" void _s80117CDC_5();
extern "C" void f_80117CDC() {}
