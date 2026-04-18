// 0x8034FE10 (24B) ENgcTextureBase::Lock(void)

struct ENgcTB_L {
    char pad[0x44];
    int m_44;
    int Lock();
};

int ENgcTB_L::Lock() {
    m_44++;
    return 1;
}
