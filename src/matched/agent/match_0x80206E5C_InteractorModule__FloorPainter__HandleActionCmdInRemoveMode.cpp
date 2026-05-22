// 0x80206E5C InteractorModule::FloorPainter::HandleActionCmdInRemoveMode(void) (544 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lbz 0,0x60(31); rlwinm 9,0,0,24,31; cmpwi 9,0; bne 1f; ori 0,0,9; lwz 7,0x20(31); stb 0,0x60(31); addi 9,31,32; addi 10,31,100; lwz 0,-31536(13); lwz 11,0x8(9); lwz 8,0x4(9); cmpwi 0,0; stw 7,0x64(31); stw 11,0x8(10); stw 8,0x4(10); bne 0f; li 3,120; bl _s80206E5C_0; bl _s80206E5C_1; stw 3,-31536(13); 0:; lis 4,14155; lwz 3,-31536(13); ori 4,4,56554; bl _s80206E5C_2; b 14f; 1:; andi. 11,9,1; beq 6f; andi. 11,9,32; bne 10f; ori 0,0,16; lis 11,-32697; stb 0,0x60(31); li 30,0; lwz 9,0x5ea0(11); lwz 9,0x0(9); cmpwi 9,0; beq 2f; lwz 30,-4(9); 2:; lwz 3,0xb8(31); li 4,0; rlwinm 5,30,2,0,29; bl _s80206E5C_3; lwz 10,0xa0(31); cmpwi 10,0; beq 5f; lwz 11,0x0(10); lwz 0,0x4(10); mr 9,11; cmpw 11,0; beq 4f; 3:; addi 9,9,8; cmpw 9,0; bne 3b; 4:; stw 11,0x4(10); 5:; lwz 4,0xb8(31); mr 3,31; bl _s80206E5C_4; cmpwi 3,0; beq 14f; lwz 4,0xb8(31); li 0,0; mr 3,31; stb 0,0x60(31); mr 5,30; bl _s80206E5C_5; mr 3,31; li 4,0; bl _s80206E5C_6; b 14f; 6:; andi. 0,9,2; beq 14f; lwz 10,0xa0(31); cmpwi 10,0; beq 9f; lwz 11,0x0(10); lwz 0,0x4(10); mr 9,11; cmpw 11,0; beq 8f; 7:; addi 9,9,8; cmpw 9,0; bne 7b; 8:; stw 11,0x4(10); 9:; lbz 0,0x60(31); rlwinm 29,0,27,31,31; cmpwi 29,0; beq 12f; 10:; lwz 0,-31536(13); cmpwi 0,0; bne 11f; li 3,120; bl _s80206E5C_7; bl _s80206E5C_8; stw 3,-31536(13); 11:; lis 4,28199; lwz 3,-31536(13); ori 4,4,30903; bl _s80206E5C_9; b 14f; 12:; ori 0,0,16; lis 11,-32697; stb 0,0x60(31); li 30,0; lwz 9,0x5ea0(11); lwz 9,0x0(9); cmpwi 9,0; beq 13f; lwz 30,-4(9); 13:; lwz 3,0xb8(31); li 4,0; rlwinm 5,30,2,0,29; bl _s80206E5C_10; lwz 4,0xb8(31); mr 3,31; bl _s80206E5C_11; cmpwi 3,0; beq 14f; lwz 4,0xb8(31); mr 3,31; stb 29,0x60(31); mr 5,30; bl _s80206E5C_12; mr 3,31; li 4,0; bl _s80206E5C_13; 14:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80206E5C_0();
extern "C" void _s80206E5C_1();
extern "C" void _s80206E5C_2();
extern "C" void _s80206E5C_3();
extern "C" void _s80206E5C_4();
extern "C" void _s80206E5C_5();
extern "C" void _s80206E5C_6();
extern "C" void _s80206E5C_7();
extern "C" void _s80206E5C_8();
extern "C" void _s80206E5C_9();
extern "C" void _s80206E5C_10();
extern "C" void _s80206E5C_11();
extern "C" void _s80206E5C_12();
extern "C" void _s80206E5C_13();
extern "C" void f_80206E5C() {}
