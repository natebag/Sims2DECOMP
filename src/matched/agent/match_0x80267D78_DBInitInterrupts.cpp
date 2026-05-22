// 0x80267D78 DBInitInterrupts (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 3,2; stw 0,0x4(1); addi 3,3,-32768; stwu 1,-8(1); bl _s80267D78_0; li 3,64; bl _s80267D78_1; lis 3,-32730; addi 0,3,32388; lis 3,-32730; stw 0,-23052(13); addi 4,3,32324; li 3,25; bl _s80267D78_2; li 3,64; bl _s80267D78_3; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s80267D78_0();
extern "C" void _s80267D78_1();
extern "C" void _s80267D78_2();
extern "C" void _s80267D78_3();
extern "C" void f_80267D78() {}
