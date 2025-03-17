#ifndef _CAML_SDL_VIDEO_
#define _CAML_SDL_VIDEO_

#include <SDL3/SDL_video.h>

/* SDL_Window */
static value Val_SDL_Window(SDL_Window * p)
{
    return caml_copy_nativeint((intnat) p);
}

static SDL_Window * SDL_Window_val(value v)
{
    return (SDL_Window *) Nativeint_val(v);
}

Uint32 Val_SDL_WindowFlags(value mask_list);



/* SDL_GLContext */
static value Val_SDL_GLContext(SDL_GLContext p)
{
    return caml_copy_nativeint((intnat) p);
}

static SDL_GLContext SDL_GLContext_val(value v)
{
    return (SDL_GLContext) Nativeint_val(v);
}

#endif /* _CAML_SDL_VIDEO_ */

/* vim: set ts=4 sw=4 et: */
