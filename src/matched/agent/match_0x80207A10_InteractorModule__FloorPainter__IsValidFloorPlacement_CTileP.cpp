// 0x80207A10 InteractorModule::FloorPainter::IsValidFloorPlacement(CTilePt (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); lwz 11,-21488(13); mr 31,4; mr 30,5; lwz 9,0x0(11); lha 3,0xf8(9); lwz 0,0xfc(9); add 3,11,3; mtspr 8,0; blrl; andi. 3,3,33; cmpwi 3,1; beq 0f; li 3,0; b 3f; 0:; cmpwi 30,0; beq 2f; addi 30,1,8; mr 4,31; mr 3,30; li 5,0; bl _s80207A10_0; mr 31,30; lwz 0,0x4(30); cmpwi 0,0; beq 2f; 1:; lwz 11,0x4(31); li 4,42; lwz 9,0x4(11); lwz 0,0x264(9); lha 3,0x260(9); mtspr 8,0; add 3,11,3; blrl; xori 3,3,1; andi. 0,3,1; li 3,0; bne 3f; mr 3,31; bl _s80207A10_1; lwz 0,0x4(31); cmpwi 0,0; bne 1b; 2:; li 3,1; 3:; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"
extern "C" void _s80207A10_0();
extern "C" void _s80207A10_1();
extern "C" void f_80207A10() {}
