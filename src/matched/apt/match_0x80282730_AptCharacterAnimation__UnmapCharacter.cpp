// 0x80282730 (68B) AptCharacterAnimation::UnmapCharacter(AptCharacter*)

struct AptCharacter;

struct AptCharacterAnimation {
    char pad[0x0C];
    int m_count;
    AptCharacter** m_array;

    int UnmapCharacter(AptCharacter* target);
};

int AptCharacterAnimation::UnmapCharacter(AptCharacter* target) {
    for (int i = 0; i < m_count; i++) {
        if (m_array[i] == target) {
            return i;
        }
    }
    return -1;
}
