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

#include <SDL3/SDL_clipboard.h>

CAMLprim value
caml_SDL_SetClipboardText(value text)
{
    CAMLparam1(text);
    int r = SDL_SetClipboardText(String_val(text));
    CAMLreturn(Val_int(r));
}

CAMLprim value
caml_SDL_GetClipboardText(value unit)
{
    CAMLparam0();
    char * txt = SDL_GetClipboardText();
    CAMLreturn(caml_copy_string(txt));
}

CAMLprim value
caml_SDL_HasClipboardText(value unit)
{
    CAMLparam0();
    bool b = SDL_HasClipboardText();
    CAMLreturn(Val_bool(b));
}

/* vim: set ts=4 sw=4 et: */
