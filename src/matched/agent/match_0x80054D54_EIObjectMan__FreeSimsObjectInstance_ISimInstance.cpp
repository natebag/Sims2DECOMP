// 0x80054D54 EIObjectMan::FreeSimsObjectInstance(ISimInstance (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,4; lwz 4,0x4(3); cmpwi 4,0; beq 2f; 0:; lwz 0,0x1c(4); cmpw 31,0; bne 1f; lwz 4,0x18(4); b 3f; 1:; lwz 4,0x10(4); cmpwi 4,0; bne 0b; 2:; li 4,-1; 3:; addi 3,3,4; bl _s80054D54_0; cmpwi 31,0; beq 4f; lwz 9,0x0(31); li 4,3; lha 3,0x30(9); lwz 0,0x34(9); add 3,31,3; mtspr 8,0; blrl; 4:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80054D54_0();
extern "C" void f_80054D54() {}
