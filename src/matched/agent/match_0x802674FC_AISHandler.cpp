// 0x802674FC __AISHandler (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-736(1); stw 31,0x2dc(1); lis 31,-13312; lwz 0,0x6c00(31); addi 3,1,16; stw 30,0x2d8(1); ori 0,0,8; stw 0,0x6c00(31); addi 30,4,0; bl _s802674FC_0; addi 3,1,16; bl _s802674FC_1; lwz 12,-23136(13); cmplwi 12,0; beq 0f; addi 3,31,27648; mtspr 8,12; lwz 3,0x8(3); blrl; 0:; addi 3,1,16; bl _s802674FC_2; mr 3,30; bl _s802674FC_3; lwz 0,0x2e4(1); lwz 31,0x2dc(1); lwz 30,0x2d8(1); addi 1,1,736; mtspr 8,0"
extern "C" void _s802674FC_0();
extern "C" void _s802674FC_1();
extern "C" void _s802674FC_2();
extern "C" void _s802674FC_3();
extern "C" void f_802674FC() {}
