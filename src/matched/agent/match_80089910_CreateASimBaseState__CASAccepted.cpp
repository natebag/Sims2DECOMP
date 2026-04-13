// FLAGS: -fno-elide-constructors
struct S { char pad[32]; int m_r; char pad2[4]; int m_a; int F(); };
int S::F() {
    int result = 0;
    if (!m_r) {
        if (m_a) result = 1;
    }
    return result;
}
