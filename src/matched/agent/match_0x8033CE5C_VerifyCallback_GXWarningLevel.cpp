// 0x8033CE5C VerifyCallback(GXWarningLevel, (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 3,5; cmpwi 4,999; bgt 1f; lis 9,-32690; rlwinm 31,4,2,0,29; addi 30,9,-25768; lwzx 0,30,31; cmplwi 0,2; bgt 0f; crxor 6,6,6; bl _s8033CE5C_0; 0:; lwzx 9,30,31; addi 9,9,1; stwx 9,30,31; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8033CE5C_0();
extern "C" void f_8033CE5C() {}
