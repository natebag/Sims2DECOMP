// 0x800BF0DC IFFResFile2::GetResType(Memory::HandleNode (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; mr 30,4; lwz 9,0xc(31); lha 3,0x60(9); lwz 0,0x64(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 0f; mr 3,31; li 4,-49; bl _s800BF0DC_0; b 1f; 0:; mr 3,31; li 4,0; bl _s800BF0DC_1; 1:; mr 3,31; bl _s800BF0DC_2; cmpwi 3,0; li 3,0; bne 3f; lwz 3,0x138(31); mr 4,30; addi 5,1,8; li 6,0; bl _s800BF0DC_3; cmpwi 3,0; bne 2f; mr 3,31; li 4,-98; bl _s800BF0DC_4; li 3,0; b 3f; 2:; lwz 3,0x8(1); 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s800BF0DC_0();
extern "C" void _s800BF0DC_1();
extern "C" void _s800BF0DC_2();
extern "C" void _s800BF0DC_3();
extern "C" void _s800BF0DC_4();
extern "C" void f_800BF0DC() {}
