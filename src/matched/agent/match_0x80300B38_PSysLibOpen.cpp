// 0x80300B38 PSysLibOpen (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 0,0x1c(1); li 3,133; li 4,133; bl _s80300B38_0; cmpwi 3,0; li 3,-1; blt 0f; li 3,5; li 4,128; li 5,1024; bl _s80300B38_1; cmpwi 3,0; li 3,-1; blt 0f; lis 4,-32702; addi 3,13,-22708; addi 4,4,-2184; bl _s80300B38_2; lis 4,-32702; addi 3,13,-22704; addi 4,4,-2172; bl _s80300B38_3; lis 4,-32702; addi 3,13,-22700; addi 4,4,-2160; bl _s80300B38_4; lis 4,-32702; addi 3,13,-22696; addi 4,4,-2148; bl _s80300B38_5; lis 9,-32702; addi 11,1,8; lwz 10,-2136(9); mr 3,11; addi 9,9,-2136; lwz 8,0x8(9); lwz 0,0x4(9); stw 10,0x8(1); stw 0,0x4(11); stw 8,0x8(11); bl _s80300B38_6; li 3,0; 0:; lwz 0,0x1c(1); mtspr 8,0; addi 1,1,24"
extern "C" void _s80300B38_0();
extern "C" void _s80300B38_1();
extern "C" void _s80300B38_2();
extern "C" void _s80300B38_3();
extern "C" void _s80300B38_4();
extern "C" void _s80300B38_5();
extern "C" void _s80300B38_6();
extern "C" void f_80300B38() {}
