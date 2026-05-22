// 0x80364710 InteractorModule::CanObjectBeDestroyed(cXObject (372 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 1,1,8; blr; lis 3,-32688; addi 3,3,-10564; blr; lis 9,-32688; lwz 3,-10552(9); blr; lis 9,-32688; lwz 3,-10548(9); blr; lis 9,-32688; lhz 3,-10544(9); blr; lis 3,-32688; addi 3,3,-10564; blr; lis 9,-32688; lhz 3,-10542(9); blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 7,3; lis 4,-32714; lis 3,-32688; lis 5,-32714; lis 6,-32714; lis 8,-32702; lis 9,-32688; addi 3,3,-10564; addi 4,4,18052; addi 5,5,18104; addi 6,6,18120; addi 8,8,12228; addi 9,9,-13320; bl _s80364710_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s80364710_1; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 3,20; bl _s80364710_2; bl _s80364710_3; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s80364710_4; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; lis 9,-32697; addi 9,9,-28472; stw 9,0x0(3); blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr. 11,3; beq 0f; lwz 9,0x0(11); li 4,3; lha 3,0x30(9); lwz 0,0x34(9); add 3,11,3; mtspr 8,0; blrl; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; lis 3,-32688; addi 3,3,-10524; blr; lis 9,-32688; lwz 3,-10512(9)"
extern "C" void _s80364710_0();
extern "C" void _s80364710_1();
extern "C" void _s80364710_2();
extern "C" void _s80364710_3();
extern "C" void _s80364710_4();
extern "C" void f_80364710() {}
