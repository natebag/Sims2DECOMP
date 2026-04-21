// 0x803B0EEC CasEventResetSimDraw::Log (64 bytes)
// DOL: prologue; lwz r0,8(r3); li r4,0; cmpwi r0,0; beq +8; li r4,1;
//       lis/addi r3,fmt; crclr; bl printf; epilogue.
// Pattern: print (m_field8 != 0 ? 1 : 0)

extern char gCasEventResetSimDrawLogFormat[256];

extern "C" void CasEventDummyPrintf(const char* fmt, ...);

struct CasEventResetSimDraw {
    char pad[8];
    int m_field8;
};

extern "C" void CasEventResetSimDraw_Log(CasEventResetSimDraw* this_) {
    int v = 0;
    if (this_->m_field8 != 0) v = 1;
    CasEventDummyPrintf(gCasEventResetSimDrawLogFormat, v);
}
