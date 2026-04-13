// FLAGS: -fno-elide-constructors
struct CASBS { char pad[32]; int m_result; char pad2[8]; int m_cancelled; int CASCanceled(); };
int CASBS::CASCanceled() {
    int r = 0;
    if (!m_result) {
        if (m_cancelled) r = 1;
    }
    return r;
}
