// 0x801B33CC FAMTarget::GetLotForFamily(int) (64B)
struct FAMTarget;
struct Family;

extern Family* FAMTarget__GetFamilyInFamilyList(FAMTarget* self, int idx);
extern int FAMTarget__GetLotForFamilyImpl(FAMTarget* self, Family* f);

int FAMTarget__GetLotForFamily(FAMTarget* self, int idx) {
    Family* f = FAMTarget__GetFamilyInFamilyList(self, idx);
    if (f == 0) return 0;
    return FAMTarget__GetLotForFamilyImpl(self, f);
}
