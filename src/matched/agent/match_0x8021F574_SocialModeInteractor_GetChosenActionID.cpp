// InteractorModule::SocialModeInteractor::GetChosenActionID(void)
// Address: 0x8021F574 | Size: 8 bytes
// Raw: A8 63 00 60 4E 80 00 20
// Disasm: lha r3, 0x60(r3); blr

class SocialModeInteractor {
public:
    char pad[0x60];
    short m_chosenActionID;
    
    short GetChosenActionID();
};

short SocialModeInteractor::GetChosenActionID() {
    return m_chosenActionID;
}
