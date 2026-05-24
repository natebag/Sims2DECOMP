// 0x800F2FD4 ObjectModuleImpl::Save(iResFile (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-104(1); mfspr 0,8; stmw 27,0x54(1); stw 0,0x6c(1); lwz 11,-21508(13); mr 28,3; mr 29,4; lwz 27,-32040(13); lwz 9,0x0(11); addi 31,1,8; lha 3,0x120(9); lwz 0,0x124(9); add 3,11,3; mtspr 8,0; blrl; lwz 30,0x2c(28); cmpwi 30,0; beq 1f; 0:; lwz 9,0xec(30); lha 3,0x38(9); lwz 0,0x3c(9); add 3,30,3; mtspr 8,0; blrl; lwz 30,0x5c(30); cmpwi 30,0; bne 0b; 1:; lis 5,20322; mr 7,27; li 6,1; mr 4,29; ori 5,5,27213; mr 3,28; bl _s800F2FD4_0; mr 30,3; addi 4,31,8; li 5,64; mr 3,31; bl _s800F2FD4_1; lwz 9,0xc(29); lis 5,17493; mr 7,31; li 4,0; lha 3,0xf8(9); ori 5,5,19792; lwz 0,0xfc(9); li 6,1; add 3,29,3; li 8,0; mtspr 8,0; blrl; mr 3,30; lwz 0,0x6c(1); mtspr 8,0; lmw 27,0x54(1); addi 1,1,104"

extern "C" void _s800F2FD4_0();
extern "C" void _s800F2FD4_1();

struct ObjectModuleImpl {
    void Save();
};

void ObjectModuleImpl::Save() {
}
