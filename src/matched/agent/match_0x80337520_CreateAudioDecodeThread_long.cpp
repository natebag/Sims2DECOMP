// 0x80337520 CreateAudioDecodeThread(long, (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 8,3; mr. 5,4; beq 0f; lis 3,-32691; lis 4,-32717; lis 6,-32691; addi 3,3,9680; addi 4,4,30316; addi 6,6,14568; b 1f; 0:; lis 3,-32691; lis 4,-32717; lis 6,-32691; addi 3,3,9680; addi 4,4,30276; addi 6,6,14568; li 5,0; 1:; li 7,4096; li 9,1; bl _s80337520_0; cmpwi 3,0; li 3,0; beq 2f; lis 3,-32691; lis 4,-32691; addi 3,3,14568; addi 4,4,14632; li 5,3; bl _s80337520_1; lis 3,-32691; lis 4,-32691; addi 3,3,14600; addi 4,4,14644; li 5,3; bl _s80337520_2; li 0,1; li 3,1; stw 0,-26372(13); 2:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80337520_0();
extern "C" void _s80337520_1();
extern "C" void _s80337520_2();
extern "C" void f_80337520() {}
