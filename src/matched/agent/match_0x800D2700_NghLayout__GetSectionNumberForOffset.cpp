// 0x800D2700 NghLayout::GetSectionNumberForOffset(unsigned int) (68B)

struct Section {
    int field_4;
    int field_8;
    int field_C;
};

struct NghLayout {
    Section* sections;
    int GetSectionNumberForOffset(unsigned int offset);
};

int NghLayout::GetSectionNumberForOffset(unsigned int offset) {
    int result = 0;
    Section* s = sections;
    if (s->field_4 <= 0) {
        return 0;
    }
    offset -= s->field_C;
    if ((int)offset < 0) {
        return 0;
    }
    while (true) {
        s++;
        result++;
        if (s->field_4 <= 0) {
            return result;
        }
        offset -= s->field_C;
        if ((int)offset < 0) {
            return result;
        }
    }
}
