struct ERFlash {
    ~ERFlash();
    static void Destruct(ERFlash* obj);
};

void ERFlash::Destruct(ERFlash* obj) {
    obj->~ERFlash();
}
