(* Substring -- SML Basis Library *)

type substring

val substring : string * int * int -> substring
val extract   : string * int * int option -> substring
val all       : string -> substring
val string    : substring -> string
val base      : substring -> (string * int * int)

val isEmpty   : substring -> bool
val getc      : substring -> (char * substring) option
val first     : substring -> char option
val triml     : int -> substring -> substring
val trimr     : int -> substring -> substring
val sub       : substring * int -> char
val size      : substring -> int
val slice     : substring * int * int option -> substring
val concat    : substring list -> string
val explode   : substring -> char list
val isPrefix  : string -> substring -> bool
val compare   : substring * substring -> order
val collate   : (char * char -> order) -> substring * substring -> order

val dropl     : (char -> bool) -> substring -> substring
val dropr     : (char -> bool) -> substring -> substring
val takel     : (char -> bool) -> substring -> substring
val taker     : (char -> bool) -> substring -> substring
val splitl    : (char -> bool) -> substring -> substring * substring
val splitr    : (char -> bool) -> substring -> substring * substring
val splitAt   : substring * int -> substring * substring

val position  : string -> substring -> substring * substring

exception Span
val span      : substring * substring -> substring

val translate : (char -> string) -> substring -> string

val tokens    : (char -> bool) -> substring -> substring list
val fields    : (char -> bool) -> substring -> substring list

val foldl     : (char * 'a -> 'a) -> 'a -> substring -> 'a
val foldr     : (char * 'a -> 'a) -> 'a -> substring -> 'a
val app       : (char -> unit) -> substring -> unit

(* 
   [substring] is the type of substrings of a basestring, an efficient 
   representation of a piece of a string.
   A substring (s,i,n) is valid if 0 <= i <= i+n <= size s, 
                  or equivalently, 0 <= i and 0 <= n and i+n <= size s.  
   A valid substring (s, i, n) represents the string s[i...i+n-1].  
   Invariant in the implementation: Any value of type substring is valid.

   [substring(s, i, n)] creates the substring (s, i, n), consisting of
   the substring of s with length n starting at i.  Raises Subscript
   if i<0 or n<0 or i+n > size s.  Equivalent to extract(s, i, SOME n).

   [extract(s, i, NONE)] creates the substring (s, i, size s-i)
   consisting of the tail of s starting at i.  
   Raises Subscript if i<0 or i > size s.

   [extract(s, i, SOME n)] creates the substring (s, i, n),
   consisting of the substring of s with length n starting at i.
   Raises Subscript if i<0 or n<0 or i+n > size s.

   [all s] is the substring (s, 0, size s).

   [string sus] is the string s[i..i+n-1] represented by sus = (s, i, n).

   [base sus] is the concrete triple (s, i, n), where sus = (s, i, n).

   [isEmpty (s, i, n)] true if the substring is empty (that is, n = 0).

   [getc sus] returns SOME(c, rst) where c is the first character and
   rst the remainder of sus, if sus is non-empty; otherwise returns
   NONE.  Note that 
        #1 o valOf o scanFn Substring.getc
   is equivalent to, but more efficient than, 
        valOf o StringCvt.scanString scanFn o Substring.string

   [first sus] returns SOME c where c is the first character in sus,
   if sus is non-empty; otherwise returns NONE.

   [triml k sus] returns sus less its leftmost k characters; or the
   empty string at the end of sus if it has less than k characters.
   Raises Subscript if k < 0, even in the partial application triml(k). 

   [trimr k sus] returns sus less its rightmost k characters; or the
   empty string at the beginning of sus if it has less than k characters.  
   Raises Subscript if k < 0, even in the partial application triml(k).

   [sub (sus, k)] returns the k'th character of the substring; that is,
   s(i+k) where sus = (s, i, n).  Raises Subscript if k<0 or k>=n.

   [size (s, i, n)] returns the size of the substring, that is, n.

   [slice (sus, i', NONE)] returns the substring (s, i+i', n-i'), where
   sus = (s, i, n).  Raises Subscript if i' < 0 or i' > n.

   [slice (sus, i', SOME n')] returns the substring (s, i+i', n'), where
   sus = (s, i, n).  Raises Subscript if i' < 0 or n' < 0 or i'+n' >= n.

   [concat suss] returns a string consisting of the concatenation of
   the substrings.  Equivalent to String.concat (List.map string suss).

   [explode sus] returns the list of characters of sus, that is,
        [s(i), s(i+1), ..., s(i+n-1)]
   where sus = (s, i, n).  Equivalent to String.explode(string ss).

   [isPrefix s1 s2] is true if s1 is a prefix of s2. That is, if there 
   exists a string t such that string s1 ^ t = string s2.

   [compare (sus1, sus2)] performs lexicographic comparison, using the
   standard ordering Char.compare on the characters.  Returns LESS,
   EQUAL, or GREATER, according as sus1 is less than, equal to, or
   greater than sus2.  Equivalent to, but more efficient than,
       String.compare(string sus1, string sus2).

   [collate cmp (sus1, sus2)] performs lexicographic comparison, using the 
   given ordering cmp on characters.  Equivalent to, but more efficient 
   than, String.collate cmp (string sus1, string sus2).

   [dropl p sus] drops the longest prefix (left substring) of sus all
   of whose characters satisfy predicate p.  If all characters do, it
   returns the empty substring (s, i+n, 0) where sus = (s, i, n).

   [dropr p sus] drops the longest suffix (right substring) of sus all
   of whose characters satisfy predicate p.  If all characters do, it
   returns the empty substring (s, i, 0) where sus = (s, i, n).

   [takel p sus] returns the longest prefix (left substring) of sus
   all of whose characters satisfy predicate p.  That is, if the
   left-most character does not satisfy p, returns the empty (s, i, 0)
   where sus = (s, i, n).

   [taker p sus] returns the longest suffix (right substring) of sus
   all of whose characters satisfy predicate p.  That is, if the
   right-most character satisfies p, returns the empty (s, i+n, 0)
   where sus = (s, i, n).

   Let p be a predicate and xxxxfyyyyfzzzz a string where all
   characters in xxxx and zzzz satisfy p, and f a is character
   not satisfying p.  Then

                sus = xxxxfyyyyfzzzz         sus = xxxxzzzz
        ------------------------------------------------------
        dropl p sus =     fyyyyfzzzz               
        dropr p sus = xxxxfyyyyf       
        takel p sus = xxxx                         xxxxzzzz
        taker p sus =           zzzz               xxxxzzzz

   It also holds that 
        concat[takel p sus, dropl p sus] = string sus
        concat[dropr p sus, taker p sus] = string sus 

   [splitl p sus] splits sus into a pair (sus1, sus2) of substrings
   where sus1 is the longest prefix (left substring) all of whose
   characters satisfy p, and sus2 is the rest.  That is, sus2 begins
   with the leftmost character not satisfying p.  Disregarding
   sideeffects, we have: 
        splitl p sus = (takel p sus, dropl p sus).

   [splitr p sus] splits sus into a pair (sus1, sus2) of substrings
   where sus2 is the longest suffix (right substring) all of whose
   characters satisfy p, and sus1 is the rest.  That is, sus1 ends
   with the rightmost character not satisfying p.  Disregarding
   sideeffects, we have:
        splitr p sus = (dropr p sus, taker p sus)

   [splitAt (sus, k)] returns the pair (sus1, sus2) of substrings,
   where sus1 contains the first k characters of sus, and sus2
   contains the rest.  Raises Subscript if k < 0 or k > size sus.

   [position s (s',i,n)] splits the substring into a pair (pref, suff)
   of substrings, where suff is the longest suffix of (s', i, n) which
   has s as a prefix.  More precisely, let m = size s.  If there is a
   least index k in i..i+n-m for which s = s'[k..k+m-1], 
   then the result is       pref = (s', i, k-i) and suff = (s', k, n-(k-i)); 
   otherwise the result is  pref = (s', i, n)   and suff = (s', i+n, 0).

   [span (sus1, sus2)] returns a substring spanning from the start of
   sus1 to the end of sus2, provided this is well-defined: sus1 and
   sus2 must have the same underlying string, and the start of sus1
   must not be to the right of the end of sus2; otherwise raises Span.

   More precisely, if base(sus1) = (s,i,n) and base(sus2) = (s',i',n') 
   and s = s' and i <= i'+n', then base(join(sus1, sus2)) = (s, i, i'+n'-i).
   This may be used to compute `span', `union', and `intersection'.

   [translate f sus] applies f to every character of sus, from left to
   right, and returns the concatenation of the results.  Raises Size
   if the sum of their sizes is greater than String.maxSize.
   Equivalent to String.concat(List.map f (explode sus)).

   [tokens p sus] returns the list of tokens in sus, from left to right, 
   where a token is a non-empty maximal substring of sus not containing 
   any delimiter, and a delimiter is a character satisfying p.

   [fields p sus] returns the list of fields in sus, from left to right, 
   where a field is a (possibly empty) maximal substring of sus not 
   containing any delimiter, and a delimiter is a character satisfying p.

   Two tokens may be separated by more than one delimiter, whereas two
   fields are separated by exactly one delimiter.  If the only delimiter 
   is the character #"|", then
        "abc||def" contains two tokens:   "abc" and "def"
        "abc||def" contains three fields: "abc" and "" and "def"

   [foldl f e sus] folds f over sus from left to right.  That is, 
   evaluates f(s[i+n-1], f( ... f(s[i+1], f(s[i] % e)) ...)) 
   tail-recursively, where sus = (s, i, n).  
   Equivalent to List.foldl f e (explode sus).

   [foldr f e sus] folds f over sus from right to left.  That is, 
   evaluates f(s[i], f(s[i+1], f(... f(s[i+n-1] % e) ...)))
   tail-recursively, where sus = (s, i, n).
   Equivalent to List.foldr f e (explode sus).

   [app f sus] applies f to all characters of sus, from left to right.
   Equivalent to List.app f (explode sus).

*)
