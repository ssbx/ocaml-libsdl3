#ifndef _CAML_SDL_RWOPS_
#define _CAML_SDL_RWOPS_

#include <SDL3/SDL_rwops.h>

static value Val_SDL_RWops(SDL_IOStream * p)
{
    return caml_copy_nativeint((intnat) p);
}

static SDL_IOStream * SDL_RWops_val(value v)
{
    return (SDL_IOStream *) Nativeint_val(v);
}

#endif /* _CAML_SDL_RWOPS_ */
