
module Rect = struct
  type t =
    { x : int
    ; y : int
    ; w : int
    ; h : int }

  let make ~x ~y ~w ~h = { x; y; w; h }
end


module Point = struct
  type t =
    { x : int
    ; y : int
    }
end

external has_intersection : a:Rect.t -> b:Rect.t -> bool = "caml_SDL_HasIntersection"

external intersect_rect_and_line
  :  rect:Rect.t
  -> x1:int
  -> y1:int
  -> x2:int
  -> y2:int
  -> (int * int * int * int) option
  = "caml_SDL_IntersectRectAndLine"

external point_in_rect : p:Point.t -> r:Rect.t -> bool = "caml_SDL_PointInRect"
