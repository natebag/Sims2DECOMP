// 0x801A5000 CRDTarget::EndCredits(void) (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 0,1; lwz 4,0xf4(31); li 30,0; stw 0,0x9c(31); stw 30,0xa0(31); cmpwi 4,0; beq 0f; lwz 3,-26392(13); lwz 9,0x0(3); lha 0,0x110(9); lwz 9,0x114(9); add 3,3,0; mtspr 8,9; blrl; stw 30,0xf4(31); 0:; lwz 4,0xf0(31); cmpwi 4,0; beq 1f; lwz 3,-26392(13); lwz 9,0x0(3); lha 0,0xc0(9); lwz 9,0xc4(9); add 3,3,0; mtspr 8,9; blrl; stw 30,0xf0(31); 1:; lwz 4,0xc4(31); cmpwi 4,0; beq 2f; lwz 3,-26392(13); lwz 9,0x0(3); lha 0,0xd8(9); lwz 9,0xdc(9); add 3,3,0; mtspr 8,9; blrl; stw 30,0xc4(31); 2:; lwz 3,0xb8(31); cmpwi 3,0; beq 3f; bl _s801A5000_0; stw 30,0xb8(31); 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801A5000_0();
extern "C" void f_801A5000() {}
