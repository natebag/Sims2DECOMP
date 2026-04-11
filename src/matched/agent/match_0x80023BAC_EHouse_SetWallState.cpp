// EHouse::SetWallState(EWallUpDownStateType)
// Address: 0x80023BAC | Size: 52 bytes

enum EWallUpDownStateType { /* ... */ };

struct EHouse {
    char pad[0x08];
    void* m_wallData;      // at 0x08
    char pad2[0x24 - 0x08 - 4];
    EWallUpDownStateType m_wallState;  // at 0x24
    
    void SetWallState(EWallUpDownStateType state);
};

extern void UpdateWallState(EHouse* house);

void EHouse::SetWallState(EWallUpDownStateType state) {
    m_wallState = state;
    if (m_wallData != 0) {
        UpdateWallState((EHouse*)m_wallData);
    }
}
