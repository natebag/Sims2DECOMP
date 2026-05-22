// 0x801D6144 PCTTarget::get_motive_rating_value(unsigned int, unsigned wchar_t*) const (104B)

extern int IsSkillCatalogRating(int rating);

class UIObjectBase {
public:
    static void makeNumberString(int n, unsigned short* dst);
};

class PCTTarget {
public:
    char pad_000[204];
    int  m_arr204[1];   // 204 — array of ratings (4-byte stride)
    char pad_CC[8];
    int  m_arr216[1];   // 216 — array of values (4-byte stride)
    int  get_motive_rating_value(unsigned int idx, unsigned short* dst) const;
};

int PCTTarget::get_motive_rating_value(unsigned int idx, unsigned short* dst) const {
    int byte_off = idx * 4;
    int* arr216 = (int*)((char*)this + 216);
    if (*(int*)((char*)arr216 + byte_off) == 0) return 0;
    int* arr204 = (int*)((char*)this + 204);
    int rating = *(int*)((char*)arr204 + byte_off);
    if (IsSkillCatalogRating(rating) != 0) return 0;
    int val = *(int*)((char*)arr216 + byte_off);
    UIObjectBase::makeNumberString(val, dst);
    return 1;
}
