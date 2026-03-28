struct ISimsWallObjectModel {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual ~ISimsWallObjectModel();
    void SafeDelete();
};

void ISimsWallObjectModel::SafeDelete() {
    if (this != 0) {
        delete this;
    }
}
