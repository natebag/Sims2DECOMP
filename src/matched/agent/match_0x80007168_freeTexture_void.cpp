// 0x80007168 freeTexture(void (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32697; rlwinm 31,3,2,0,29; addi 30,9,672; lwzx 4,30,31; cmpwi 4,0; beq 0f; lwz 11,-26392(13); lwz 9,0x0(11); lwz 0,0x114(9); lha 3,0x110(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stwx 0,30,31; 0:; lis 9,-32697; addi 30,9,-728; lwzx 3,30,31; cmpwi 3,0; beq 1f; bl _s80007168_0; li 0,0; stwx 0,30,31; 1:; lis 9,-32697; li 0,-1; addi 9,9,2072; stwx 0,9,31; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80007168_0();
extern "C" void f_80007168() {}
