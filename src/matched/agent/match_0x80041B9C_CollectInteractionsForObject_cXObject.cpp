// 0x80041B9C CollectInteractionsForObject(cXObject (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr. 3,3; beq 0f; lis 9,-32697; rlwinm 0,5,2,0,29; addi 9,9,24012; addi 9,9,188; lwzx 5,9,0; cmpwi 5,0; beq 0f; bl _s80041B9C_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80041B9C_0();
extern "C" void f_80041B9C() {}
