// 0x80129878 cXPersonImpl::IsPersonInFamily(int) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 9,-21476(13); mr 31,3; lwz 11,0x0(9); lha 3,0x120(11); lwz 0,0x124(11); add 3,9,3; mtspr 8,0; blrl; mr. 11,3; beq 0f; lwz 9,0x0(11); lwz 4,0x4(31); lha 3,0x50(9); lwz 0,0x54(9); add 3,11,3; mtspr 8,0; blrl; b 1f; 0:; li 3,0; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void f_80129878() {}
