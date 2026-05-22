// 0x803378A4 CreateVideoDecodeThread(long, (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 8,3; mr. 5,4; beq 0f; lis 3,-32691; lis 4,-32717; lis 6,-32691; addi 3,3,4704; addi 4,4,31408; addi 6,6,9592; b 1f; 0:; lis 3,-32691; lis 4,-32717; lis 6,-32691; addi 3,3,4704; addi 4,4,31180; addi 6,6,9592; li 5,0; 1:; li 7,4096; li 9,1; bl _s803378A4_0; cmpwi 3,0; li 3,0; beq 2f; lis 3,-32691; lis 4,-32691; addi 3,3,9592; addi 4,4,9656; li 5,3; bl _s803378A4_1; lis 3,-32691; lis 4,-32691; addi 3,3,9624; addi 4,4,9668; li 5,3; bl _s803378A4_2; li 0,1; li 3,1; stw 0,-22544(13); stw 0,-26376(13); 2:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s803378A4_0();
extern "C" void _s803378A4_1();
extern "C" void _s803378A4_2();
extern "C" void f_803378A4() {}
