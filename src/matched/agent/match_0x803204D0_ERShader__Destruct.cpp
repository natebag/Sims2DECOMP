/* ERShader::Destruct at 0x803204D0 (36 bytes) */

void ERShader_dtor(void* self, int mode);

void ERShader_Destruct(void* self)
{
    ERShader_dtor(self, 2);
}
