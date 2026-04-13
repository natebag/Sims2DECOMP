// FLAGS: -fno-elide-constructors
struct GameState { char pad[188]; void* m_player0; void* m_player1; };
extern char g_gameState[];
int GetSimIndex(void* person) {
    GameState* gs = (GameState*)g_gameState;
    if (gs->m_player0 == person) return 0;
    if (gs->m_player1 == person) return 1;
    return -1;
}
