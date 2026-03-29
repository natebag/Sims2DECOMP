struct EResPrefetchFile {
    char pad[48];
    unsigned int m_030;
    unsigned int m_034;
    unsigned int m_038;
    unsigned int m_03C;
    unsigned int m_040;

    int ValidateStreamPos(void);
};

int EResPrefetchFile::ValidateStreamPos(void)
{
    unsigned int avail = m_040 - m_03C;
    unsigned int used  = m_030 - m_034;
    return (int)(used <= avail);
}
