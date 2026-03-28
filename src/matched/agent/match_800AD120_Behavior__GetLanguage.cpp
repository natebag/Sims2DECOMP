// 0x800AD120 (8 bytes)
class Behavior {
public:
    char pad[8];
    int m_language;

    int GetLanguage(void);
};

int Behavior::GetLanguage(void) {
    return m_language;
}
