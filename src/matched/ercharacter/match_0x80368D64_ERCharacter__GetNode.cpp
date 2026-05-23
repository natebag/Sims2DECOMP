struct ERCharacter {
    char _p[0x14];
    char *m_nodes;
    void *GetNode(int i);
};
void *ERCharacter::GetNode(int i) { return m_nodes + i * 0xb8; }
