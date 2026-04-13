// 0x800730F4 SimModel::UsingHighResolutionModel (32B)

extern char g_hiResFlag[];

struct SimModel {
    char pad[0x150];
    int m_hiRes;

    int UsingHighResolutionModel();
};

int SimModel::UsingHighResolutionModel() {
    int r = 0;
    if (*(int*)g_hiResFlag == 0) r = m_hiRes;
    return r;
}
