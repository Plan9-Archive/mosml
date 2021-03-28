(* Auxiliaries for the lexical analyzer *)

local
  open Fnlib Lexing;
in

val brace_depth = ref 0;
val comment_depth = ref 0;

exception Lexical_error of string;

val initial_string_buffer = CharArray.array(256, #" ");
val string_buff = ref initial_string_buffer;
val string_index = ref 0;

fun reset_string_buffer () =
(
  string_buff := initial_string_buffer;
  string_index := 0
);

fun store_string_char c =
  let open CharArray
      val len = length (!string_buff)
  in
    if !string_index >= len then
      let val new_buff = array(len * 2, #" ") in
        copy { src= !string_buff, si=0, len = NONE, dst= new_buff, di=0 };
        string_buff := new_buff
      end
    else ();
    update(!string_buff, !string_index, c);
    incr string_index
  end
;

fun get_stored_string () =
  let val s = CharArray.extract(!string_buff, 0, SOME (!string_index)) in
    string_buff := initial_string_buffer;
    s
  end
;

val char_for_backslash = fn
    #"n" => #"\010" (* #"\n" *)
  | #"t" => #"\009" (* #"\t" *)
  | #"b" => #"\008" (* #"\b" *)
  | #"r" => #"\013" (* #"\r" *)
  | c   => c
;

fun char_for_decimal_code lexbuf i =
  Char.chr(100 * (Char.ord(getLexemeChar lexbuf i) - 48) +
            10 * (Char.ord(getLexemeChar lexbuf (i+1)) - 48) +
                 (Char.ord(getLexemeChar lexbuf (i+2)) - 48))
;

end;
