// 0x80369780 ERDataset::New(void) (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s80369780_0; li 4,36; li 5,0; bl _s80369780_1; bl _s80369780_2; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80369780_0();
extern "C" void _s80369780_1();
extern "C" void _s80369780_2();
extern "C" void f_80369780() {}
