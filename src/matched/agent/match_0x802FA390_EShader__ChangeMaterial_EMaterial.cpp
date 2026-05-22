// 0x802FA390 EShader::ChangeMaterial(EMaterial (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lfs f0,0x0(4); addi 10,3,16; addi 9,4,16; addi 11,10,16; stfs f0,0x10(3); addi 8,4,32; addi 7,3,48; lfs f0,0x4(4); stfs f0,0x4(10); lfs f13,0x8(4); stfs f13,0x8(10); lfs f0,0xc(4); stfs f0,0xc(10); lfs f13,0x10(4); stfs f13,0x10(10); lfs f0,0x4(9); stfs f0,0x4(11); lfs f13,0x8(9); stfs f13,0x8(11); lfs f0,0xc(9); stfs f0,0xc(11); lwz 0,0x20(4); lwz 9,0x8(8); lwz 11,0x4(8); stw 0,0x30(3); stw 9,0x8(7); stw 11,0x4(7); lfs f0,0x2c(4); stfs f0,0x2c(10); lwz 9,0xf0(3); lha 0,0x60(9); lwz 9,0x64(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_802FA390() {}
