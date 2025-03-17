external set_clipboard_text : text:string -> int = "caml_SDL_SetClipboardText"
external get_clipboard_text : unit -> string = "caml_SDL_GetClipboardText"
external has_clipboard_text : unit -> bool = "caml_SDL_HasClipboardText"
