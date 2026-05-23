/* REffectsAttachment::Destruct at 0x80322A54 (36 bytes) */

void REffectsAttachment_dtor(void* self, int mode);

void REffectsAttachment_Destruct(void* self)
{
    REffectsAttachment_dtor(self, 2);
}
