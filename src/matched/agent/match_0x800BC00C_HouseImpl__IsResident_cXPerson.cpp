// 0x800BC00C HouseImpl::IsResident(cXPerson (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 11,-21424(13); mr 31,4; lwz 9,0x0(11); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,11,3; blrl; mr 11,3; mr 4,31; lwz 9,0x0(11); lha 3,0x50(9); lwz 0,0x54(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; beq 0f; li 3,1; b 2f; 0:; lis 9,-32697; lwz 0,0x5c6c(9); cmpwi 0,0; bne 1f; lwz 11,-21476(13); li 4,1; lwz 9,0x0(11); lwz 0,0x124(9); lha 3,0x120(9); mtspr 8,0; add 3,11,3; blrl; mr 11,3; mr 4,31; lwz 9,0x0(11); lha 3,0x50(9); lwz 0,0x54(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; li 3,1; bne 2f; 1:; li 3,0; 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void f_800BC00C() {}
