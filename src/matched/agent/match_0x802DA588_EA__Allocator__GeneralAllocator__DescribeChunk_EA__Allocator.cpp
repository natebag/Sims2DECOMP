// 0x802DA588 EA::Allocator::GeneralAllocator::DescribeChunk(EA::Allocator::GeneralAllocator::Chunk (352 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-832(1); mfspr 0,8; stmw 24,0x320(1); stw 0,0x344(1); mr 31,4; addi 28,1,16; lwz 30,0x4(31); mr 24,3; mr 25,5; addi 29,1,280; rlwinm 30,30,0,0,28; mr 26,6; addi 30,30,-8; li 4,0; li 5,257; mr 3,28; crxor 6,6,6; bl _s802DA588_0; addi 27,31,8; li 4,0; li 5,514; mr 3,29; crxor 6,6,6; bl _s802DA588_1; mr 5,30; mr 7,29; mr 4,27; mr 6,28; li 8,256; mr 3,24; bl _s802DA588_2; lbz 0,0x484(24); mr 8,30; lis 5,-32702; stw 28,0x8(1); mr 7,0; addi 5,5,-6640; mr 6,27; stw 0,0xc(1); mr 3,25; mr 4,26; mr 9,8; mr 10,7; crxor 6,6,6; bl _s802DA588_3; mr. 30,3; ble 5f; lwz 0,0x4(31); andi. 9,0,4; mr 11,0; mcrf cr7,cr0; bne cr7,0f; andi. 0,11,2; beq 5f; 0:; add 25,25,30; subf 26,30,26; beq cr7,1f; lis 9,-32702; addi 6,9,-6580; b 2f; 1:; lis 9,-32702; addi 6,9,-6568; 2:; andi. 9,11,2; beq 3f; lis 9,-32702; addi 7,9,-6564; b 4f; 3:; lis 9,-32702; addi 7,9,-6568; 4:; lbz 8,0x484(24); lis 5,-32702; mr 3,25; mr 4,26; addi 5,5,-6596; crxor 6,6,6; bl _s802DA588_4; mr. 3,3; ble 5f; add 30,30,3; 5:; mr 3,30; cmpwi 30,0; bgt 6f; li 3,0; 6:; lwz 0,0x344(1); mtspr 8,0; lmw 24,0x320(1); addi 1,1,832"
extern "C" void _s802DA588_0();
extern "C" void _s802DA588_1();
extern "C" void _s802DA588_2();
extern "C" void _s802DA588_3();
extern "C" void _s802DA588_4();
extern "C" void f_802DA588() {}
