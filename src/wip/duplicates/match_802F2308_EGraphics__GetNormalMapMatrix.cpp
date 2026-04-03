struct EMat4 { float m[16]; };
class EGraphics {
public:
    char m_pad[64];
    EMat4 m_normalMapMatrix;
    EMat4 *GetNormalMapMatrix();
};
EMat4 *EGraphics::GetNormalMapMatrix() { return &m_normalMapMatrix; }
