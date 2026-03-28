struct EVec3_FD {
    int x;
    int y;
    int z;
};

struct FadeSquare_SD {
    EVec3_FD m_pos;
    char pad_0C[4];
    float m_alpha;
    int m_fade;
    int m_flag;

    void StartDraw(EVec3_FD *pos, int isActive);
};

void FadeSquare_SD::StartDraw(EVec3_FD *pos, int isActive) {
    m_pos = *pos;
    m_alpha = 1.0f;
    m_fade = 0;
    m_flag = isActive;
}
