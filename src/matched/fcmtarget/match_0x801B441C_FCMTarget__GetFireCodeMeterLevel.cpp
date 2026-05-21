// 0x801B441C (60B) FCMTarget::GetFireCodeMeterLevel(void)

extern float FCM_levelMult[3];  // 0x803F0968
extern "C" float helper_GetFireCodeValue(bool b);  // 0x800427A8

class FCMTarget {
public:
    int GetFireCodeMeterLevel();
};

int FCMTarget::GetFireCodeMeterLevel() {
    return (int)(helper_GetFireCodeValue(false) * FCM_levelMult[0]);
}
