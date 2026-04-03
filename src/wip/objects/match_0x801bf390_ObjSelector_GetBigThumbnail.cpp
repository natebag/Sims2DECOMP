// ObjSelector::GetBigThumbnail(ERShader **) (196 bytes)
// Get the big thumbnail shader, falling back to normal thumbnail if needed

class ERShader;
class EResourceManager;

class ObjSelector {
    int m_cachedBigThumb;   // offset 148
    int m_cachedThumb;      // offset 144

public:
    int GetGUID() const;
    int GetThumbnail(ERShader **ppShader);
};

extern int GetNpcShaderId(int guid, bool forBig);
extern EResourceManager *g_EResourceManager;

int ObjSelector::GetBigThumbnail(ERShader **ppShader) {
    int guid = GetGUID();
    int shaderId = GetNpcShaderId(guid, true);

    if (shaderId == 0) {
        // Fallback to normal thumbnail
        return GetThumbnail(ppShader);
    }

    // Load big thumbnail shader resource
    // Loop through shader variants (up to 2)
    for (int i = 0; i <= 1; i++) {
        ERShader *shader = g_EResourceManager->AddRef(shaderId, 0, 0);
        *ppShader = shader;

        if (shader != 0) {
            // Found valid shader
            return 1;
        }
    }

    return 0;
}
