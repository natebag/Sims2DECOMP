// 0x8032EB94 EventThread(void (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lis 3,-32692; lwz 8,-26488(13); addi 3,3,23328; lis 4,-32717; lis 6,-32692; addi 4,4,-5256; addi 6,6,28224; mr 5,3; li 7,4096; li 9,1; bl _s8032EB94_0; lis 3,-32717; lis 28,-32692; addi 3,3,-6484; lis 29,-32717; bl _s8032EB94_1; lis 30,-32692; lis 3,-32692; addi 3,3,18392; bl _s8032EB94_2; lwz 31,-22564(13); 0:; mr 6,31; addi 3,28,18392; addi 7,29,-5368; srawi 5,31,31; bl _s8032EB94_3; addi 3,30,18432; bl _s8032EB94_4; 1:; lwz 11,-26564(13); cmpwi 11,0; beq 2f; lwz 9,0x0(11); lha 3,0x20(9); lwz 0,0x24(9); add 3,11,3; mtspr 8,0; blrl; 2:; bl _s8032EB94_5; bl _s8032EB94_6; cmpwi 3,0; beq 1b; b 0b"
extern "C" void _s8032EB94_0();
extern "C" void _s8032EB94_1();
extern "C" void _s8032EB94_2();
extern "C" void _s8032EB94_3();
extern "C" void _s8032EB94_4();
extern "C" void _s8032EB94_5();
extern "C" void _s8032EB94_6();
extern "C" void f_8032EB94() {}
