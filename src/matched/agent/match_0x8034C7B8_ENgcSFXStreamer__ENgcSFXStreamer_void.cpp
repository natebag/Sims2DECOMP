// 0x8034C7B8 ENgcSFXStreamer::ENgcSFXStreamer(void) (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); lis 9,-32690; mr 29,3; addi 31,9,-19244; lis 27,-32715; addi 28,31,4148; li 30,0; 0:; stw 30,0x24(31); addi 4,27,-10400; li 5,0; li 3,15; bl _s8034C7B8_0; mr 0,3; li 6,-904; stw 0,0x0(31); li 7,-904; li 8,64; li 9,127; li 10,0; li 4,0; li 5,0; bl _s8034C7B8_1; lwz 3,0x0(31); bl _s8034C7B8_2; stw 30,0x34(31); stw 30,0x38(31); addi 31,31,68; cmplw 31,28; ble 0b; li 0,0; mr 3,29; stw 0,-22488(13); lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8034C7B8_0();
extern "C" void _s8034C7B8_1();
extern "C" void _s8034C7B8_2();
extern "C" void f_8034C7B8() {}
