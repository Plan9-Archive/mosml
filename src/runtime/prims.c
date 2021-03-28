#include "mlvalues.h"
#include "prims.h"
extern value compare();
extern value equal();
extern value notequal();
extern value lessthan();
extern value lessequal();
extern value greaterthan();
extern value greaterequal();
extern value extern_val();
extern value extern_compact_val();
extern value format_float();
extern value float_of_string();
extern value exp_float();
extern value log_float();
extern value sqrt_float();
extern value power_float();
extern value sin_float();
extern value cos_float();
extern value tan_float();
extern value asin_float();
extern value acos_float();
extern value atan_float();
extern value atan2_float();
extern value gc_stat();
extern value gc_get();
extern value gc_set();
extern value gc_minor();
extern value gc_major();
extern value gc_full_major();
extern value hash_univ_param();
extern value intern_val();
extern value int_of_string();
extern value format_int();
extern value open_descriptor();
extern value channel_descriptor();
extern value channel_size();
extern value flush();
extern value output_char();
extern value output_int();
extern value output();
extern value seek_out();
extern value pos_out();
extern value close_out();
extern value input_char();
extern value input_int();
extern value input();
extern value input_nonblocking();
extern value seek_in();
extern value pos_in();
extern value close_in();
extern value input_scan_line();
extern value get_next_char();
extern value start_interp();
extern value realloc_global();
extern value static_alloc();
extern value static_free();
extern value static_resize();
extern value obj_is_block();
extern value obj_block();
extern value available_primitives();
extern value parse_engine();
extern value create_string();
extern value compare_strings();
extern value blit_string();
extern value fill_string();
extern value is_printable();
extern value sys_exit();
extern value sys_open();
extern value sys_close();
extern value sys_remove();
extern value sys_rename();
extern value sys_chdir();
extern value sys_getenv();
extern value sys_system_command();
extern value sys_catch_break();
extern value sml_equal();
extern value sml_not_equal();
extern value sml_system();
extern value sml_abs_int();
extern value sml_floor();
extern value sml_ceil();
extern value sml_round();
extern value sml_trunc();
extern value sml_abs_real();
extern value sml_sqrt();
extern value sml_sin();
extern value sml_cos();
extern value sml_exp();
extern value sml_ln();
extern value sml_int_of_string();
extern value sml_concat();
extern value sml_chr();
extern value sml_ord();
extern value sml_float_of_string();
extern value sml_string_of_int();
extern value sml_string_of_float();
extern value sml_makestring_of_char();
extern value sml_makestring_of_string();
extern value sml_getrealtime();
extern value sml_getrutime();
extern value sml_errno();
extern value sml_getdir();
extern value sml_mkdir();
extern value sml_rmdir();
extern value sml_opendir();
extern value sml_rewinddir();
extern value sml_readdir();
extern value sml_closedir();
extern value sml_isdir();
extern value sml_modtime();
extern value sml_settime();
extern value sml_access();
extern value sml_tmpnam();
extern value sml_errormsg();
extern value sml_asin();
extern value sml_acos();
extern value sml_atan2();
extern value sml_pow();
extern value sml_localtime();
extern value sml_gmtime();
extern value sml_mktime();
extern value sml_asctime();
extern value sml_strftime();
extern value sml_general_string_of_float();
extern value sml_filesize();
extern value sml_int_of_hex();
extern value sml_word_of_hex();
extern value sml_word_of_dec();
extern value sml_hexstring_of_word();
extern value sml_sinh();
extern value sml_cosh();
extern value sml_tanh();
extern value weak_sub();
extern value weak_isdead();
extern value weak_arr();
extern value string_mlval();
extern value mlval_string();
extern value w8vectofloat();
extern value floattow8vec();
extern value w8vectodouble();
extern value doubletow8vec();
extern value sml_localoffset();
extern value sml_exnname();
extern value sml_exnmessage();
extern value sml_realpath();
extern value sml_uname();
extern value sml_islink();
extern value sml_readlink();
extern value sml_devinode();
extern value sml_setdisk();
extern value md5sum();
extern value alloc_valueptr();
extern value sml_init_register();
extern value c_var();
extern value cfun_app1();
extern value cfun_app2();
extern value cfun_app3();
extern value cfun_app4();
extern value cfun_app5();
c_primitive cprim[] = {
  compare,
  equal,
  notequal,
  lessthan,
  lessequal,
  greaterthan,
  greaterequal,
  extern_val,
  extern_compact_val,
  format_float,
  float_of_string,
  exp_float,
  log_float,
  sqrt_float,
  power_float,
  sin_float,
  cos_float,
  tan_float,
  asin_float,
  acos_float,
  atan_float,
  atan2_float,
  gc_stat,
  gc_get,
  gc_set,
  gc_minor,
  gc_major,
  gc_full_major,
  hash_univ_param,
  intern_val,
  int_of_string,
  format_int,
  open_descriptor,
  channel_descriptor,
  channel_size,
  flush,
  output_char,
  output_int,
  output,
  seek_out,
  pos_out,
  close_out,
  input_char,
  input_int,
  input,
  input_nonblocking,
  seek_in,
  pos_in,
  close_in,
  input_scan_line,
  get_next_char,
  start_interp,
  realloc_global,
  static_alloc,
  static_free,
  static_resize,
  obj_is_block,
  obj_block,
  available_primitives,
  parse_engine,
  create_string,
  compare_strings,
  blit_string,
  fill_string,
  is_printable,
  sys_exit,
  sys_open,
  sys_close,
  sys_remove,
  sys_rename,
  sys_chdir,
  sys_getenv,
  sys_system_command,
  sys_catch_break,
  sml_equal,
  sml_not_equal,
  sml_system,
  sml_abs_int,
  sml_floor,
  sml_ceil,
  sml_round,
  sml_trunc,
  sml_abs_real,
  sml_sqrt,
  sml_sin,
  sml_cos,
  sml_exp,
  sml_ln,
  sml_int_of_string,
  sml_concat,
  sml_chr,
  sml_ord,
  sml_float_of_string,
  sml_string_of_int,
  sml_string_of_float,
  sml_makestring_of_char,
  sml_makestring_of_string,
  sml_getrealtime,
  sml_getrutime,
  sml_errno,
  sml_getdir,
  sml_mkdir,
  sml_rmdir,
  sml_opendir,
  sml_rewinddir,
  sml_readdir,
  sml_closedir,
  sml_isdir,
  sml_modtime,
  sml_settime,
  sml_access,
  sml_tmpnam,
  sml_errormsg,
  sml_asin,
  sml_acos,
  sml_atan2,
  sml_pow,
  sml_localtime,
  sml_gmtime,
  sml_mktime,
  sml_asctime,
  sml_strftime,
  sml_general_string_of_float,
  sml_filesize,
  sml_int_of_hex,
  sml_word_of_hex,
  sml_word_of_dec,
  sml_hexstring_of_word,
  sml_sinh,
  sml_cosh,
  sml_tanh,
  weak_sub,
  weak_isdead,
  weak_arr,
  string_mlval,
  mlval_string,
  w8vectofloat,
  floattow8vec,
  w8vectodouble,
  doubletow8vec,
  sml_localoffset,
  sml_exnname,
  sml_exnmessage,
  sml_realpath,
  sml_uname,
  sml_islink,
  sml_readlink,
  sml_devinode,
  sml_setdisk,
  md5sum,
  alloc_valueptr,
  sml_init_register,
  c_var,
  cfun_app1,
  cfun_app2,
  cfun_app3,
  cfun_app4,
  cfun_app5,
  0 };
char * names_of_cprim[] = {
  "compare",
  "equal",
  "notequal",
  "lessthan",
  "lessequal",
  "greaterthan",
  "greaterequal",
  "extern_val",
  "extern_compact_val",
  "format_float",
  "float_of_string",
  "exp_float",
  "log_float",
  "sqrt_float",
  "power_float",
  "sin_float",
  "cos_float",
  "tan_float",
  "asin_float",
  "acos_float",
  "atan_float",
  "atan2_float",
  "gc_stat",
  "gc_get",
  "gc_set",
  "gc_minor",
  "gc_major",
  "gc_full_major",
  "hash_univ_param",
  "intern_val",
  "int_of_string",
  "format_int",
  "open_descriptor",
  "channel_descriptor",
  "channel_size",
  "flush",
  "output_char",
  "output_int",
  "output",
  "seek_out",
  "pos_out",
  "close_out",
  "input_char",
  "input_int",
  "input",
  "input_nonblocking",
  "seek_in",
  "pos_in",
  "close_in",
  "input_scan_line",
  "get_next_char",
  "start_interp",
  "realloc_global",
  "static_alloc",
  "static_free",
  "static_resize",
  "obj_is_block",
  "obj_block",
  "available_primitives",
  "parse_engine",
  "create_string",
  "compare_strings",
  "blit_string",
  "fill_string",
  "is_printable",
  "sys_exit",
  "sys_open",
  "sys_close",
  "sys_remove",
  "sys_rename",
  "sys_chdir",
  "sys_getenv",
  "sys_system_command",
  "sys_catch_break",
  "sml_equal",
  "sml_not_equal",
  "sml_system",
  "sml_abs_int",
  "sml_floor",
  "sml_ceil",
  "sml_round",
  "sml_trunc",
  "sml_abs_real",
  "sml_sqrt",
  "sml_sin",
  "sml_cos",
  "sml_exp",
  "sml_ln",
  "sml_int_of_string",
  "sml_concat",
  "sml_chr",
  "sml_ord",
  "sml_float_of_string",
  "sml_string_of_int",
  "sml_string_of_float",
  "sml_makestring_of_char",
  "sml_makestring_of_string",
  "sml_getrealtime",
  "sml_getrutime",
  "sml_errno",
  "sml_getdir",
  "sml_mkdir",
  "sml_rmdir",
  "sml_opendir",
  "sml_rewinddir",
  "sml_readdir",
  "sml_closedir",
  "sml_isdir",
  "sml_modtime",
  "sml_settime",
  "sml_access",
  "sml_tmpnam",
  "sml_errormsg",
  "sml_asin",
  "sml_acos",
  "sml_atan2",
  "sml_pow",
  "sml_localtime",
  "sml_gmtime",
  "sml_mktime",
  "sml_asctime",
  "sml_strftime",
  "sml_general_string_of_float",
  "sml_filesize",
  "sml_int_of_hex",
  "sml_word_of_hex",
  "sml_word_of_dec",
  "sml_hexstring_of_word",
  "sml_sinh",
  "sml_cosh",
  "sml_tanh",
  "weak_sub",
  "weak_isdead",
  "weak_arr",
  "string_mlval",
  "mlval_string",
  "w8vectofloat",
  "floattow8vec",
  "w8vectodouble",
  "doubletow8vec",
  "sml_localoffset",
  "sml_exnname",
  "sml_exnmessage",
  "sml_realpath",
  "sml_uname",
  "sml_islink",
  "sml_readlink",
  "sml_devinode",
  "sml_setdisk",
  "md5sum",
  "alloc_valueptr",
  "sml_init_register",
  "c_var",
  "cfun_app1",
  "cfun_app2",
  "cfun_app3",
  "cfun_app4",
  "cfun_app5",
  0 };
