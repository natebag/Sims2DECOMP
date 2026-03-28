struct EFontSize {
    ~EFontSize(void);
    static void Destruct(EFontSize* obj);
};

void EFontSize::Destruct(EFontSize* obj)
{
    obj->~EFontSize();
}
