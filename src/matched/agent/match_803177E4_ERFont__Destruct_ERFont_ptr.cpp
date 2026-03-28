struct ERFont {
    ~ERFont();
    static void Destruct(ERFont* obj);
};

void ERFont::Destruct(ERFont* obj) {
    obj->~ERFont();
}
