// 0x802B4CA8 AptValue::isMovieClip (32b)

struct AptValue {
    unsigned int m_data;
};

int AptValue__isMovieClip(AptValue *self) {
    unsigned int val = self->m_data;
    int result = 0;
    if ((val & 0x7F) == 30) {
        result = (val >> 27) & 1;
    }
    return result;
}
