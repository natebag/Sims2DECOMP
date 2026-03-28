static int s_nullString;

struct EString_STN {
    int* m_data;
    void SetToNull();
};

void EString_STN::SetToNull() {
    m_data = &s_nullString;
}
