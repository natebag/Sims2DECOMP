// 0x803C2844 TArray<EString, (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; addi 31,4,-1; cmpwi 4,0; beq 1f; 0:; mr 3,30; bl _s803C2844_0; addi 30,30,4; cmpwi 31,0; addi 31,31,-1; bne 0b; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s803C2844_0();
extern "C" void f_803C2844() {}
