static int s_nullString2;

struct EString2_STN {
    int* m_data;
    void SetToNull();
};

void EString2_STN::SetToNull() {
    m_data = &s_nullString2;
}
