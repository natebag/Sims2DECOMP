// 0x801B5AAC (104B) G2DTarget::PopAptButtonFilters()

extern char g_baseStruct_0x80475DCC[2048];

class AptViewer;

extern "C" void PopAptButtonFilter__10AptViewerFiUi(AptViewer*, int, unsigned int);

class G2DTarget {
public:
    char m_pad[288];
    unsigned int m_120_filters[2];
    void PopAptButtonFilters();
};

void G2DTarget::PopAptButtonFilters() {
    char* base = g_baseStruct_0x80475DCC;
    for (int i = 0; i <= 1; i++) {
        unsigned int f = m_120_filters[i];
        if (f != (unsigned int)-1) {
            AptViewer* viewer = *(AptViewer**)(base + 180);
            PopAptButtonFilter__10AptViewerFiUi(viewer, i, f);
            m_120_filters[i] = (unsigned int)-1;
        }
    }
}
