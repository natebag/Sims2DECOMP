// 0x80148550 TreeSimImpl::Simulate(int) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lis 9,-32706; mr 31,3; lfs f0,-10292(9); li 0,0; stw 0,0x4(31); stfs f0,0x8(31); 0:; lwz 11,0x0(31); lwz 9,0x18(11); lha 3,0x48(9); lwz 0,0x4c(9); add 3,11,3; mtspr 8,0; blrl; mr 4,3; mr 3,31; bl _s80148550_0; cmpwi 3,1; beq 1f; ble 0b; cmpwi 3,2; beq 2f; b 0b; 1:; li 3,1; b 3f; 2:; li 3,0; 3:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80148550_0();
extern "C" void f_80148550() {}
