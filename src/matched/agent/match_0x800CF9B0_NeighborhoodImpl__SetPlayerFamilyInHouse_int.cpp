// 0x800CF9B0 NeighborhoodImpl::SetPlayerFamilyInHouse(int) (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 11,-21476(13); lis 9,-32697; lwz 30,0x5c5c(9); mr 29,4; lwz 9,0x0(11); mr 4,30; lha 3,0x120(9); lwz 0,0x124(9); add 3,11,3; mtspr 8,0; blrl; mr 31,3; cmpwi 30,0; beq 0f; cmpwi 31,0; beq 0f; lwz 9,0x0(31); mr 4,29; lwz 0,0xb4(9); lha 3,0xb0(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x0(31); li 4,0; lha 3,0x120(9); lwz 0,0x124(9); add 3,31,3; mtspr 8,0; blrl; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void f_800CF9B0() {}
