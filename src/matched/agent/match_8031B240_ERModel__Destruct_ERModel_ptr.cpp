struct ERModel {
    ~ERModel();
    static void Destruct(ERModel* obj);
};

void ERModel::Destruct(ERModel* obj) {
    obj->~ERModel();
}
