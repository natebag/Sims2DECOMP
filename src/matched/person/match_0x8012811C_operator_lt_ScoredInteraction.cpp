// 0x8012811C operator<(ScoredInteraction&, ScoredInteraction&) (24B)

struct ScoredInteraction_OL {
    char p[8];
    float score;
};

int operator<(ScoredInteraction_OL& a, ScoredInteraction_OL& b) {
    return a.score > b.score;
}
