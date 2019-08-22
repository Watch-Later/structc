﻿#ifndef _CSTR_H
#define _CSTR_H

#include "strext.h"

#ifndef CSTR_CREATE

struct cstr {
    char * str;     // 字符串
    size_t cap;     // 容量
    size_t len;     // 长度
};

// CSTR_INT 构建字符串初始化大小
#define CSTR_INT    (1 << 7)

typedef struct cstr * cstr_t;

//
// CSTR_CREATE - 栈上创建 cstr_t 结构
// CSTR_DELETE - 释放栈上 cstr_t 结构
// var      : 变量名
//
#define CSTR_CREATE(var)                \
struct cstr var[1] = { {                \
    .str = malloc(CSTR_INT),            \
    .cap = CSTR_INT,                    \
} }

#define CSTR_DELETE(var)                \
free((var)->str)

#endif//CSTR_CREATE

//
// cstr_expand - low level 字符串扩容 api
// cs       : 可变字符串
// len      : 扩容的长度
// return   : cstr::str + cstr::len 位置的串
//
char * cstr_expand(cstr_t cs, size_t len);

//
// cstr_delete - cstr_t 释放函数
// cs       : 待释放的串对象
// return   : void
//
extern void cstr_delete(cstr_t cs);

//
// cstr_create - cstr_t 创建函数, 根据 C 串创建 cstr_t 字符串
// str      : 待创建的字符串
// len      : 创建串的长度
// return   : 返回创建的字符串
//
extern cstr_t cstr_creats(const char * str);
extern cstr_t cstr_create(const char * str, size_t len);

//
// cstr_t 串结构中添加字符等
// cs       : cstr_t 串
// c        : 添加 char
// str      : 添加 char *
// len      : 添加串的长度
// return   : void
//
extern void cstr_appendc(cstr_t cs, int c);
extern void cstr_appends(cstr_t cs, const char * str);
extern void cstr_appendn(cstr_t cs, const char * str, size_t len);

//
// cstr_get - 通过 str_t 串得到一个 C 串以'\0'结尾
// cs       : cstr_t 串
// return   : 返回构建 C 串, 内存地址 cs->str
//
extern char * cstr_get(cstr_t cs);

//
// cstr_dup - 得到 C 堆上的串, 需要自行 free
// cs       : cstr_t 串
// return   : 返回创建好的 C 串
//
extern char * cstr_dup(cstr_t cs);

//
// cstr_popup - 字符串头弹出 len 长度字符
// cs       : 可变字符串
// len      : 弹出的长度
// return   : void
//
extern void cstr_popup(cstr_t cs, size_t len);

//
// cstr_sprintf - 参照 sprintf 方式填充内容
// cs       : cstr_t 串
// fmt      : 待格式化的串
// ...      : 等待进入的变量
// return   : 返回创建的 C 字符串内容
//
extern char * cstr_sprintf(cstr_t cs, const char * format, ...);

#endif//_CSTR_H