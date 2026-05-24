// 0x8033F80C ENgcRenderer::SetupTEVStagePassColor(_GXTevStageID) (464 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); stmw 23,0xc(1); lwz 9,0x4d8(3); lis 6,-32700; rlwinm 26,4,2,0,29; addi 6,6,11008; lwz 0,0x6cc(9); mulli 4,4,92; lwz 11,0x6d0(9); li 10,255; oris 0,0,32768; addi 27,9,112; ori 0,0,128; addi 29,9,116; stw 0,0x6cc(9); addi 30,9,120; li 5,4; li 7,15; lwzx 0,6,26; li 25,10; li 28,7; li 24,5; or 11,11,0; li 8,0; stw 11,0x6d0(9); li 23,1; stwx 10,27,4; stwx 10,29,4; stwx 5,30,4; lwz 9,0x4d8(3); lwz 11,0x6cc(9); addi 27,9,124; lwz 10,0x6d0(9); addi 29,9,128; oris 11,11,32768; addi 30,9,132; ori 11,11,128; addi 5,9,136; stw 11,0x6cc(9); lwzx 0,6,26; or 10,10,0; stw 10,0x6d0(9); stwx 7,27,4; stwx 7,29,4; stwx 7,30,4; stwx 25,5,4; lwz 9,0x4d8(3); lwz 11,0x6cc(9); addi 29,9,160; lwz 10,0x6d0(9); addi 30,9,164; oris 11,11,32768; addi 5,9,168; ori 11,11,128; addi 7,9,172; stw 11,0x6cc(9); lwzx 0,6,26; or 10,10,0; stw 10,0x6d0(9); stwx 28,29,4; stwx 28,30,4; stwx 28,5,4; stwx 24,7,4; lwz 9,0x4d8(3); lwz 0,0x6cc(9); addi 29,9,140; lwz 11,0x6d0(9); addi 30,9,144; oris 0,0,32768; addi 5,9,148; ori 0,0,128; add 7,9,4; stw 0,0x6cc(9); addi 10,9,156; lwzx 0,6,26; or 11,11,0; stw 11,0x6d0(9); stwx 8,29,4; stwx 8,30,4; stwx 8,5,4; stb 23,0x98(7); stwx 8,10,4; lwz 9,0x4d8(3); lwz 0,0x6cc(9); addi 29,9,176; lwz 11,0x6d0(9); addi 30,9,180; oris 0,0,32768; addi 5,9,184; ori 0,0,128; add 7,9,4; stw 0,0x6cc(9); addi 10,9,192; lwzx 0,6,26; or 11,11,0; stw 11,0x6d0(9); stwx 8,29,4; stwx 8,30,4; stwx 8,5,4; stb 23,0xbc(7); stwx 8,10,4; lwz 9,0x4d8(3); lwz 0,0x6cc(9); addi 7,9,196; lwz 11,0x6d0(9); addi 10,9,200; oris 0,0,32768; ori 0,0,128; oris 11,11,1; stw 0,0x6cc(9); stw 11,0x6d0(9); stwx 8,7,4; stwx 8,10,4; lmw 23,0xc(1); addi 1,1,48"

struct ENgcRenderer {
    void SetupTEVStagePassColor__GXTevStageID();
};

void ENgcRenderer::SetupTEVStagePassColor__GXTevStageID() {
}
