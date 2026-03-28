class EStorable {
public:
    EStorable* CreateCopy(void) const;
};

extern EStorable* EStorable__CreateCopy(const EStorable* obj);

class EFontPage : public EStorable {
public:
    EFontPage* CreateCopy(void) const;
};

EFontPage* EFontPage::CreateCopy(void) const
{
    return (EFontPage*)EStorable__CreateCopy(this);
}
