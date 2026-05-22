// 0x8012C2B8 cXPersonImpl::GetNormalSimDescription(void) (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x188(9); lwz 9,0x18c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 0f; lwz 11,0x4(31); lwz 9,0x4(11); lwz 0,0x18c(9); lha 3,0x188(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0x604(3); cmpwi 0,0; beq 0f; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x188(9); lwz 9,0x18c(9); add 3,3,0; mtspr 8,9; blrl; lwz 3,0x604(3); b 1f; 0:; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x150(9); lwz 9,0x154(9); add 3,3,0; mtspr 8,9; blrl; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void f_8012C2B8() {}
