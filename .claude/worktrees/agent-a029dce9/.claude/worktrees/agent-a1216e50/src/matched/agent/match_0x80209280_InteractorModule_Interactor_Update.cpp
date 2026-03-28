struct EVec3 { float x, y, z; };

struct Interactor {
    char pad[0x08];
    EVec3 m_prevPos;
    EVec3 m_curPos;

    void Update(float dt);
};

void Interactor::Update(float dt) {
    m_curPos = m_prevPos;
}
