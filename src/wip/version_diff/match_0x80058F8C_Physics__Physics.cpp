struct EVec3 {
    float x, y, z;
};

struct Physics {
    EVec3 m_vec0;
    EVec3 m_vec1;
    EVec3 m_vec2;
    float m_field24;
    float m_field28;
    float m_field2C;

    Physics();
};

Physics::Physics() {
    m_vec0.z = 0.0f;
    m_vec0.y = 0.0f;
    m_vec0.x = 0.0f;
    m_vec1.y = 0.0f;
    m_vec1.z = 0.0f;
    m_vec1.x = 0.0f;
    m_vec2.y = 0.0f;
    m_vec2.z = 0.0f;
    m_field2C = 0.0f;
    m_vec2.x = 0.0f;
    m_field24 = 0.0f;
    m_field28 = 0.0f;
}
