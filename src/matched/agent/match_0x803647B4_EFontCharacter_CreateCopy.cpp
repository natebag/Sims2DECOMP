class EStorable {
public:
    EStorable* CreateCopy(void) const;
};

extern EStorable* EStorable__CreateCopy(const EStorable* obj);

class EFontCharacter : public EStorable {
public:
    EFontCharacter* CreateCopy(void) const;
};

EFontCharacter* EFontCharacter::CreateCopy(void) const
{
    return (EFontCharacter*)EStorable__CreateCopy(this);
}
