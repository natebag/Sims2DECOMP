// 0x80335108 ENgcMovie::ENgcMovie(void) (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lis 9,-32697; mr 31,3; addi 9,9,-14024; li 4,4096; stw 9,0x8(31); addi 3,31,68; bl _s80335108_0; li 0,0; lis 3,-32692; stw 0,0x20(31); addi 3,3,9472; bl _s80335108_1; lwz 0,-26576(13); cmpwi 0,0; bne 2f; lwz 0,-26352(13); cmpwi 0,0; bne 2f; li 3,0; bl _s80335108_2; bl _s80335108_3; bl _s80335108_4; li 3,2; bl _s80335108_5; bl _s80335108_6; cmpwi 3,0; bne 0f; li 3,0; bl _s80335108_7; b 1f; 0:; li 3,3; bl _s80335108_8; 1:; li 0,1; stw 0,-26352(13); 2:; lis 3,-32691; li 4,0; li 5,464; addi 3,3,14656; bl _s80335108_9; mr 3,31; li 4,1; bl _s80335108_10; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80335108_0();
extern "C" void _s80335108_1();
extern "C" void _s80335108_2();
extern "C" void _s80335108_3();
extern "C" void _s80335108_4();
extern "C" void _s80335108_5();
extern "C" void _s80335108_6();
extern "C" void _s80335108_7();
extern "C" void _s80335108_8();
extern "C" void _s80335108_9();
extern "C" void _s80335108_10();
extern "C" void f_80335108() {}
