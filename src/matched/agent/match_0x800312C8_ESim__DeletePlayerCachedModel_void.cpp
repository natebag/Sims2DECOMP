// 0x800312C8 ESim::DeletePlayerCachedModel(void) (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); lis 9,-32697; li 4,-1; addi 0,9,21760; lwz 11,0x5500(9); stw 0,0x8(1); lha 3,0x10(11); lwz 9,0x14(11); add 3,3,0; mtspr 8,9; blrl; lwz 3,-32632(13); cmpwi 3,0; beq 0f; li 4,3; bl _s800312C8_0; li 0,0; stw 0,-32632(13); 0:; lwz 3,-32628(13); cmpwi 3,0; beq 1f; li 4,3; bl _s800312C8_1; li 0,0; stw 0,-32628(13); 1:; lwz 3,0x8(1); lwz 9,0x0(3); lha 0,0x18(9); lwz 9,0x1c(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s800312C8_0();
extern "C" void _s800312C8_1();
extern "C" void f_800312C8() {}
