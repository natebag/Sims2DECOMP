// 0x8019EDD8 CASPersonalTarget::SetVariableSubnav(UIScreenID, (376 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; cmpwi 6,0; bne 4f; cmpwi 4,20; bne 4f; cmpwi 5,4; bgt 4f; cmpwi 5,0; blt 4f; mulli 10,5,20; lis 11,-32688; lwz 0,0x0(31); addi 11,11,-16256; lis 9,-32705; addi 4,9,-12576; cmpwi 0,0; mr 30,10; lwzx 5,11,10; beq 0f; lwz 3,0x1c(31); cmpwi 3,0; beq 0f; lwz 6,0x7c(31); li 7,0; bl _s8019EDD8_0; 0:; lis 9,-32688; lwz 0,0x0(31); addi 9,9,-16256; lis 11,-32705; addi 9,9,4; addi 4,11,-12556; lwzx 5,9,30; cmpwi 0,0; beq 1f; lwz 3,0x1c(31); cmpwi 3,0; beq 1f; lwz 6,0x7c(31); li 7,0; bl _s8019EDD8_1; 1:; lis 9,-32688; lwz 0,0x0(31); addi 9,9,-16256; lis 11,-32705; addi 9,9,8; addi 4,11,-12536; lwzx 5,9,30; cmpwi 0,0; beq 2f; lwz 3,0x1c(31); cmpwi 3,0; beq 2f; lwz 6,0x7c(31); li 7,0; bl _s8019EDD8_2; 2:; lis 9,-32688; lwz 0,0x0(31); addi 9,9,-16256; lis 11,-32705; addi 9,9,12; addi 4,11,-12516; lwzx 5,9,30; cmpwi 0,0; beq 3f; lwz 3,0x1c(31); cmpwi 3,0; beq 3f; lwz 6,0x7c(31); li 7,0; bl _s8019EDD8_3; 3:; lis 9,-32688; lwz 0,0x0(31); addi 9,9,-16256; lis 11,-32705; addi 9,9,16; addi 4,11,-12496; lwzx 5,9,30; cmpwi 0,0; beq 4f; lwz 3,0x1c(31); cmpwi 3,0; beq 4f; lwz 6,0x7c(31); li 7,0; bl _s8019EDD8_4; 4:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8019EDD8_0();
extern "C" void _s8019EDD8_1();
extern "C" void _s8019EDD8_2();
extern "C" void _s8019EDD8_3();
extern "C" void _s8019EDD8_4();
extern "C" void f_8019EDD8() {}
