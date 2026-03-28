struct PersonalityData;

class cXPersonImpl {
public:
    char m_pad[168];
    PersonalityData* GetPersonality();
};

PersonalityData* cXPersonImpl::GetPersonality() {
    return (PersonalityData*)((char*)this + 168);
}
