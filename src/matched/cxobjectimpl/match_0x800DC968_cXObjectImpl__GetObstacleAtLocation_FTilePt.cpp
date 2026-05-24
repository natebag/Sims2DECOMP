// 0x800DC968 cXObjectImpl::GetObstacleAtLocation(FTilePt (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; mfcr 12; stmw 30,0x10(1); stw 0,0x1c(1); stw 12,0xc(1); cmpwi 4,6,0; li 30,0; bl _s800DC968_0; b 2f; 0:; beq cr4,1f; lwz 9,0x4(31); lha 3,0x50(9); lwz 0,0x54(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 1f; mr 30,31; 1:; lwz 9,0x4(31); lha 3,0x2f8(9); lwz 0,0x2fc(9); add 3,31,3; mtspr 8,0; blrl; 2:; mr 31,3; cmpwi 31,0; beq 3f; lwz 9,0x4(31); lha 3,0x478(9); lwz 0,0x47c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 0b; b 4f; 3:; mr 3,30; cmpwi 30,0; bne 5f; 4:; mr 3,31; 5:; lwz 0,0x1c(1); lwz 12,0xc(1); mtspr 8,0; lmw 30,0x10(1); mtcrf 8,12; addi 1,1,24"

extern "C" void _s800DC968_0();

struct cXObjectImpl {
    void GetObstacleAtLocation_FTilePt();
};

void cXObjectImpl::GetObstacleAtLocation_FTilePt() {
}
