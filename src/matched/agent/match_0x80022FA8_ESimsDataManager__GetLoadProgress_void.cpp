// 0x80022FA8 ESimsDataManager::GetLoadProgress(void) (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); lwz 0,0xd20(3); cmpwi 0,1; beq 0f; lis 9,-32707; lfs f1,0x620(9); b 2f; 0:; lwz 7,0xd28(3); cmpwi 7,0; beq 1f; lwz 0,0xd24(3); lis 8,17200; mr 10,11; xoris 0,0,32768; xoris 7,7,32768; stw 0,0xc(1); lis 9,-32707; lfd f13,0x628(9); stw 8,0x8(1); lfd f0,0x8(1); stw 7,0xc(1); fsub f0,f0,f13; stw 8,0x8(1); frsp f0,f0; lfd f1,0x8(1); fsub f1,f1,f13; frsp f1,f1; fdivs f1,f0,f1; b 2f; 1:; lis 9,-32707; lfs f1,0x624(9); 2:; addi 1,1,16"
extern "C" void f_80022FA8() {}
