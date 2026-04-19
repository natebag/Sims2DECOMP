/* LoadingScreenStateMachine_IRL::IsReadyToLoad() at 0x80090BB8 (24B) */

struct LoadingScreenStateMachine_IRL {
    char m_pad[160];
    int m_field;
    int IsReadyToLoad();
};

int LoadingScreenStateMachine_IRL::IsReadyToLoad() {
    if (m_field) return 1;
    return 0;
}
