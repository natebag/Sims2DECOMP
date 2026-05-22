// 0x80187C9C HUDTarget::OnReadBar(int, (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lhz 0,0xc8(31); cmpwi 0,9; bgt 0f; cmpwi 0,1; blt 0f; cmpwi 5,5; bne 1f; lwz 0,0xa0(31); cmpwi 0,0; beq 1f; bl _s80187C9C_0; mulli 0,30,6; addi 9,31,169; stbx 3,9,0; b 1f; 0:; mr 3,31; mr 4,30; bl _s80187C9C_1; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80187C9C_0();
extern "C" void _s80187C9C_1();
extern "C" void f_80187C9C() {}
