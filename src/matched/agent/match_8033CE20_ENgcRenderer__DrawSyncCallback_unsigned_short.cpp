static unsigned short s_drawSyncToken;
class ENgcRenderer { public: static void DrawSyncCallback(unsigned short); };
void ENgcRenderer::DrawSyncCallback(unsigned short val) { s_drawSyncToken = val; }
