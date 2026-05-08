/* ActionQueueHUD::SelectAction(signed char) @ 0x80184E50 (60B) */

struct AQH_SA {
    char _pad1[0x150];
    int m_count;
    char _pad2[0x1C5];
    signed char m_selectedAction;
    void SelectAction(signed char action);
    void DeactivateEditActionQueue();
};

void AQH_SA::SelectAction(signed char action) {
    if (action < 0) goto deactivate;
    if (action < m_count) goto store;
deactivate:
    DeactivateEditActionQueue();
    return;
store:
    m_selectedAction = action;
}
