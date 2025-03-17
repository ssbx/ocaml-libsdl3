#ifndef _CAML_SDL_PIXEL_
#define _CAML_SDL_PIXEL_

#include <SDL3/SDL_pixels.h>

value Val_Sdl_pixelformat_t(Uint32 pixel_format);

extern const Uint32 caml_sdl_pixelformat_table[];
#define Sdl_pixelformat_t(v) \
    caml_sdl_pixelformat_table[Long_val(v)]

#define SDL_Color_val(c, v) \
    (c)->r = Int_val(Field(v,0)); \
    (c)->g = Int_val(Field(v,1)); \
    (c)->b = Int_val(Field(v,2)); \
    (c)->a = Int_val(Field(v,3))

#define Val_SDL_Color(ret, c) \
    ret = caml_alloc(4, 0); \
    Store_field(ret, 0, Val_int((c)->r)); \
    Store_field(ret, 1, Val_int((c)->g)); \
    Store_field(ret, 2, Val_int((c)->b)); \
    Store_field(ret, 3, Val_int((c)->a))

#endif /* _CAML_SDL_PIXEL_ */
