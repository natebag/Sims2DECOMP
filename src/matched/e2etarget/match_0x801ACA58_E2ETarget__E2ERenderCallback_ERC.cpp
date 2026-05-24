// 0x801ACA58 E2ETarget::E2ERenderCallback(ERC (476 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 29,0x3c(1); stw 0,0x4c(1); lwz 0,0x88(3); mr 31,4; mr 30,5; cmpwi 0,0; beq 0f; lwz 9,-30452(13); lwz 0,0x8c(9); cmpwi 0,0; bne 0f; bl _s801ACA58_0; mr. 3,3; beq 0f; lwz 9,0x70(31); mr 4,3; li 5,0; lwz 0,0x124(9); lha 3,0x120(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x70(31); li 5,0; li 4,16; lwz 0,0x154(9); lha 3,0x150(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x70(31); li 4,0; lwz 0,0x13c(9); lha 3,0x138(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x70(31); li 7,0; li 4,0; li 5,2; lwz 0,0x1cc(9); li 6,0; lha 3,0x1c8(9); mtspr 8,0; add 3,31,3; blrl; lwz 11,0x70(31); lis 9,-32705; lfs f1,-2008(9); li 6,0; lwz 0,0x1d4(11); li 4,0; lha 3,0x1d0(11); li 5,5; mtspr 8,0; add 3,31,3; blrl; lwz 9,0x70(31); li 4,1; li 5,0; lwz 0,0x204(9); lha 3,0x200(9); mtspr 8,0; add 3,31,3; blrl; lwz 11,0x0(30); lis 9,-32705; lfs f7,-2004(9); lis 10,-32705; lwz 9,0x4(30); lis 8,-32705; lfs f12,0x0(11); addi 30,1,8; lfs f11,0x4(11); lis 7,-32705; lfs f8,-2000(10); fdivs f12,f12,f7; lfs f10,0x4(9); addi 11,1,24; lfs f13,0x0(9); addi 10,1,32; lwz 29,0x70(31); addi 9,1,40; lfs f9,-1996(8); mr 4,30; lha 3,0x188(29); mr 6,11; lfs f0,-1992(7); mr 8,9; mr 7,10; add 3,31,3; addi 5,1,16; fdivs f11,f11,f8; stfs f12,0x8(1); fdivs f13,f13,f7; stfs f11,0x4(30); stfs f9,0x18(1); fdivs f10,f10,f8; stfs f13,0x10(1); stfs f10,0x14(1); fmr f1,f0; stfs f0,0x4(11); stfs f0,0x20(1); stfs f9,0x4(10); stfs f0,0x28(1); stfs f0,0x4(9); stfs f0,0x8(9); stfs f0,0xc(9); lwz 0,0x18c(29); mtspr 8,0; blrl; 0:; lwz 0,0x4c(1); mtspr 8,0; lmw 29,0x3c(1); addi 1,1,72"

extern "C" void _s801ACA58_0();

struct E2ETarget {
    void E2ERenderCallback();
};

void E2ETarget::E2ERenderCallback() {
}
