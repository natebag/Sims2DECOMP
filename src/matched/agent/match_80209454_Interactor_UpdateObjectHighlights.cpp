void UpdateObjHighlightsImpl(void *objMan, int playerId);

struct Interactor_UOH {
    int m_playerId;

    void UpdateObjectHighlights(void *objMan);
};

void Interactor_UOH::UpdateObjectHighlights(void *objMan) {
    UpdateObjHighlightsImpl(objMan, m_playerId);
}
