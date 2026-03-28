/* Globs::Globs(void) at 0x800B81BC (12B) */

struct Globs;
extern Globs* g_globs;

struct Globs {
    Globs(void);
};

Globs::Globs(void) {
    g_globs = this;
}
