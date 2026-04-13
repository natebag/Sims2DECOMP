struct CARDControl {
    char _p[0x88];
    int m_fatBlock;
};
int *__CARDGetFatBlock(CARDControl *ctrl);
int *__CARDGetFatBlock(CARDControl *ctrl) { return (int*)ctrl->m_fatBlock; }
