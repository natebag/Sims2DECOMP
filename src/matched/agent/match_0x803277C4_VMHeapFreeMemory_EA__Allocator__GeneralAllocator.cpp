// 0x803277C4 VMHeapFreeMemory(EA::Allocator::GeneralAllocator (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 29,4; li 31,0; lis 25,-32693; lis 26,-32692; lis 27,-32693; lis 28,-32692; 0:; addi 3,25,31260; bl _s803277C4_0; mr 30,3; addi 3,26,-20832; bl _s803277C4_1; add 30,30,3; addi 3,27,11064; bl _s803277C4_2; add 30,30,3; addi 3,28,-17444; bl _s803277C4_3; add 30,30,3; cmpwi 30,0; add 31,31,30; beq 1f; cmplw 31,29; blt 0b; 1:; cmpwi 31,0; mfcr 31; beq 2f; lwz 3,-26392(13); lwz 9,0x0(3); lha 0,0x40(9); lwz 9,0x44(9); add 3,3,0; mtspr 8,9; blrl; 2:; li 3,1; mtcrf 128,31; bne 3f; li 3,0; 3:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s803277C4_0();
extern "C" void _s803277C4_1();
extern "C" void _s803277C4_2();
extern "C" void _s803277C4_3();
extern "C" void f_803277C4() {}
