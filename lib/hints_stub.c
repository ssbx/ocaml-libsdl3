/* ocaml-libsdl3 - An OCaml interface to the SDL3 library
 Copyright (C) 2025 Sébastien Serre

 This software is provided "AS-IS", without any express or implied warranty.
 In no event will the authors be held liable for any damages arising from
 the use of this software.

 Permission is granted to anyone to use this software for any purpose,
 including commercial applications, and to alter it and redistribute it freely.
*/
#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/fail.h>

#include <SDL3/SDL.h>
#include <SDL3/SDL_hints.h>

const Uint32 caml_sdl_hintpriority_table[] = {
    SDL_HINT_DEFAULT,
    SDL_HINT_NORMAL,
    SDL_HINT_OVERRIDE
};

value
Val_Sdl_hintpriority_t(int hint_priority)
{
    switch (hint_priority) {
    case SDL_HINT_DEFAULT:    return Val_int(0);
    case SDL_HINT_NORMAL: return Val_int(1);
    case SDL_HINT_OVERRIDE:    return Val_int(2);
    }
    caml_failwith("Sdl_hintprority.t");
}

#define Sdl_hintpriority_t(v) \
    caml_sdl_hintpriority_table[Int_val(v)]

CAMLprim value
caml_SDL_SetHintWithPriority(value hint, value valstr, value priority)
{
    CAMLparam3(hint, valstr, priority);

    int r = SDL_SetHintWithPriority(
                String_val(hint),
                String_val(valstr),
                Sdl_hintpriority_t(priority));
    if (r) caml_failwith("sdlhint.set_with_prio");
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_SetHint(value hint, value valstr)
{
    CAMLparam2(hint, valstr);

    int _was_set = SDL_SetHint(
                    String_val(hint),
                    String_val(valstr));

    /* CAMLreturn(Bool_val(was_set)); */
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_GetHint(value hint)
{
    CAMLparam1(hint);
    CAMLlocal2(val,ret);

    const char *hint_val = SDL_GetHint(String_val(hint));

    if (hint_val) {
        val = caml_copy_string(hint_val);
        ret = caml_alloc_some(val);
    } else {
        ret = Val_none;
    }
    CAMLreturn(ret);
}


