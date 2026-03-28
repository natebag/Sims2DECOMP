struct Inner {
    int m_first;
};

class Outer {
public:
    int m_pad;
    Inner* m_inner;
    int GetNestedValue();
};

int Outer::GetNestedValue() {
    return m_inner->m_first;
}
