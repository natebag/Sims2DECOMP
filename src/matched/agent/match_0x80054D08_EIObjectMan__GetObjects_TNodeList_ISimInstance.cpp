// 0x80054D08 EIObjectMan::GetObjects(TNodeList<ISimInstance (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 31,0x4(3); mr 30,4; cmpwi 31,0; beq 1f; 0:; lwz 4,0x1c(31); mr 3,30; bl _s80054D08_0; lwz 31,0x10(31); cmpwi 31,0; bne 0b; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80054D08_0();
extern "C" void f_80054D08() {}
