// 0x801262B0 cXPersonImpl::CancelAllButLastActions(void) (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; li 4,0; lwz 3,0x4(30); lwz 9,0x4(3); lha 0,0xd8(9); lwz 9,0xdc(9); add 3,3,0; mtspr 8,9; blrl; addic. 31,3,-1; blt 2f; 0:; lwz 11,0x4(30); mr 4,31; li 5,0; lwz 9,0x4(11); lwz 0,0xe4(9); lha 3,0xe0(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x4(30); lwz 4,0x38(3); lwz 9,0x4(11); lha 3,0xb8(9); lwz 0,0xbc(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; bne 1f; li 3,0; b 3f; 1:; addic. 31,31,-1; bge 0b; 2:; li 3,1; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_801262B0() {}
