// 0x80193D70 CASTarget::Draw(ERC (444 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 29,3; mr 27,4; lwz 11,0x1350(29); cmpwi 11,0; beq 5f; lwz 9,0x4(11); lha 3,0x60(9); lwz 0,0x64(9); add 3,11,3; mtspr 8,0; blrl; mr 3,29; bl _s80193D70_0; cmpwi 3,0; beq 1f; addi 30,29,2632; addi 31,29,2636; li 28,4; 0:; lwz 9,0x0(31); mr 4,27; addi 31,31,576; lha 3,0x60(9); lwz 0,0x64(9); add 3,30,3; mtspr 8,0; addi 30,30,576; blrl; addic. 28,28,-1; bne 0b; lwz 3,0x1390(29); mr 4,27; lwz 9,0x80(3); lha 0,0x30(9); lwz 9,0x34(9); add 3,3,0; mtspr 8,9; blrl; b 2f; 1:; lwz 0,0x134c(29); mr 4,27; rlwinm 3,0,3,0,28; add 3,3,0; rlwinm 3,3,6,0,25; add 9,3,29; lwz 11,0xa4c(9); addi 3,3,2632; add 3,29,3; lha 0,0x60(11); lwz 9,0x64(11); add 3,3,0; mtspr 8,9; blrl; lis 9,-32697; lwz 0,0x61f8(9); cmpwi 0,0; beq 2f; lwz 0,0x134c(29); mr 4,27; rlwinm 3,0,3,0,28; add 3,3,0; rlwinm 3,3,6,0,25; addi 3,3,2632; add 3,29,3; bl _s80193D70_1; 2:; lwz 3,0x1354(29); cmpwi 3,0; beq 4f; mr 4,27; bl _s80193D70_2; lwz 11,0x134c(29); mr 0,11; cmpwi 11,0; bge 3f; addi 0,11,3; 3:; rlwinm 0,0,0,0,29; lwz 9,0x1348(29); subf 0,0,11; srw 9,9,0; andi. 0,9,1; beq 4f; rlwinm 3,11,3,0,28; mr 4,27; add 3,3,11; rlwinm 3,3,6,0,25; addi 3,3,2632; add 3,29,3; bl _s80193D70_3; 4:; lwz 0,0x1370(29); cmpwi 0,0; beq 5f; mr 3,29; bl _s80193D70_4; cmpwi 3,0; beq 5f; lwz 3,0x1370(29); mr 4,27; lwz 9,0x80(3); lha 0,0x30(9); lwz 9,0x34(9); add 3,3,0; mtspr 8,9; blrl; 5:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s80193D70_0();
extern "C" void _s80193D70_1();
extern "C" void _s80193D70_2();
extern "C" void _s80193D70_3();
extern "C" void _s80193D70_4();
extern "C" void f_80193D70() {}
