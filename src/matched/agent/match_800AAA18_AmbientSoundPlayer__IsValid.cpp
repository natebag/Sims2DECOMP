// FLAGS: -fno-elide-constructors
struct ASP { int m_f0; int m_f4; int IsValid(); };
int ASP::IsValid() {
    int r = 0;
    if (m_f0) {
        if (m_f4) r = 1;
    }
    return r;
}
