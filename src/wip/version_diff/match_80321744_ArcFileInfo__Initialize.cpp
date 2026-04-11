/* 0x80321744 (28 bytes) - ArcFileInfo::Initialize(char *, char *) */
class ArcFileInfo {
public:
    char *m_src;
    char *m_dst;
    int m_f8, m_fC, m_f10;
    void Initialize(char *src, char *dst);
};
void ArcFileInfo::Initialize(char *src, char *dst) {
    m_src = src;
    m_f10 = 0;
    m_dst = dst;
    m_fC = 0;
    m_f8 = 0;
}
