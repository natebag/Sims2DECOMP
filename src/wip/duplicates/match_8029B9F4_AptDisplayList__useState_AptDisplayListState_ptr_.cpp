struct AptDisplayListState;

struct AptDisplayList {
    AptDisplayListState* m_state;

    void useState(AptDisplayListState* state);
};

void AptDisplayList::useState(AptDisplayListState* state) {
    m_state = state;
}
