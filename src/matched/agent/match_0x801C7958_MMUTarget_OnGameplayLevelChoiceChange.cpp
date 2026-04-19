// 0x801C7958 (32B) MMUTarget::OnGameplayLevelChoiceChange(void)
// Thunk to MMUTarget::UpdateText(void)

class MMUTarget {
public:
    void OnGameplayLevelChoiceChange(void);
    void UpdateText(void);
};

void MMUTarget::OnGameplayLevelChoiceChange(void) {
    UpdateText();
}
