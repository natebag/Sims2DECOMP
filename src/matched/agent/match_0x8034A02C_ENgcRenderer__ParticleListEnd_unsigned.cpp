// 0x8034A02C ENgcRenderer::ParticleListEnd(unsigned (1116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-160(1); mfspr 0,8; stmw 23,0x7c(1); stw 0,0xa4(1); mr 25,3; mr. 31,4; bne 0f; bl _s8034A02C_0; lwz 4,0x465c(25); bl _s8034A02C_1; stw 31,0x465c(25); b 4f; 0:; lwz 0,0x510(25); cmpwi 0,0; beq 1f; mr 3,25; li 4,0; bl _s8034A02C_2; 1:; lwz 9,0x4d8(25); li 0,0; lwz 28,0x465c(25); li 10,1; lwz 11,0x6cc(9); li 8,15; stw 0,0x4c(9); addi 4,1,8; oris 11,11,32768; stw 0,0x4(9); ori 11,11,1; stw 0,0x28(9); stw 11,0x6cc(9); stw 0,0x2c(9); stw 0,0x30(9); stw 0,0x38(9); stw 0,0x3c(9); stw 0,0x40(9); stw 0,0x44(9); stw 0,0x48(9); lwz 11,0x4d8(25); lwz 0,0x6cc(11); stw 10,0x28(11); oris 0,0,32768; ori 0,0,1; stw 0,0x6cc(11); lwz 9,0x4d8(25); lwz 0,0x6cc(9); stw 10,0x30(9); oris 0,0,32768; ori 0,0,1; stw 0,0x6cc(9); lwz 11,0x4d8(25); lwz 0,0x6cc(11); stw 10,0x38(11); oris 0,0,32768; ori 0,0,1; stw 0,0x6cc(11); lwz 9,0x4d8(25); lwz 0,0x6cc(9); stw 8,0x0(9); oris 0,0,32768; stw 0,0x6cc(9); lwz 11,0x4d8(25); lwz 0,0x6cc(11); oris 0,0,32768; stw 0,0x6cc(11); lwz 3,0x4d8(25); addi 3,3,1952; bl _s8034A02C_3; lwz 3,0x4d8(25); li 4,0; bl _s8034A02C_4; li 3,128; li 4,7; rlwinm 5,31,2,16,29; bl _s8034A02C_5; cmpwi 31,0; ble 3f; mr 23,31; addi 26,1,72; addi 24,1,56; addi 27,1,88; addi 31,1,104; lis 29,-13311; 2:; li 4,0; li 5,12; mr 3,26; crxor 6,6,6; bl _s8034A02C_6; lfs f0,0x0(28); li 4,0; li 5,12; mr 3,27; stfs f0,0x48(1); lfs f13,0x4(28); lwz 11,0x48(1); stfs f13,0x4c(1); lfs f0,0x8(28); stfs f0,0x50(1); lwz 0,0x4(26); lwz 9,0x8(26); stw 11,0x38(1); stw 0,0x4(24); stw 9,0x8(24); crxor 6,6,6; bl _s8034A02C_7; lfs f0,0x10(28); li 4,0; li 5,12; mr 3,31; stfs f0,0x58(1); lwz 0,0x58(1); lwz 9,0x4(27); lwz 11,0x8(27); stw 0,0x48(1); stw 9,0x4(26); stw 11,0x8(26); crxor 6,6,6; bl _s8034A02C_8; lfs f0,0x14(28); addi 3,1,8; lwz 11,0x68(1); mr 4,26; stfs f0,0x6c(1); mr 5,26; lwz 0,0x4(31); lwz 9,0x8(31); stw 11,0x58(1); stw 0,0x4(27); stw 9,0x8(27); bl _s8034A02C_9; addi 3,1,8; mr 4,27; mr 5,27; bl _s8034A02C_10; lbz 30,0x2f(28); mr 3,24; mr 4,26; mr 5,31; rlwinm 30,30,1,24,30; bl _s8034A02C_11; mr 3,31; mr 4,27; mr 5,31; bl _s8034A02C_12; lwz 3,0x4d8(25); mr 4,31; mr 5,31; addi 3,3,2144; bl _s8034A02C_13; lfs f0,0x68(1); mr 3,24; lfs f13,0x6c(1); mr 4,26; stfs f0,-32768(29); mr 5,31; lfs f0,0x70(1); stfs f13,-32768(29); stfs f0,-32768(29); lbz 0,0x23(28); lbz 9,0x27(28); lbz 11,0x2b(28); stb 0,-32768(29); stb 9,-32768(29); stb 11,-32768(29); stb 30,-32768(29); lfs f0,0x30(28); lfs f13,0x34(28); stfs f0,-32768(29); stfs f13,-32768(29); bl _s8034A02C_14; mr 3,31; mr 4,27; mr 5,31; bl _s8034A02C_15; lwz 3,0x4d8(25); mr 4,31; mr 5,31; addi 3,3,2144; bl _s8034A02C_16; lfs f0,0x68(1); mr 3,24; lfs f13,0x6c(1); mr 4,26; stfs f0,-32768(29); mr 5,31; lfs f0,0x70(1); stfs f13,-32768(29); stfs f0,-32768(29); lbz 0,0x23(28); lbz 9,0x27(28); lbz 11,0x2b(28); stb 0,-32768(29); stb 9,-32768(29); stb 11,-32768(29); stb 30,-32768(29); lfs f0,0x30(28); lfs f13,0x3c(28); stfs f0,-32768(29); stfs f13,-32768(29); bl _s8034A02C_17; mr 3,31; mr 4,27; mr 5,31; bl _s8034A02C_18; lwz 3,0x4d8(25); mr 4,31; mr 5,31; addi 3,3,2144; bl _s8034A02C_19; lfs f0,0x68(1); mr 3,24; lfs f13,0x6c(1); mr 4,26; stfs f0,-32768(29); mr 5,31; lfs f0,0x70(1); stfs f13,-32768(29); stfs f0,-32768(29); lbz 0,0x23(28); lbz 9,0x27(28); lbz 11,0x2b(28); stb 0,-32768(29); stb 9,-32768(29); stb 11,-32768(29); stb 30,-32768(29); lfs f0,0x38(28); lfs f13,0x3c(28); stfs f0,-32768(29); stfs f13,-32768(29); bl _s8034A02C_20; mr 3,31; mr 4,27; mr 5,31; bl _s8034A02C_21; lwz 3,0x4d8(25); mr 4,31; mr 5,31; addi 3,3,2144; bl _s8034A02C_22; lfs f0,0x68(1); addic. 23,23,-1; lfs f12,0x6c(1); stfs f0,-32768(29); lfs f13,0x70(1); stfs f12,-32768(29); stfs f13,-32768(29); lbz 0,0x23(28); lbz 9,0x27(28); lbz 11,0x2b(28); stb 0,-32768(29); stb 9,-32768(29); stb 11,-32768(29); stb 30,-32768(29); lfs f0,0x38(28); lfs f13,0x34(28); stfs f0,-32768(29); addi 28,28,64; stfs f13,-32768(29); bne 2b; 3:; lwz 9,0x4d8(25); li 11,12; lwz 0,0x6cc(9); stw 11,0x0(9); oris 0,0,32768; stw 0,0x6cc(9); lwz 11,0x4d8(25); lwz 0,0x6cc(11); oris 0,0,32768; stw 0,0x6cc(11); bl _s8034A02C_23; lwz 4,0x465c(25); bl _s8034A02C_24; li 0,0; stw 0,0x465c(25); 4:; lwz 0,0xa4(1); mtspr 8,0; lmw 23,0x7c(1); addi 1,1,160"
extern "C" void _s8034A02C_0();
extern "C" void _s8034A02C_1();
extern "C" void _s8034A02C_2();
extern "C" void _s8034A02C_3();
extern "C" void _s8034A02C_4();
extern "C" void _s8034A02C_5();
extern "C" void _s8034A02C_6();
extern "C" void _s8034A02C_7();
extern "C" void _s8034A02C_8();
extern "C" void _s8034A02C_9();
extern "C" void _s8034A02C_10();
extern "C" void _s8034A02C_11();
extern "C" void _s8034A02C_12();
extern "C" void _s8034A02C_13();
extern "C" void _s8034A02C_14();
extern "C" void _s8034A02C_15();
extern "C" void _s8034A02C_16();
extern "C" void _s8034A02C_17();
extern "C" void _s8034A02C_18();
extern "C" void _s8034A02C_19();
extern "C" void _s8034A02C_20();
extern "C" void _s8034A02C_21();
extern "C" void _s8034A02C_22();
extern "C" void _s8034A02C_23();
extern "C" void _s8034A02C_24();
extern "C" void f_8034A02C() {}
