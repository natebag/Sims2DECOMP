// 0x800D23FC _c2DArray::GetArray(BString (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 31,-31952(13); mr 30,3; cmpwi 31,0; beq 2f; 0:; addi 3,31,16; mr 4,30; bl _s800D23FC_0; cmpwi 3,0; beq 1f; mr 3,31; b 3f; 1:; lwz 31,0x0(31); cmpwi 31,0; bne 0b; 2:; li 3,0; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800D23FC_0();
extern "C" void f_800D23FC() {}
