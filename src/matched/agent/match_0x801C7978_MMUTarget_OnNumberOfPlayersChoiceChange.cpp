// 0x801C7978 (32B) MMUTarget::OnNumberOfPlayersChoiceChange(void)
// Thunk to MMUTarget::UpdateText(void)

class MMUTarget {
public:
    void OnNumberOfPlayersChoiceChange(void);
    void UpdateText(void);
};

void MMUTarget::OnNumberOfPlayersChoiceChange(void) {
    UpdateText();
}
