// 0x802B6220 AptPrototype::SetSuperConstructor(AptValue (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 11,4; lwz 31,0x20(3); cmpwi 11,0; stw 11,0x20(3); beq 0f; lwz 9,0x8(11); lis 4,-32703; lis 5,-32703; addi 4,4,19328; lha 3,0x8(9); addi 5,5,19380; lwz 0,0xc(9); li 6,218; add 3,11,3; mtspr 8,0; blrl; 0:; cmpwi 31,0; beq 1f; lwz 9,0x8(31); lis 4,-32703; lis 5,-32703; addi 4,4,19328; lha 3,0x10(9); addi 5,5,19380; lwz 0,0x14(9); li 6,219; add 3,31,3; mtspr 8,0; blrl; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void f_802B6220() {}
