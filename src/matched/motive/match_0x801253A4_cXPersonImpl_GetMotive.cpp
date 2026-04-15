// cXPersonImpl::GetMotive(int) at 0x801253A4 (16B)

class cXPersonImpl {
    char pad[168];
    float m_motives[1];
public:
    float GetMotive(int idx);
};

float cXPersonImpl::GetMotive(int idx) {
    return m_motives[idx];
}
