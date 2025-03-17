#ifndef _CAML_SDL_RENDERER_
#define _CAML_SDL_RENDERER_

#include <SDL3/SDL_render.h>

/* SDL_Renderer val */
static value Val_SDL_Renderer(SDL_Renderer * p)
{
    return caml_copy_nativeint((intnat) p);
}

static SDL_Renderer * SDL_Renderer_val(value v)
{
    return (SDL_Renderer *) Nativeint_val(v);
}



/* SDL_Texture val */
static value Val_SDL_Texture(SDL_Texture * p)
{
    return caml_copy_nativeint((intnat) p);
}

static SDL_Texture * SDL_Texture_val(value v)
{
    return (SDL_Texture *) Nativeint_val(v);
}



/* SDL_TextureAccess val */
value Val_Sdl_textureaccess_t(int texture_access);

extern const int caml_sdl_textureaccess_table[];
#define Sdl_textureaccess_t(v) \
    caml_sdl_textureaccess_table[Int_val(v)]

#endif /* _CAML_SDL_RENDERER_ */
