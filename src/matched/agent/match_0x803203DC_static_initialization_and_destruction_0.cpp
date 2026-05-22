// 0x803203DC __static_initialization_and_destruction_0 (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 1f; cmpwi 3,0; beq 0f; addi 9,13,-22620; li 0,0; lis 3,-32693; stw 0,0x0(9); stw 0,0x4(9); addi 3,3,6072; bl _s803203DC_0; lis 3,-32688; lis 4,-32718; lis 5,-32718; lis 6,-32718; lis 8,-32702; lis 9,-32688; addi 3,3,-12544; addi 4,4,1148; addi 5,5,1188; addi 6,6,1232; addi 8,8,2572; addi 9,9,-13000; li 7,2; bl _s803203DC_1; stw 3,-22612(13); b 1f; 0:; lis 3,-32693; li 4,2; addi 3,3,6072; bl _s803203DC_2; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s803203DC_0();
extern "C" void _s803203DC_1();
extern "C" void _s803203DC_2();
extern "C" void f_803203DC() {}
