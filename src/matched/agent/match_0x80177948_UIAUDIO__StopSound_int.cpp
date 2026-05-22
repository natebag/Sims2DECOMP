// 0x80177948 UIAUDIO::StopSound(int) (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lis 9,-32697; mr 30,3; lwz 0,0x6200(9); cmpwi 0,0; beq 0f; rlwinm 31,4,2,0,29; addi 28,30,16; lwzx 0,28,31; cmpwi 0,0; beq 0f; addi 29,30,56; lwzx 4,29,31; cmpwi 4,0; beq 0f; lwz 3,-22572(13); bl _s80177948_0; li 0,0; addi 9,30,36; stwx 0,29,31; stwx 0,9,31; lwz 11,-26564(13); lwzx 4,28,31; lwz 9,0x0(11); lha 3,0xa0(9); lwz 0,0xa4(9); add 3,11,3; mtspr 8,0; blrl; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80177948_0();
extern "C" void f_80177948() {}
