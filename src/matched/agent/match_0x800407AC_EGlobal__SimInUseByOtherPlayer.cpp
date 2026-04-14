// 0x800407AC EGlobal::SimInUseByOtherPlayer(int, cXPerson*) (48B)
struct cXPerson;

struct EGlobal {
    char pad[188];
    void* m_player1;  // 188
    void* m_player2;  // 192
};

int EGlobal__SimInUseByOtherPlayer(EGlobal* self, int playerIdx, void* person) {
    if (playerIdx == 0) {
        return person == self->m_player2;
    }
    return person == self->m_player1;
}
