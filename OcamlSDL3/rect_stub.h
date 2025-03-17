#ifndef _CAML_SDL_RECT_
#define _CAML_SDL_RECT_

#include <SDL3/SDL_rect.h>

#define SDL_Rect_val(r, v) \
    (r)->x = Int_val(Field(v, 0)); \
    (r)->y = Int_val(Field(v, 1)); \
    (r)->w = Int_val(Field(v, 2)); \
    (r)->h = Int_val(Field(v, 3))

#define Val_SDL_Rect(ret, r) \
    ret = caml_alloc(4, 0); \
    Store_field(ret, 0, Val_int((r)->x)); \
    Store_field(ret, 1, Val_int((r)->y)); \
    Store_field(ret, 2, Val_int((r)->w)); \
    Store_field(ret, 3, Val_int((r)->h))

#define SDL_Point_val(p, v) \
    (p)->x = Int_val(Field(v, 0)); \
    (p)->y = Int_val(Field(v, 1));

#define Val_SDL_Point(ret, p) \
    ret = caml_alloc(2, 0); \
    Store_field(ret, 0, Val_int((p)->x)); \
    Store_field(ret, 1, Val_int((p)->y));

#endif /* _CAML_SDL_RECT_ */
