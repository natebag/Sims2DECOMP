// 0x80312790 EResPrefetch::LoadAnotherBlock(void) (500 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 31,0x1c(1); stw 0,0x24(1); mr 31,3; lwz 9,0x3e8(31); lwz 0,0x3fc(31); cmplw 9,0; ble 1f; lwz 9,0x404(31); lwz 0,0x400(31); cmplw 9,0; bge 0f; lwz 3,0x3dc(31); lwz 4,0x408(31); lwz 5,0x3e4(31); lwz 6,0x3f8(31); bl _s80312790_0; lwz 8,0x404(31); lis 0,17200; lwz 7,0x400(31); addi 8,8,1; mr 10,11; stw 8,0x14(1); lis 9,-32702; lfd f12,0x560(9); stw 0,0x10(1); lwz 9,0x408(31); lfd f13,0x10(1); stw 7,0x14(1); fsub f13,f13,f12; lwz 11,0x3f8(31); stw 0,0x10(1); frsp f13,f13; lwz 0,0x3e4(31); add 9,9,11; lfd f0,0x10(1); add 0,0,11; stw 9,0x408(31); fsub f0,f0,f12; stw 0,0x3e4(31); frsp f0,f0; stw 8,0x404(31); fdivs f13,f13,f0; stfs f13,0x410(31); 0:; lwz 9,0x404(31); lwz 0,0x400(31); cmpw 9,0; bne 3f; lis 9,-32702; li 0,0; lfs f0,0x568(9); stw 0,0x414(31); stfs f0,0x410(31); b 3f; 1:; lwz 9,0x404(31); lwz 0,0x3f0(31); cmplw 9,0; bge 2f; lwz 4,0x408(31); lwz 5,0x3e4(31); lwz 6,0x3f8(31); lwz 3,0x3dc(31); bl _s80312790_1; lwz 8,0x404(31); lis 6,17200; lwz 5,0x3f0(31); addi 8,8,1; mr 7,10; stw 8,0x14(1); lis 9,-32702; lfd f12,0x560(9); stw 6,0x10(1); lwz 11,0x408(31); lfd f13,0x10(1); stw 5,0x14(1); fsub f13,f13,f12; lwz 9,0x3f8(31); stw 6,0x10(1); frsp f13,f13; lwz 0,0x3e4(31); add 11,11,9; lfd f0,0x10(1); lwz 4,0x3f4(31); add 0,0,9; fsub f0,f0,f12; stw 11,0x408(31); frsp f0,f0; cmpwi 4,0; fdivs f13,f13,f0; stw 0,0x3e4(31); stw 8,0x404(31); stfs f13,0x410(31); bne 3f; cmpw 8,5; bne 3f; lis 9,-32702; stw 4,0x414(31); lfs f0,0x568(9); stfs f0,0x410(31); b 3f; 2:; lwz 6,0x3f4(31); cmpwi 6,0; beq 3f; lwz 3,0x3dc(31); lwz 4,0x408(31); lwz 5,0x3e4(31); bl _s80312790_2; lwz 9,0x408(31); lis 10,-32702; lwz 11,0x3f4(31); li 8,0; lwz 0,0x3e4(31); lfs f0,0x568(10); add 9,9,11; add 0,0,11; stw 9,0x408(31); stfs f0,0x410(31); stw 0,0x3e4(31); stw 8,0x414(31); 3:; lwz 0,0x24(1); mtspr 8,0; lwz 31,0x1c(1); addi 1,1,32"

extern "C" void _s80312790_0();
extern "C" void _s80312790_1();
extern "C" void _s80312790_2();

struct EResPrefetch {
    void LoadAnotherBlock();
};

void EResPrefetch::LoadAnotherBlock() {
}
