// 0x80321760 ArcFileInfo::OnValidated(void) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 9,-22652(13); mr 31,3; lwz 4,0x4(31); lwz 11,0x0(9); lha 3,0xa0(11); lwz 0,0xa4(11); add 3,9,3; mtspr 8,0; blrl; mr. 3,3; beq 0f; lwz 11,-22652(13); li 0,1; stw 0,0x10(31); mr 4,3; lwz 9,0x0(11); lha 3,0xb0(9); lwz 0,0xb4(9); add 3,11,3; mtspr 8,0; blrl; 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void f_80321760() {}
