// BString — stub implementations from symbol map
// Auto-generated. 93 functions.

// 0x8011BF04 [96b]
void BString::delete_ref(void) { }

// 0x8011BF64 [12b]
int BString::ref_count(void) const { }

// 0x8011BF70 [68b]
int BString::data(void) const { }

// 0x8011FE9C [12b]
int BString::length(void) const { }

// 0x8011BFB4 [12b]
int BString::point(void) { }

// 0x8011BFC0 [12b]
int BString::len(void) { }

// 0x8011BFCC [76b]
void BString::get_at(unsigned int) const { }

// 0x8011C018 [76b]
int BString::operator[](unsigned int) const { }

// 0x8011F768 [132b]
void BString::compare(BString &, unsigned int, unsigned int) const { }

// 0x8011F84C [104b]
void BString::compare(char *, unsigned int) const { }

// 0x8011F8B4 [252b]
void BString::compare(char, unsigned int, unsigned int) const { }

// 0x8011CA28 [8b]
void BString::eos(void) { }

// 0x8011CA30 [216b]
void BString::assign_str(char *, unsigned int) { }

// 0x8011FEA8 [12b]
void BString::reserve(void) const { }

// 0x8011CB08 [304b]
void BString::append_str(char *, unsigned int) { }

// 0x8011CC38 [484b]
void BString::insert_str(unsigned int, char *, unsigned int) { }

// 0x8011CE1C [612b]
void BString::replace_str(unsigned int, unsigned int, char *, unsigned int) { }

// 0x8011D080 [184b]
void BString::compare_str(unsigned int, char *, unsigned int, unsigned int) const { }

// 0x8011D138 [256b]
void BString::find_str(char *, unsigned int, unsigned int) const { }

// 0x8011EFE0 [136b]
void BString::find(char, unsigned int) const { }

// 0x8011D238 [288b]
void BString::rfind_str(char *, unsigned int, unsigned int) const { }

// 0x8011F138 [216b]
void BString::rfind(char, unsigned int) const { }

// 0x8011D358 [184b]
void BString::find_first_of_str(char *, unsigned int, unsigned int) const { }

// 0x8011D410 [212b]
void BString::find_last_of_str(char *, unsigned int, unsigned int) const { }

// 0x8011D4E4 [152b]
void BString::find_first_not_of_str(char *, unsigned int, unsigned int) const { }

// 0x8011D57C [204b]
void BString::find_last_not_of_str(char *, unsigned int, unsigned int) const { }

// 0x8011D648 [32b]
BString::BString(void) { }

// 0x8011D668 [84b]
BString::BString(unsigned int, BString::capacity) { }

// 0x8011D6BC [200b]
BString::BString(BString &, unsigned int, unsigned int) { }

// 0x8011D784 [108b]
BString::BString(char *, unsigned int, unsigned int) { }

// 0x8011D7F0 [84b]
BString::BString(char *, unsigned int) { }

// 0x8011D844 [76b]
BString::BString(char *) { }

// 0x8011D890 [84b]
BString::BString(char, unsigned int) { }

// 0x8011D8E4 [64b]
BString::~BString(void) { }

// 0x8011D924 [152b]
BString& BString::operator=(BString &) { }

// 0x8011D9BC [84b]
BString& BString::operator=(char *) { }

// 0x8011DA10 [172b]
BString& BString::operator=(char) { }

// 0x8011DABC [84b]
void BString::operator+=(BString &) { }

// 0x8011DB10 [84b]
void BString::operator+=(char *) { }

// 0x8011DB64 [284b]
void BString::operator+=(char) { }

// 0x8011DC80 [140b]
void BString::append(BString &, unsigned int, unsigned int) { }

// 0x8011DD0C [48b]
void BString::append(char *, unsigned int) { }

// 0x8011DD3C [84b]
void BString::append(char *) { }

// 0x8011DD90 [328b]
void BString::append(char, unsigned int) { }

// 0x8011DED8 [196b]
void BString::assign(BString &, unsigned int, unsigned int) { }

// 0x8011DF9C [48b]
void BString::assign(char *, unsigned int) { }

// 0x8011DFCC [84b]
void BString::assign(char *) { }

// 0x8011E020 [228b]
void BString::assign(char, unsigned int) { }

// 0x8011E104 [140b]
void BString::insert(unsigned int, BString &, unsigned int, unsigned int) { }

// 0x8011E190 [48b]
void BString::insert(unsigned int, char *, unsigned int) { }

// 0x8011E1C0 [92b]
void BString::insert(unsigned int, char *) { }

// 0x8011E21C [532b]
void BString::insert(unsigned int, char, unsigned int) { }

// 0x8011E430 [424b]
void BString::erase(unsigned int, unsigned int) { }

// 0x8011E5D8 [196b]
void BString::replace(unsigned int, unsigned int, BString &, unsigned int, unsigned int) { }

// 0x8011E69C [116b]
void BString::replace(unsigned int, unsigned int, char *, unsigned int) { }

// 0x8011E710 [132b]
void BString::replace(unsigned int, unsigned int, char *) { }

// 0x8011E794 [772b]
void BString::replace(unsigned int, unsigned int, char, unsigned int) { }

// 0x8011EA98 [256b]
void BString::put_at(unsigned int, char) { }

// 0x8011EB98 [176b]
int BString::operator[](unsigned int) { }

// 0x8011EC48 [48b]
void BString::c_str(void) const { }

// 0x8011EC78 [304b]
void BString::resize(unsigned int, char) { }

// 0x8011EDA8 [64b]
void BString::resize(unsigned int) { }

// 0x8011EDE8 [152b]
void BString::reserve(unsigned int) { }

// 0x8011EE80 [144b]
void BString::copy(char *, unsigned int, unsigned int) const { }

// 0x8011EF10 [88b]
void BString::find(BString &, unsigned int) const { }

// 0x8011EF68 [32b]
void BString::find(char *, unsigned int, unsigned int) const { }

// 0x8011EF88 [88b]
void BString::find(char *, unsigned int) const { }

// 0x8011F068 [88b]
void BString::rfind(BString &, unsigned int) const { }

// 0x8011F0C0 [32b]
void BString::rfind(char *, unsigned int, unsigned int) const { }

// 0x8011F0E0 [88b]
void BString::rfind(char *, unsigned int) const { }

// 0x8011F210 [88b]
void BString::find_first_of(BString &, unsigned int) const { }

// 0x8011F268 [32b]
void BString::find_first_of(char *, unsigned int, unsigned int) const { }

// 0x8011F288 [88b]
void BString::find_first_of(char *, unsigned int) const { }

// 0x8011F2E0 [32b]
void BString::find_first_of(char, unsigned int) const { }

// 0x8011F300 [88b]
void BString::find_last_of(BString &, unsigned int) const { }

// 0x8011F358 [32b]
void BString::find_last_of(char *, unsigned int, unsigned int) const { }

// 0x8011F378 [88b]
void BString::find_last_of(char *, unsigned int) const { }

// 0x8011F3D0 [32b]
void BString::find_last_of(char, unsigned int) const { }

// 0x8011F3F0 [88b]
void BString::find_first_not_of(BString &, unsigned int) const { }

// 0x8011F448 [32b]
void BString::find_first_not_of(char *, unsigned int, unsigned int) const { }

// 0x8011F468 [88b]
void BString::find_first_not_of(char *, unsigned int) const { }

// 0x8011F4C0 [120b]
void BString::find_first_not_of(char, unsigned int) const { }

// 0x8011F538 [88b]
void BString::find_last_not_of(BString &, unsigned int) const { }

// 0x8011F590 [32b]
void BString::find_last_not_of(char *, unsigned int, unsigned int) const { }

// 0x8011F5B0 [88b]
void BString::find_last_not_of(char *, unsigned int) const { }

// 0x8011F608 [184b]
void BString::find_last_not_of(char, unsigned int) const { }

// 0x8011F6C0 [168b]
void BString::substr(unsigned int, unsigned int) const { }

// 0x8011F7EC [96b]
void BString::compare(char *, unsigned int, unsigned int) const { }

// 0x8011FE08 [48b]
bool BString::operator==(BString &) const { }

// 0x8011FE38 [56b]
bool BString::operator!=(BString &) const { }

// 0x8011FE70 [44b]
bool BString::operator<(BString &) const { }

// 0x8011FEB4 [124b]
void BString::assignDebug(unsigned wchar_t *) { }

// 0x806FFBC0 [16b]
void BString::defaultReference() { }

