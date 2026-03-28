class EStorable {
public:
    EStorable* CreateCopy(void) const;
};

extern EStorable* EStorable__CreateCopy(const EStorable* obj);

class EFontSize : public EStorable {
public:
    EFontSize* CreateCopy(void) const;
};

EFontSize* EFontSize::CreateCopy(void) const
{
    return (EFontSize*)EStorable__CreateCopy(this);
}
