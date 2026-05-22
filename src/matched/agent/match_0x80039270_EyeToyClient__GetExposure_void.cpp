// 0x80039270 EyeToyClient::GetExposure(void) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 3,-32576(13); cmpwi 3,-1; beq 1f; bl _s80039270_0; lis 9,-32707; lfs f1,0x4(3); lfs f0,0x16d0(9); fcmpu 0,f1,f0; beq 0f; fadds f1,f1,f1; b 2f; 0:; fmr f1,f0; b 2f; 1:; lfs f1,-25036(13); 2:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80039270_0();
extern "C" void f_80039270() {}
