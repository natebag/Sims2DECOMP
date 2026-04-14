/* srand at 0x802432A4 (12B) */

struct RandState {
    char pad[88];
    unsigned int seed;
};

extern RandState* s_pRandState;

void srand(unsigned int seed) {
    s_pRandState->seed = seed;
}
