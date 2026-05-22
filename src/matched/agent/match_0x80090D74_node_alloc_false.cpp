// 0x80090D74 __node_alloc<false, (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 3,0; bl _s80090D74_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; lwz 9,-32160(13); cmpwi 9,0; beqlr; li 0,1; stw 0,0xa4(9); blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 3,-32160(13); cmpwi 3,0; beq 0f; bl _s80090D74_1; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,-32160(13); li 3,0; cmpwi 0,0; beq 1f; mr 3,0; bl _s80090D74_2; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; lwz 3,0x98(3); blr; li 0,0; stw 0,0xa0(3); blr; lwz 3,0xa4(3)"
extern "C" void _s80090D74_0();
extern "C" void _s80090D74_1();
extern "C" void _s80090D74_2();
extern "C" void f_80090D74() {}
