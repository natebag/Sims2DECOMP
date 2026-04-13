// 0x8031B1EC ERModel::New (40b)
struct ERModel {
    char _pad[384];
    static void *operator new(unsigned int);
    ERModel(void);
};

ERModel *ERModel__New(void) {
    ERModel *p = new ERModel;
    return p;
}
