struct EVec3 {
    float x;
    float y;
    float z;
};

struct Interactor_M {
    char pad[0x08];
    EVec3 m_currentPos;
    EVec3 m_previousPos;

    int Moved();
};

int Interactor_M::Moved() {
    EVec3 *cur = &m_currentPos;
    EVec3 *prev = &m_previousPos;
    int result = 0;
    if (cur->x != prev->x) {
        result = 1;
    } else if (cur->y != prev->y) {
        result = 1;
    } else if (cur->z != prev->z) {
        result = 1;
    }
    return result;
}
