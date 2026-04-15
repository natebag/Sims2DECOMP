// MotiveInc::DoStream(ReconBuffer *, int) at 0x8011A984 (92B)

class ReconBuffer {
public:
    void ReconInt(int* val, int mode);
    void ReconFloat(float* val, int mode);
};

struct MotiveInc {
    int m_type;      // +0
    float m_amount;  // +4
    float m_rate;    // +8
    void DoStream(ReconBuffer* buf, int mode);
};

void MotiveInc::DoStream(ReconBuffer* buf, int /*mode*/) {
    buf->ReconInt(&m_type, 1);
    buf->ReconFloat(&m_amount, 1);
    buf->ReconFloat(&m_rate, 1);
}
