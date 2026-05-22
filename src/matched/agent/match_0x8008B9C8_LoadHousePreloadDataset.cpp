// 0x8008B9C8 LoadHousePreloadDataset(char*) (84B)

extern char g_house_fmt[16];  // at 0x803D7D2C "housepre%02d%s"
extern int g_house_num[16];   // at 0x80476230 — forces lis+lwz
// AddRefAsync is a member function: receiver is g_ds_mgr at 0x804A5FD8
class EDatasetManager;
extern EDatasetManager g_ds_mgr;

extern "C" int Sprintf(char* buf, char* fmt, ...);

class EDatasetManager {
public:
    void AddRefAsync(char* name);
};

class EResourceManager {
public:
    static int CalcId(char* name);
};

int LoadHousePreloadDataset(char* arg) {
    char buf[64];
    Sprintf(buf, g_house_fmt, g_house_num[0], arg);
    g_ds_mgr.AddRefAsync(buf);
    return EResourceManager::CalcId(buf);
}
