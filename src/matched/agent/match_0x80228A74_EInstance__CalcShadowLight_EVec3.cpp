// 0x80228A74 EInstance::CalcShadowLight(EVec3 (300 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stw 31,0x2c(1); stw 0,0x34(1); mr 31,4; mr. 5,5; blt 3f; mulli 0,5,84; lwz 9,0x4(3); add 9,9,0; addi 11,9,24636; lwz 10,0x3c(11); cmpwi 10,0; beq 0f; addi 9,11,32; lfs f11,0x8c(10); lfs f0,0x20(11); addi 10,1,8; lfs f13,0x8(9); lfs f12,0x4(9); fmuls f0,f0,f11; fmuls f13,f13,f11; stfs f0,0x8(1); fmuls f12,f12,f11; stfs f13,0x10(1); stfs f12,0xc(1); lwz 9,0x8(1); lwz 11,0x8(10); lwz 0,0x4(10); stw 9,0x0(31); stw 0,0x4(31); stw 11,0x8(31); b 2f; 0:; addi 9,3,60; addi 11,3,72; lfs f0,0x4(11); lis 8,-32704; lfs f9,0x4(9); lis 10,-32704; lfs f11,0x48(3); lfs f12,0x3c(3); fadds f9,f9,f0; lfs f0,-6156(8); lfs f13,0x8(9); fadds f12,f12,f11; lfs f10,0x8(11); fmuls f11,f9,f0; lwz 0,0xc(3); fmuls f0,f12,f0; lfs f8,-6152(10); fadds f13,f13,f10; stfs f13,0x20(1); cmpwi 0,0; stfs f0,0x8(1); stfs f11,0xc(1); stfs f8,0x10(1); stfs f12,0x18(1); stfs f9,0x1c(1); beq 1f; mr 6,5; addi 4,1,8; mr 5,31; bl _s80228A74_0; b 2f; 1:; mr 6,5; addi 4,1,8; mr 5,31; bl _s80228A74_1; 2:; mr 3,31; bl _s80228A74_2; 3:; lwz 0,0x34(1); mtspr 8,0; lwz 31,0x2c(1); addi 1,1,48"
extern "C" void _s80228A74_0();
extern "C" void _s80228A74_1();
extern "C" void _s80228A74_2();
extern "C" void f_80228A74() {}
