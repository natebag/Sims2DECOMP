// 0x801B3024 FAMTarget::GetLotName(int) (80B)

extern char* GetHouseNameText(int idx);

class EGlobal {
public:
    static void HouseNameText(void* dest, char* fmt, ...);
};

extern char g_HouseNameText_globals[1172];

class FAMTarget {
public:
    char* GetLotName(int idx);
};

char* FAMTarget::GetLotName(int idx) {
    char* houseText = GetHouseNameText(idx);
    char* lname;
    EGlobal::HouseNameText(&lname, g_HouseNameText_globals, houseText);
    char* result = 0;
    if (lname != 0) result = *(char**)lname;
    return result;
}
