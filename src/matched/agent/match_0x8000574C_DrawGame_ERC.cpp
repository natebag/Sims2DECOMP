// 0x8000574C DrawGame(ERC (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 9,-26392(13); mr 30,3; lwz 11,0x0(9); lha 3,0x58(11); lwz 0,0x5c(11); add 3,9,3; mtspr 8,0; blrl; cmpwi 3,0; beq 0f; mr 3,30; bl _s8000574C_0; 0:; lis 9,-32697; addi 31,9,23428; lwz 0,0x88(31); cmpwi 0,0; beq 2f; lwz 11,0x3c(31); cmpwi 11,0; beq 1f; lwz 9,0x80(11); mr 4,30; lha 3,0x30(9); lwz 0,0x34(9); add 3,11,3; mtspr 8,0; blrl; 1:; lwz 0,0x88(31); cmpwi 0,0; beq 2f; lwz 0,-28408(13); cmpwi 0,0; beq 2f; lis 9,-32697; mr 4,30; addi 9,9,24012; lwz 3,0xb4(9); bl _s8000574C_1; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8000574C_0();
extern "C" void _s8000574C_1();
extern "C" void f_8000574C() {}
