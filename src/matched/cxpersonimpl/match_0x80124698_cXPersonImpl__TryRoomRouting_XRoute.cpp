// 0x80124698 cXPersonImpl::TryRoomRouting(XRoute (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,4; mr 31,3; lwz 0,0x6c(29); cmpwi 0,0; bne 0f; lwz 9,0x0(31); lwz 11,0x4(31); lwz 3,0x58(9); lwz 4,0x0(11); lwz 5,0x4c(29); bl _s80124698_0; cmpwi 3,0; beq 1f; 0:; lwz 9,0x0(31); lwz 11,0x4(31); lwz 3,0x58(9); lwz 4,0x0(11); lwz 5,0x4c(29); bl _s80124698_1; mr. 30,3; beq 1f; lwz 11,0x0(30); li 4,15; lwz 10,0x0(11); lwz 9,0x4(10); lha 3,0x1d0(9); lwz 0,0x1d4(9); add 3,10,3; mtspr 8,0; blrl; mr. 3,3; beq 1f; lwz 10,0x4(31); mr 6,3; lwz 11,0x0(30); li 5,0; lwz 9,0x4(10); li 7,0; lwz 4,0x0(11); lha 3,0x40(9); lwz 0,0x44(9); add 3,10,3; mtspr 8,0; blrl; cmpwi 3,0; bne 2f; 1:; li 3,0; b 3f; 2:; lwz 11,0x4(31); mr 5,30; lwz 9,0x0(31); lwz 4,0x0(11); lwz 3,0x58(9); bl _s80124698_2; stw 30,0x6c(29); li 3,1; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s80124698_0();
extern "C" void _s80124698_1();
extern "C" void _s80124698_2();

struct cXPersonImpl {
    void TryRoomRouting_XRoute();
};

void cXPersonImpl::TryRoomRouting_XRoute() {
}
