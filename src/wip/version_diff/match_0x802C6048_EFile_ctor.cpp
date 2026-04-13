// MATCH: 0x802C6048 EFile::EFile (68 bytes)
// Has SDA globals - uses r13-relative addressing
// FLAGS: -fno-elide-constructors

struct EFile {
    int field_0;
    int field_4;
    int field_8;
    int field_c;
    int field_10;
    int field_14;
    int field_18;
    int field_1c;
    int field_20;
    int field_24;
    int field_28;
};

// SDA globals
extern char gFileHeap[4];
extern char gFileHeapInit[4];

extern "C" void EFile_ctor(EFile* this_) {
    this_->field_0 = 0;
    this_->field_4 = 0;
    this_->field_8 = -1;  // 0x80000000 >> 1
    this_->field_c = -1;
    this_->field_10 = 0;
    this_->field_14 = 0;
    this_->field_18 = 0;
    this_->field_1c = 0;
    this_->field_20 = 0;
    this_->field_24 = 0;
    this_->field_28 = (int)gFileHeap;
}
