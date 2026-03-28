/* Behavior::GetGlobNamespaceID(void) at 0x800AB558 (8B) */

extern int g_globNamespaceID;

struct Behavior {
    int GetGlobNamespaceID(void);
};

int Behavior::GetGlobNamespaceID(void) {
    return g_globNamespaceID;
}
