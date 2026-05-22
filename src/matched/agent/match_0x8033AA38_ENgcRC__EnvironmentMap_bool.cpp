// 0x8033AA38 ENgcRC::EnvironmentMap(bool, (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); cmpwi 4,0; beq 1f; lwz 9,0x70(3); cmpwi 5,0; lwz 11,-26392(13); li 5,1; lha 0,0x118(9); addi 10,9,280; addi 4,11,64; add 3,3,0; beq 0f; li 5,4; 0:; lwz 0,0x4(10); mr 8,6; li 6,1; li 7,0; mtspr 8,0; blrl; b 3f; 1:; lwz 9,0x70(3); cmpwi 6,0; li 4,128; lha 0,0x130(9); addi 11,9,304; add 3,3,0; beq 2f; li 4,256; 2:; lwz 0,0x4(11); mtspr 8,0; blrl; 3:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_8033AA38() {}
