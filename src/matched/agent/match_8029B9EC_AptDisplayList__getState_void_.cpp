struct AptDisplayListState;

struct AptDisplayList {
    AptDisplayListState* m_state;

    AptDisplayListState* getState();
};

AptDisplayListState* AptDisplayList::getState() {
    return m_state;
}
