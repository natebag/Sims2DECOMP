// 0x80099670 TheSimsStateMachine::Shutdown(void) (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 11,0x98(31); cmpwi 11,0; beq 0f; lwz 9,0x80(11); li 4,3; lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stw 0,0x98(31); 0:; addi 3,31,60; bl _s80099670_0; lis 9,-32697; addi 31,9,23428; lwz 11,0x68(31); cmpwi 11,0; beq 1f; lwz 9,0x80(11); li 4,3; lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stw 0,0x68(31); 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80099670_0();
extern "C" void f_80099670() {}
