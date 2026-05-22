// 0x801AD65C E2ETarget::ChangeSelectedSlot(char (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; mr 3,5; bl _s801AD65C_0; mr. 3,3; bge 0f; lwz 9,0xb4(31); addi 9,9,-1; stw 9,0xc0(31); b 2f; 0:; lwz 0,0xb4(31); cmpw 3,0; blt 1f; li 0,0; stw 0,0xc0(31); b 2f; 1:; stw 3,0xc0(31); 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s801AD65C_0();
extern "C" void f_801AD65C() {}
