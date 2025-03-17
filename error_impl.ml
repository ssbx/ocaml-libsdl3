external get_error : unit -> string = "caml_SDL_GetError"
external set_error : string -> unit = "caml_SDL_SetError"
external clear_error : unit -> unit = "caml_SDL_ClearError"
