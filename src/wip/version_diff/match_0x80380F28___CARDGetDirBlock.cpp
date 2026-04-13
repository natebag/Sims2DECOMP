struct CARDControl {
    char _p[0x84];
    int m_dirBlock;
};
int *__CARDGetDirBlock(CARDControl *ctrl);
int *__CARDGetDirBlock(CARDControl *ctrl) { return (int*)ctrl->m_dirBlock; }
