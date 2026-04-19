// 0x801C7938 (32B) MMUTarget::OnTopLevelChoiceChange(void)
// Thunk to MMUTarget::UpdateText(void)

class MMUTarget {
public:
    void OnTopLevelChoiceChange(void);
    void UpdateText(void);
};

void MMUTarget::OnTopLevelChoiceChange(void) {
    UpdateText();
}
