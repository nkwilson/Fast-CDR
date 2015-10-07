﻿#include <fastcdr/Cdr.h>
#include <fastcdr/FastCdr.h>
#include <fastcdr/exceptions/Exception.h>

#include <stdio.h>
#include <limits>
#include <iostream>

#include <gtest/gtest.h>

using namespace eprosima::fastcdr;
using namespace ::exception;

static const uint8_t octet_t = 32;
static const char char_t =  'Z';
static const uint16_t ushort_t = 65500;
static const int16_t short_t = -32700;
static const uint32_t ulong_t = 4294967200;
static const int32_t long_t = -2147483600;
static const uint64_t ulonglong_t = 18446744073709551600u;
static const int64_t longlong_t = -9223372036800;
static const float float_tt = std::numeric_limits<float>::min();
static const double double_tt = std::numeric_limits<double>::min();
static const bool bool_t = true;
static const std::string string_t = "Hola a todos, esto es un test";
static const std::array<uint8_t, 5> octet_array_t = {{1, 2, 3, 4, 5}};
static const uint8_t octet_array_2_t[5] = {5, 4, 3, 2, 1};
static const std::array<char, 5> char_array_t = {{'A', 'B', 'C', 'D', 'E'}};
static const char char_array_2_t[5] = {'E', 'D', 'C', 'B', 'A'};
static const std::array<uint16_t, 5> ushort_array_t = {{65500, 65501, 65502, 65503, 65504}};
static const uint16_t ushort_array_2_t[5] = {65504, 65503, 65502, 65501, 65500};
static const std::array<int16_t, 5> short_array_t = {{-32700, -32701, -32702, -32703, -32704}};
static const int16_t short_array_2_t[5] = {-32704, -32703, -32702, -32701, -32700};
static const std::array<uint32_t, 5> ulong_array_t = {{4294967200, 4294967201, 4294967202, 4294967203, 4294967204}};
static const uint32_t ulong_array_2_t[5] = {4294967204, 4294967203, 4294967202, 4294967201, 4294967200};
static const std::array<int32_t, 5> long_array_t = {{-2147483600, -2147483601, -2147483602, -2147483603, -2147483604}};
static const int32_t long_array_2_t[5] = {-2147483604, -2147483603, -2147483602, -2147483601, -2147483600};
static const std::array<uint64_t, 5> ulonglong_array_t = {{18446744073709551600u, 18446744073709551601u, 18446744073709551602u, 18446744073709551603u, 18446744073709551604u}};
static const uint64_t ulonglong_array_2_t[5] = {18446744073709551604u, 18446744073709551603u, 18446744073709551602u, 18446744073709551601u, 18446744073709551600u};
static const std::array<int64_t, 5> longlong_array_t = {{-9223372036800, -9223372036801, -9223372036802, -9223372036803, -9223372036804}};
static const int64_t longlong_array_2_t[5] = {-9223372036804, -9223372036803, -9223372036802, -9223372036801, -9223372036800};
static const std::array<float, 5> float_array_t = {{float_tt, float_tt + 1, float_tt + 2, float_tt + 3, float_tt + 4}};
static const float float_array_2_t[5] = {float_tt + 4, float_tt + 3, float_tt + 2, float_tt + 1, float_tt};
static const std::array<double, 5> double_array_t = {{double_tt, double_tt + 1, double_tt + 2, double_tt + 3, double_tt + 4}};
static const double double_array_2_t[5] = {double_tt + 4, double_tt + 3, double_tt + 2, double_tt + 1, double_tt};
static const std::array<bool, 5> bool_array_t = {{true, false, true, false, true}};
static const bool bool_array_2_t[5] = {false, true, false, true, false};
static const std::array<std::string, 5> string_array_t = {{"HOLA", "ADIOS", "HELLO", "BYE", "GOODBYE"}};
static const std::string string_array_2_t[5] = {"HOLA", "ADIOS", "HELLO", "BYE", "GOODBYE"};
static const std::vector<uint8_t> octet_vector_t(octet_array_2_t, octet_array_2_t + sizeof(octet_array_2_t) / sizeof(uint8_t));
static const std::vector<char> char_vector_t(char_array_2_t, char_array_2_t + sizeof(char_array_2_t) / sizeof(char));
static const std::vector<uint16_t> ushort_vector_t(ushort_array_2_t, ushort_array_2_t + sizeof(ushort_array_2_t) / sizeof(uint16_t));
static const std::vector<int16_t> short_vector_t(short_array_2_t, short_array_2_t + sizeof(short_array_2_t) / sizeof(int16_t));
static const std::vector<uint32_t> ulong_vector_t(ulong_array_2_t, ulong_array_2_t + sizeof(ulong_array_2_t) / sizeof(uint32_t));
static const std::vector<int32_t> long_vector_t(long_array_2_t, long_array_2_t + sizeof(long_array_2_t) / sizeof(int32_t));
static const std::vector<uint64_t> ulonglong_vector_t(ulonglong_array_2_t, ulonglong_array_2_t + sizeof(ulonglong_array_2_t) / sizeof(uint64_t));
static const std::vector<int64_t> longlong_vector_t(longlong_array_2_t, longlong_array_2_t + sizeof(longlong_array_2_t) / sizeof(int64_t));
static const std::vector<float> float_vector_t(float_array_2_t, float_array_2_t + sizeof(float_array_2_t) / sizeof(float));
static const std::vector<double> double_vector_t(double_array_2_t, double_array_2_t + sizeof(double_array_2_t) / sizeof(double));
static const std::vector<bool> bool_vector_t(bool_array_2_t, bool_array_2_t + sizeof(bool_array_2_t) / sizeof(bool));
static const std::vector<std::string> string_vector_t(string_array_2_t, string_array_2_t + sizeof(string_array_2_t) / sizeof(std::string));
static const std::array<std::array<std::array<uint32_t, 3>, 2>, 2> triple_ulong_array_t = {{ {{ {{1, 2, 3}}, {{4, 5, 6}} }}, {{ {{7, 8, 9}}, {{10, 11, 12}} }} }};
// Added because error 336.
static const uint8_t octet_seq_t[5] = {5, 4, 3, 2, 1};
static const char char_seq_t[5] = {'E', 'D', 'C', 'B', 'A'};
static const uint16_t ushort_seq_t[5] = {65504, 65503, 65502, 65501, 65500};
static const int16_t short_seq_t[5] = {-32704, -32703, -32702, -32701, -32700};
static const uint32_t ulong_seq_t[5] = {4294967204, 4294967203, 4294967202, 4294967201, 4294967200};
static const int32_t long_seq_t[5] = {-2147483604, -2147483603, -2147483602, -2147483601, -2147483600};
static const uint64_t ulonglong_seq_t[5] = {18446744073709551604u, 18446744073709551603u, 18446744073709551602u, 18446744073709551601u, 18446744073709551600u};
static const int64_t longlong_seq_t[5] = {-9223372036804, -9223372036803, -9223372036802, -9223372036801, -9223372036800};
static const float float_seq_t[5] = {float_tt + 4, float_tt + 3, float_tt + 2, float_tt + 1, float_tt};
static const double double_seq_t[5] = {double_tt + 4, double_tt + 3, double_tt + 2, double_tt + 1, double_tt};
static const bool bool_seq_t[5] = {true, true, false, false, true};
static const std::string string_seq_t[5] = {"HELLO", "BYE", "GOODBYE", "HOLA", "ADIOS"};
// Added because error 337
static const char *c_string_t = "HOLA";

template<typename T>
void EXPECT_ARRAY_EQ(T *array1, const T *array2, size_t size)
{
    for(size_t count = 0; count < size; ++count)
    {
        EXPECT_EQ(array1[count], array2[count]);
    }
}

static void EXPECT_ARRAY_FLOAT_EQ(float *array1, const float *array2, size_t size)
{
    for(size_t count = 0; count < size; ++count)
    {
        EXPECT_FLOAT_EQ(array1[count], array2[count]);
    }
}

static void EXPECT_ARRAY_DOUBLE_EQ(double *array1, const double *array2, size_t size)
{
    for(size_t count = 0; count < size; ++count)
    {
        EXPECT_DOUBLE_EQ(array1[count], array2[count]);
    }
}

TEST(CDRResizeTests, Octet)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << octet_t;
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    uint8_t octet_value = 0;

    EXPECT_NO_THROW(
    {
        cdr_des >> octet_value;
    });

    EXPECT_EQ(octet_value, octet_t);
}

TEST(CDRResizeTests, Char)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << char_t;
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    char char_value = 0;

    EXPECT_NO_THROW(
    {
        cdr_des >> char_value;
    });

    EXPECT_EQ(char_value, char_t);
}

TEST(CDRResizeTests, UnsignedShort)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << ushort_t;
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    uint16_t ushort_value = 0;

    EXPECT_NO_THROW(
    {
        cdr_des >> ushort_value;
    });

    EXPECT_EQ(ushort_value, ushort_t);
}

TEST(CDRResizeTests, Short)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << short_t;
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    int16_t short_value = 0;

    EXPECT_NO_THROW(
    {
        cdr_des >> short_value;
    });

    EXPECT_EQ(short_value, short_t);
}

TEST(CDRResizeTests, UnsignedLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << ulong_t;
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    uint32_t ulong_value = 0;

    EXPECT_NO_THROW(
    {
        cdr_des >> ulong_value;
    });

    EXPECT_EQ(ulong_value, ulong_t);
}

TEST(CDRResizeTests, Long)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << long_t;
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    int32_t long_value = 0;

    EXPECT_NO_THROW(
    {
        cdr_des >> long_value;
    });

    EXPECT_EQ(long_value, long_t);
}

TEST(CDRResizeTests, UnsignedLongLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << ulonglong_t;
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    uint64_t ulonglong_value = 0;

    EXPECT_NO_THROW(
    {
        cdr_des >> ulonglong_value;
    });

    EXPECT_EQ(ulonglong_value, ulonglong_t);
}

TEST(CDRResizeTests, LongLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << longlong_t;
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    int64_t longlong_value = 0;

    EXPECT_NO_THROW(
    {
        cdr_des >> longlong_value;
    });

    EXPECT_EQ(longlong_value, longlong_t);
}

TEST(CDRResizeTests, Float)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << float_tt;
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    float float_value = 0;

    EXPECT_NO_THROW(
    {
        cdr_des >> float_value;
    });

    EXPECT_FLOAT_EQ(float_value, float_tt);
}

TEST(CDRResizeTests, Double)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << double_tt;
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    double double_value = 0;

    EXPECT_NO_THROW(
    {
        cdr_des >> double_value;
    });

    EXPECT_DOUBLE_EQ(double_value, double_tt);
}

TEST(CDRResizeTests, Boolean)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << bool_t;
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    bool bool_value = false;

    EXPECT_NO_THROW(
    {
        cdr_des >> bool_value;
    });

    EXPECT_EQ(bool_value, bool_t);
}

TEST(CDRResizeTests, String)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << string_t;
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    std::string string_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> string_value;
    });

    EXPECT_EQ(string_value, string_t);
}

TEST(CDRResizeTests, STDArrayOctet)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << octet_array_t;
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    std::array<uint8_t, 5> octet_array_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> octet_array_value;
    });

    EXPECT_EQ(octet_array_value, octet_array_t);
}

TEST(CDRResizeTests, STDArrayChar)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << char_array_t;
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    std::array<char, 5> char_array_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> char_array_value;
    });

    EXPECT_EQ(char_array_value, char_array_t);
}

TEST(CDRResizeTests, STDArrayUnsignedShort)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << ushort_array_t;
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    std::array<uint16_t, 5> ushort_array_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> ushort_array_value;
    });

    EXPECT_EQ(ushort_array_value, ushort_array_t);
}

TEST(CDRResizeTests, STDArrayShort)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << short_array_t;
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    std::array<int16_t, 5> short_array_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> short_array_value;
    });

    EXPECT_EQ(short_array_value, short_array_t);
}

TEST(CDRResizeTests, STDArrayUnsignedLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << ulong_array_t;
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    std::array<uint32_t, 5> ulong_array_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> ulong_array_value;
    });

    EXPECT_EQ(ulong_array_value, ulong_array_t);
}

TEST(CDRResizeTests, STDArrayLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << long_array_t;
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    std::array<int32_t, 5> long_array_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> long_array_value;
    });

    EXPECT_EQ(long_array_value, long_array_t);
}

TEST(CDRResizeTests, STDArrayUnsignedLongLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << ulonglong_array_t;
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    std::array<uint64_t, 5> ulonglong_array_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> ulonglong_array_value;
    });

    EXPECT_EQ(ulonglong_array_value, ulonglong_array_t);
}

TEST(CDRResizeTests, STDArrayLongLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << longlong_array_t;
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    std::array<int64_t, 5> longlong_array_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> longlong_array_value;
    });

    EXPECT_EQ(longlong_array_value, longlong_array_t);
}

TEST(CDRResizeTests, STDArrayFloat)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << float_array_t;
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    std::array<float, 5> float_array_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> float_array_value;
    });

    EXPECT_EQ(float_array_value, float_array_t);
}

TEST(CDRResizeTests, STDArrayDouble)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << double_array_t;
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    std::array<double, 5> double_array_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> double_array_value;
    });

    EXPECT_EQ(double_array_value, double_array_t);
}

TEST(CDRResizeTests, STDArrayBoolean)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << bool_array_t;
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    std::array<bool, 5> bool_array_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> bool_array_value;
    });

    EXPECT_EQ(bool_array_value, bool_array_t);
}

TEST(CDRResizeTests, STDArrayString)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << string_array_t;
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    std::array<std::string, 5> string_array_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> string_array_value;
    });

    EXPECT_EQ(string_array_value, string_array_t);
}

TEST(CDRResizeTests, ArrayOctet)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeArray(octet_array_2_t, 5);
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    uint8_t octet_array_2_value[5];

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeArray(octet_array_2_value, 5);
    });

    EXPECT_ARRAY_EQ(octet_array_2_value, octet_array_2_t, 5);
}

TEST(CDRResizeTests, ArrayChar)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeArray(char_array_2_t, 5);
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    char char_array_2_value[5];

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeArray(char_array_2_value, 5);
    });

    EXPECT_ARRAY_EQ(char_array_2_value, char_array_2_t, 5);
}

TEST(CDRResizeTests, ArrayUnsignedShort)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeArray(ushort_array_2_t, 5);
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    uint16_t ushort_array_2_value[5];

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeArray(ushort_array_2_value, 5);
    });

    EXPECT_ARRAY_EQ(ushort_array_2_value, ushort_array_2_t, 5);
}

TEST(CDRResizeTests, ArrayShort)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeArray(short_array_2_t, 5);
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    int16_t short_array_2_value[5];

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeArray(short_array_2_value, 5);
    });

    EXPECT_ARRAY_EQ(short_array_2_value, short_array_2_t, 5);
}

TEST(CDRResizeTests, ArrayUnsignedLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeArray(ulong_array_2_t, 5);
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    uint32_t ulong_array_2_value[5];

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeArray(ulong_array_2_value, 5);
    });

    EXPECT_ARRAY_EQ(ulong_array_2_value, ulong_array_2_t, 5);
}

TEST(CDRResizeTests, ArrayLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeArray(long_array_2_t, 5);
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    int32_t long_array_2_value[5];

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeArray(long_array_2_value, 5);
    });

    EXPECT_ARRAY_EQ(long_array_2_value, long_array_2_t, 5);
}

TEST(CDRResizeTests, ArrayUnsignedLongLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeArray(ulonglong_array_2_t, 5);
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    uint64_t ulonglong_array_2_value[5];

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeArray(ulonglong_array_2_value, 5);
    });

    EXPECT_ARRAY_EQ(ulonglong_array_2_value, ulonglong_array_2_t, 5);
}

TEST(CDRResizeTests, ArrayLongLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeArray(longlong_array_2_t, 5);
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    int64_t longlong_array_2_value[5];

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeArray(longlong_array_2_value, 5);
    });

    EXPECT_ARRAY_EQ(longlong_array_2_value, longlong_array_2_t, 5);
}

TEST(CDRResizeTests, ArrayFloat)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeArray(float_array_2_t, 5);
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    float float_array_2_value[5];

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeArray(float_array_2_value, 5);
    });

    EXPECT_ARRAY_FLOAT_EQ(float_array_2_value, float_array_2_t, 5);
}

TEST(CDRResizeTests, ArrayDouble)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeArray(double_array_2_t, 5);
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    double double_array_2_value[5];

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeArray(double_array_2_value, 5);
    });

    EXPECT_ARRAY_DOUBLE_EQ(double_array_2_value, double_array_2_t, 5);
}

TEST(CDRResizeTests, ArrayBoolean)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeArray(bool_array_2_t, 5);
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    bool bool_array_2_value[5];

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeArray(bool_array_2_value, 5);
    });

    EXPECT_ARRAY_EQ(bool_array_2_value, bool_array_2_t, 5);
}

TEST(CDRResizeTests, ArrayString)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeArray(string_array_2_t, 5);
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    std::string string_array_2_value[5];

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeArray(string_array_2_value, 5);
    });

    EXPECT_ARRAY_EQ(string_array_2_value, string_array_2_t, 5);
}

TEST(CDRResizeTests, STDVectorOctet)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << octet_vector_t;
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    std::vector<uint8_t> octet_vector_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> octet_vector_value;
    });

    EXPECT_EQ(octet_vector_value, octet_vector_t);
}

TEST(CDRResizeTests, STDVectorChar)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << char_vector_t;
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    std::vector<char> char_vector_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> char_vector_value;
    });

    EXPECT_EQ(char_vector_value, char_vector_t);
}

TEST(CDRResizeTests, STDVectorUnsignedShort)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << ushort_vector_t;
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    std::vector<uint16_t> ushort_vector_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> ushort_vector_value;
    });

    EXPECT_EQ(ushort_vector_value, ushort_vector_t);
}

TEST(CDRResizeTests, STDVectorShort)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << short_vector_t;
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    std::vector<int16_t> short_vector_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> short_vector_value;
    });

    EXPECT_EQ(short_vector_value, short_vector_t);
}

TEST(CDRResizeTests, STDVectorUnsignedLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << ulong_vector_t;
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    std::vector<uint32_t> ulong_vector_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> ulong_vector_value;
    });

    EXPECT_EQ(ulong_vector_value, ulong_vector_t);
}

TEST(CDRResizeTests, STDVectorLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << long_vector_t;
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    std::vector<int32_t> long_vector_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> long_vector_value;
    });

    EXPECT_EQ(long_vector_value, long_vector_t);
}

TEST(CDRResizeTests, STDVectorUnsignedLongLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << ulonglong_vector_t;
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    std::vector<uint64_t> ulonglong_vector_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> ulonglong_vector_value;
    });

    EXPECT_EQ(ulonglong_vector_value, ulonglong_vector_t);
}

TEST(CDRResizeTests, STDVectorLongLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << longlong_vector_t;
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    std::vector<int64_t> longlong_vector_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> longlong_vector_value;
    });

    EXPECT_EQ(longlong_vector_value, longlong_vector_t);
}

TEST(CDRResizeTests, STDVectorFloat)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << float_vector_t;
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    std::vector<float> float_vector_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> float_vector_value;
    });

    EXPECT_EQ(float_vector_value, float_vector_t);
}

TEST(CDRResizeTests, STDVectorDouble)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << double_vector_t;
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    std::vector<double> double_vector_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> double_vector_value;
    });

    EXPECT_EQ(double_vector_value, double_vector_t);
}

TEST(CDRResizeTests, STDVectorBoolean)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << bool_vector_t;
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    std::vector<bool> bool_vector_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> bool_vector_value;
    });

    EXPECT_EQ(bool_vector_value, bool_vector_t);
}

TEST(CDRResizeTests, STDVectorString)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << string_vector_t;
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    std::vector<std::string> string_vector_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> string_vector_value;
    });

    EXPECT_EQ(string_vector_value, string_vector_t);
}

TEST(CDRResizeTests, STDTripleArrayUnsignedLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << triple_ulong_array_t;
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    std::array<std::array<std::array<uint32_t, 3>, 2>, 2> triple_ulong_array_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> triple_ulong_array_value;
    });

    EXPECT_EQ(triple_ulong_array_value, triple_ulong_array_t);
}

TEST(CDRResizeTests, SequenceOctet)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeSequence(octet_seq_t, 5);
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    uint8_t *octet_seq_value = NULL; size_t octet_seq_len;

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeSequence(octet_seq_value, octet_seq_len);
    });

    EXPECT_EQ(octet_seq_len, 5);
    EXPECT_ARRAY_EQ(octet_seq_value, octet_seq_t, octet_seq_len);

    free(octet_seq_value);
}

TEST(CDRResizeTests, SequenceChar)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeSequence(char_seq_t, 5);
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    char *char_seq_value = NULL; size_t char_seq_len;

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeSequence(char_seq_value, char_seq_len);
    });

    EXPECT_EQ(char_seq_len, 5);
    EXPECT_ARRAY_EQ(char_seq_value, char_seq_t, char_seq_len);

    free(char_seq_value);
}

TEST(CDRResizeTests, SequenceUnsignedShort)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeSequence(ushort_seq_t, 5);
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    uint16_t *ushort_seq_value = NULL; size_t ushort_seq_len;

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeSequence(ushort_seq_value, ushort_seq_len);
    });

    EXPECT_EQ(ushort_seq_len, 5);
    EXPECT_ARRAY_EQ(ushort_seq_value, ushort_seq_t, ushort_seq_len);

    free(ushort_seq_value);
}

TEST(CDRResizeTests, SequenceShort)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeSequence(short_seq_t, 5);
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    int16_t *short_seq_value = NULL; size_t short_seq_len;

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeSequence(short_seq_value, short_seq_len);
    });

    EXPECT_EQ(short_seq_len, 5);
    EXPECT_ARRAY_EQ(short_seq_value, short_seq_t, short_seq_len);

    free(short_seq_value);
}

TEST(CDRResizeTests, SequenceUnsignedLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeSequence(ulong_seq_t, 5);
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    uint32_t *ulong_seq_value = NULL; size_t ulong_seq_len;

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeSequence(ulong_seq_value, ulong_seq_len);
    });

    EXPECT_EQ(ulong_seq_len, 5);
    EXPECT_ARRAY_EQ(ulong_seq_value, ulong_seq_t, ulong_seq_len);

    free(ulong_seq_value);
}

TEST(CDRResizeTests, SequenceLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeSequence(long_seq_t, 5);
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    int32_t *long_seq_value = NULL; size_t long_seq_len;

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeSequence(long_seq_value, long_seq_len);
    });

    EXPECT_EQ(long_seq_len, 5);
    EXPECT_ARRAY_EQ(long_seq_value, long_seq_t, long_seq_len);

    free(long_seq_value);
}

TEST(CDRResizeTests, SequenceUnsignedLongLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeSequence(ulonglong_seq_t, 5);
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    uint64_t *ulonglong_seq_value = NULL; size_t ulonglong_seq_len;

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeSequence(ulonglong_seq_value, ulonglong_seq_len);
    });

    EXPECT_EQ(ulonglong_seq_len, 5);
    EXPECT_ARRAY_EQ(ulonglong_seq_value, ulonglong_seq_t, ulonglong_seq_len);

    free(ulonglong_seq_value);
}

TEST(CDRResizeTests, SequenceLongLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeSequence(longlong_seq_t, 5);
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    int64_t *longlong_seq_value = NULL; size_t longlong_seq_len;

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeSequence(longlong_seq_value, longlong_seq_len);
    });

    EXPECT_EQ(longlong_seq_len, 5);
    EXPECT_ARRAY_EQ(longlong_seq_value, longlong_seq_t, longlong_seq_len);

    free(longlong_seq_value);
}

TEST(CDRResizeTests, SequenceFloat)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeSequence(float_seq_t, 5);
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    float *float_seq_value = NULL; size_t float_seq_len;

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeSequence(float_seq_value, float_seq_len);
    });

    EXPECT_EQ(float_seq_len, 5);
    EXPECT_ARRAY_FLOAT_EQ(float_seq_value, float_seq_t, float_seq_len);

    free(float_seq_value);
}

TEST(CDRResizeTests, SequenceDouble)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeSequence(double_seq_t, 5);
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    double *double_seq_value = NULL; size_t double_seq_len;

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeSequence(double_seq_value, double_seq_len);
    });

    EXPECT_EQ(double_seq_len, 5);
    EXPECT_ARRAY_DOUBLE_EQ(double_seq_value, double_seq_t, double_seq_len);

    free(double_seq_value);
}

TEST(CDRResizeTests, SequenceBoolean)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeSequence(bool_seq_t, 5);
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    bool *bool_seq_value = NULL; size_t bool_seq_len;

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeSequence(bool_seq_value, bool_seq_len);
    });

    EXPECT_EQ(bool_seq_len, 5);
    EXPECT_ARRAY_EQ(bool_seq_value, bool_seq_t, bool_seq_len);

    free(bool_seq_value);
}

TEST(CDRResizeTests, SequenceString)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeSequence(string_seq_t, 5);
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    std::string *string_seq_value = NULL; size_t string_seq_len;

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeSequence(string_seq_value, string_seq_len);
    });

    EXPECT_EQ(string_seq_len, 5);
    EXPECT_ARRAY_EQ(string_seq_value, string_seq_t, string_seq_len);

    for(size_t count = 0; count < string_seq_len; ++count)
        string_seq_value[count].~basic_string();
    free(string_seq_value);
}

TEST(CDRResizeTests, CString)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serialize(c_string_t);
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    char *c_string_value = NULL;

    EXPECT_NO_THROW(
    {
        cdr_des.deserialize(c_string_value);
    });

    EXPECT_EQ(strcmp(c_string_value, c_string_t) , 0);

    free(c_string_value);
}

TEST(CDRResizeTests, Complete)
{
    // Serialization.
    FastBuffer cdrbuffer;
    Cdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << octet_t << char_t << ushort_t << short_t << ulong_t << long_t << ulonglong_t << longlong_t << float_tt << double_tt << bool_t << string_t;
        cdr_ser << octet_array_t << char_array_t << ushort_array_t << short_array_t << ulong_array_t << long_array_t << ulonglong_array_t << longlong_array_t << float_array_t << double_array_t << bool_array_t;
        cdr_ser.serializeArray(octet_array_2_t, 5).serializeArray(char_array_2_t, 5).serializeArray(ushort_array_2_t, 5).serializeArray(short_array_2_t, 5).serializeArray(ulong_array_2_t, 5);
        cdr_ser.serializeArray(long_array_2_t, 5).serializeArray(ulonglong_array_2_t, 5).serializeArray(longlong_array_2_t, 5).serializeArray(float_array_2_t, 5).serializeArray(double_array_2_t, 5).serializeArray(bool_array_2_t, 5);
        cdr_ser << octet_vector_t << char_vector_t << ushort_vector_t << short_vector_t << ulong_vector_t << long_vector_t << ulonglong_vector_t << longlong_vector_t << float_vector_t << double_vector_t << bool_vector_t;
        cdr_ser << triple_ulong_array_t;
        cdr_ser.serializeSequence(octet_seq_t, 5).serializeSequence(char_seq_t, 5).serializeSequence(ushort_seq_t, 5).serializeSequence(short_seq_t, 5);
        cdr_ser.serializeSequence(ulong_seq_t, 5).serializeSequence(long_seq_t, 5).serializeSequence(ulonglong_seq_t, 5).serializeSequence(longlong_seq_t, 5);
        cdr_ser.serializeSequence(float_seq_t, 5).serializeSequence(double_seq_t, 5);
        cdr_ser.serialize(c_string_t);
    });

    // Deseriazliation.
    Cdr cdr_des(cdrbuffer);

    uint8_t octet_value = 0;
    char char_value = 0;
    uint16_t ushort_value =0;
    int16_t short_value = 0;
    uint32_t ulong_value = 0;
    int32_t long_value = 0;
    uint64_t ulonglong_value = 0;
    int64_t longlong_value = 0;
    float float_value = 0;
    double double_value = 0;
    bool bool_value = false;
    std::string string_value = "";
    std::array<uint8_t, 5> octet_array_value;
    uint8_t octet_array_2_value[5];
    std::array<char, 5> char_array_value;
    char char_array_2_value[5];
    std::array<uint16_t, 5> ushort_array_value;
    uint16_t ushort_array_2_value[5];
    std::array<int16_t, 5> short_array_value;
    int16_t short_array_2_value[5];
    std::array<uint32_t, 5> ulong_array_value;
    uint32_t ulong_array_2_value[5];
    std::array<int32_t, 5> long_array_value;
    int32_t long_array_2_value[5];
    std::array<uint64_t, 5> ulonglong_array_value;
    uint64_t ulonglong_array_2_value[5];
    std::array<int64_t, 5> longlong_array_value;
    int64_t longlong_array_2_value[5];
    std::array<float, 5> float_array_value;
    float float_array_2_value[5];
    std::array<double, 5> double_array_value;
    double double_array_2_value[5];
    std::array<bool, 5> bool_array_value;
    bool bool_array_2_value[5];
    std::vector<uint8_t> octet_vector_value;
    std::vector<char> char_vector_value;
    std::vector<uint16_t> ushort_vector_value;
    std::vector<int16_t> short_vector_value;
    std::vector<uint32_t> ulong_vector_value;
    std::vector<int32_t> long_vector_value;
    std::vector<uint64_t> ulonglong_vector_value;
    std::vector<int64_t> longlong_vector_value;
    std::vector<float> float_vector_value;
    std::vector<double> double_vector_value;
    std::vector<bool> bool_vector_value;
    std::array<std::array<std::array<uint32_t, 3>, 2>, 2> triple_ulong_array_value;
    uint8_t *octet_seq_value = NULL; size_t octet_seq_len;
    char *char_seq_value = NULL; size_t char_seq_len;
    uint16_t *ushort_seq_value = NULL; size_t ushort_seq_len;
    int16_t *short_seq_value = NULL; size_t short_seq_len;
    uint32_t *ulong_seq_value = NULL; size_t ulong_seq_len;
    int32_t *long_seq_value = NULL; size_t long_seq_len;
    uint64_t *ulonglong_seq_value = NULL; size_t ulonglong_seq_len;
    int64_t *longlong_seq_value = NULL; size_t longlong_seq_len;
    float *float_seq_value = NULL; size_t float_seq_len;
    double *double_seq_value = NULL; size_t double_seq_len;
    char *c_string_value = NULL;

    EXPECT_NO_THROW(
    {
        cdr_des >> octet_value >> char_value >> ushort_value >> short_value >> ulong_value >> long_value >> ulonglong_value >> longlong_value >> float_value >> double_value >> bool_value >> string_value;
        cdr_des >> octet_array_value >> char_array_value >> ushort_array_value >> short_array_value >> ulong_array_value >> long_array_value >> ulonglong_array_value >> longlong_array_value >> float_array_value >> double_array_value >> bool_array_value;
        cdr_des.deserializeArray(octet_array_2_value, 5).deserializeArray(char_array_2_value, 5).deserializeArray(ushort_array_2_value, 5).deserializeArray(short_array_2_value, 5).deserializeArray(ulong_array_2_value, 5);
        cdr_des.deserializeArray(long_array_2_value, 5).deserializeArray(ulonglong_array_2_value, 5).deserializeArray(longlong_array_2_value, 5).deserializeArray(float_array_2_value, 5).deserializeArray(double_array_2_value, 5).deserializeArray(bool_array_2_value, 5);
        cdr_des >> octet_vector_value >> char_vector_value >> ushort_vector_value >> short_vector_value >> ulong_vector_value >> long_vector_value >> ulonglong_vector_value >> longlong_vector_value >> float_vector_value >> double_vector_value >> bool_vector_value;
        cdr_des >> triple_ulong_array_value;
        cdr_des.deserializeSequence(octet_seq_value, octet_seq_len).deserializeSequence(char_seq_value, char_seq_len).deserializeSequence(ushort_seq_value, ushort_seq_len); 
        cdr_des.deserializeSequence(short_seq_value, short_seq_len).deserializeSequence(ulong_seq_value, ulong_seq_len).deserializeSequence(long_seq_value, long_seq_len); 
        cdr_des.deserializeSequence(ulonglong_seq_value, ulonglong_seq_len).deserializeSequence(longlong_seq_value, longlong_seq_len).deserializeSequence(float_seq_value, float_seq_len); 
        cdr_des.deserializeSequence(double_seq_value, double_seq_len);
        cdr_des.deserialize(c_string_value);
    });

    EXPECT_EQ(octet_value, octet_t);
    EXPECT_EQ(char_value, char_t);
    EXPECT_EQ(ushort_value, ushort_t);
    EXPECT_EQ(short_value, short_t);
    EXPECT_EQ(ulong_value, ulong_t);
    EXPECT_EQ(long_value, long_t);
    EXPECT_EQ(ulonglong_value, ulonglong_t);
    EXPECT_EQ(longlong_value, longlong_t);
    EXPECT_FLOAT_EQ(float_value, float_tt);
    EXPECT_DOUBLE_EQ(double_value, double_tt);
    EXPECT_EQ(bool_value, bool_t);
    EXPECT_EQ(string_value, string_t);

    EXPECT_EQ(octet_array_value, octet_array_t);
    EXPECT_EQ(char_array_value, char_array_t);
    EXPECT_EQ(ushort_array_value, ushort_array_t);
    EXPECT_EQ(short_array_value, short_array_t);
    EXPECT_EQ(ulong_array_value, ulong_array_t);
    EXPECT_EQ(long_array_value, long_array_t);
    EXPECT_EQ(ulonglong_array_value, ulonglong_array_t);
    EXPECT_EQ(longlong_array_value, longlong_array_t);
    EXPECT_EQ(float_array_value, float_array_t);
    EXPECT_EQ(double_array_value, double_array_t);
    EXPECT_EQ(bool_array_value, bool_array_t);

    EXPECT_ARRAY_EQ(octet_array_2_value, octet_array_2_t, 5);
    EXPECT_ARRAY_EQ(char_array_2_value, char_array_2_t, 5);
    EXPECT_ARRAY_EQ(ushort_array_2_value, ushort_array_2_t, 5);
    EXPECT_ARRAY_EQ(short_array_2_value, short_array_2_t, 5);
    EXPECT_ARRAY_EQ(ulong_array_2_value, ulong_array_2_t, 5);
    EXPECT_ARRAY_EQ(long_array_2_value, long_array_2_t, 5);
    EXPECT_ARRAY_EQ(ulonglong_array_2_value, ulonglong_array_2_t, 5);
    EXPECT_ARRAY_EQ(longlong_array_2_value, longlong_array_2_t, 5);
    EXPECT_ARRAY_FLOAT_EQ(float_array_2_value, float_array_2_t, 5);
    EXPECT_ARRAY_DOUBLE_EQ(double_array_2_value, double_array_2_t, 5);
    EXPECT_ARRAY_EQ(bool_array_2_value, bool_array_2_t, 5);

    EXPECT_EQ(octet_vector_value, octet_vector_t);
    EXPECT_EQ(char_vector_value, char_vector_t);
    EXPECT_EQ(ushort_vector_value, ushort_vector_t);
    EXPECT_EQ(short_vector_value, short_vector_t);
    EXPECT_EQ(ulong_vector_value, ulong_vector_t);
    EXPECT_EQ(long_vector_value, long_vector_t);
    EXPECT_EQ(ulonglong_vector_value, ulonglong_vector_t);
    EXPECT_EQ(longlong_vector_value, longlong_vector_t);
    EXPECT_EQ(float_vector_value, float_vector_t);
    EXPECT_EQ(double_vector_value, double_vector_t);
    EXPECT_EQ(bool_vector_value, bool_vector_t);

    EXPECT_EQ(triple_ulong_array_t, triple_ulong_array_value);
    EXPECT_EQ(octet_seq_len, 5);
    EXPECT_ARRAY_EQ(octet_seq_value, octet_seq_t, 5);
    EXPECT_EQ(char_seq_len, 5);
    EXPECT_ARRAY_EQ(char_seq_value, char_seq_t, 5);
    EXPECT_EQ(ushort_seq_len, 5);
    EXPECT_ARRAY_EQ(ushort_seq_value, ushort_seq_t, 5);
    EXPECT_EQ(short_seq_len, 5);
    EXPECT_ARRAY_EQ(short_seq_value, short_seq_t, 5);
    EXPECT_EQ(ulong_seq_len, 5);
    EXPECT_ARRAY_EQ(ulong_seq_value, ulong_seq_t, 5);
    EXPECT_EQ(long_seq_len, 5);
    EXPECT_ARRAY_EQ(long_seq_value, long_seq_t, 5);
    EXPECT_EQ(ulonglong_seq_len, 5);
    EXPECT_ARRAY_EQ(ulonglong_seq_value, ulonglong_seq_t, 5);
    EXPECT_EQ(longlong_seq_len, 5);
    EXPECT_ARRAY_EQ(longlong_seq_value, longlong_seq_t, 5);
    EXPECT_EQ(float_seq_len, 5);
    EXPECT_ARRAY_FLOAT_EQ(float_seq_value, float_seq_t, 5);
    EXPECT_EQ(double_seq_len, 5);
    EXPECT_ARRAY_DOUBLE_EQ(double_seq_value, double_seq_t, 5);

    EXPECT_EQ(strcmp(c_string_t, c_string_value), 0);

    free(octet_seq_value);
    free(char_seq_value);
    free(ushort_seq_value);
    free(short_seq_value);
    free(ulong_seq_value);
    free(long_seq_value);
    free(ulonglong_seq_value);
    free(longlong_seq_value);
    free(float_seq_value);
    free(double_seq_value);
    free(c_string_value);
}

TEST(FastCDRResizeTests, Octet)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << octet_t;
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    uint8_t octet_value = 0;

    EXPECT_NO_THROW(
    {
        cdr_des >> octet_value;
    });

    EXPECT_EQ(octet_value, octet_t);
}

TEST(FastCDRResizeTests, Char)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << char_t;
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    char char_value = 0;

    EXPECT_NO_THROW(
    {
        cdr_des >> char_value;
    });

    EXPECT_EQ(char_value, char_t);
}

TEST(FastCDRResizeTests, UnsignedShort)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << ushort_t;
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    uint16_t ushort_value = 0;

    EXPECT_NO_THROW(
    {
        cdr_des >> ushort_value;
    });

    EXPECT_EQ(ushort_value, ushort_t);
}

TEST(FastCDRResizeTests, Short)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << short_t;
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    int16_t short_value = 0;

    EXPECT_NO_THROW(
    {
        cdr_des >> short_value;
    });

    EXPECT_EQ(short_value, short_t);
}

TEST(FastCDRResizeTests, UnsignedLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << ulong_t;
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    uint32_t ulong_value = 0;

    EXPECT_NO_THROW(
    {
        cdr_des >> ulong_value;
    });

    EXPECT_EQ(ulong_value, ulong_t);
}

TEST(FastCDRResizeTests, Long)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << long_t;
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    int32_t long_value = 0;

    EXPECT_NO_THROW(
    {
        cdr_des >> long_value;
    });

    EXPECT_EQ(long_value, long_t);
}

TEST(FastCDRResizeTests, UnsignedLongLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << ulonglong_t;
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    uint64_t ulonglong_value = 0;

    EXPECT_NO_THROW(
    {
        cdr_des >> ulonglong_value;
    });

    EXPECT_EQ(ulonglong_value, ulonglong_t);
}

TEST(FastCDRResizeTests, LongLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << longlong_t;
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    int64_t longlong_value = 0;

    EXPECT_NO_THROW(
    {
        cdr_des >> longlong_value;
    });

    EXPECT_EQ(longlong_value, longlong_t);
}

TEST(FastCDRResizeTests, Float)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << float_tt;
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    float float_value = 0;

    EXPECT_NO_THROW(
    {
        cdr_des >> float_value;
    });

    EXPECT_FLOAT_EQ(float_value, float_tt);
}

TEST(FastCDRResizeTests, Double)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << double_tt;
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    double double_value = 0;

    EXPECT_NO_THROW(
    {
        cdr_des >> double_value;
    });

    EXPECT_DOUBLE_EQ(double_value, double_tt);
}

TEST(FastCDRResizeTests, Boolean)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << bool_t;
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    bool bool_value = false;

    EXPECT_NO_THROW(
    {
        cdr_des >> bool_value;
    });

    EXPECT_EQ(bool_value, bool_t);
}

TEST(FastCDRResizeTests, String)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << string_t;
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    std::string string_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> string_value;
    });

    EXPECT_EQ(string_value, string_t);
}

TEST(FastCDRResizeTests, STDArrayOctet)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << octet_array_t;
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    std::array<uint8_t, 5> octet_array_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> octet_array_value;
    });

    EXPECT_EQ(octet_array_value, octet_array_t);
}

TEST(FastCDRResizeTests, STDArrayChar)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << char_array_t;
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    std::array<char, 5> char_array_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> char_array_value;
    });

    EXPECT_EQ(char_array_value, char_array_t);
}

TEST(FastCDRResizeTests, STDArrayUnsignedShort)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << ushort_array_t;
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    std::array<uint16_t, 5> ushort_array_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> ushort_array_value;
    });

    EXPECT_EQ(ushort_array_value, ushort_array_t);
}

TEST(FastCDRResizeTests, STDArrayShort)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << short_array_t;
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    std::array<int16_t, 5> short_array_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> short_array_value;
    });

    EXPECT_EQ(short_array_value, short_array_t);
}

TEST(FastCDRResizeTests, STDArrayUnsignedLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << ulong_array_t;
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    std::array<uint32_t, 5> ulong_array_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> ulong_array_value;
    });

    EXPECT_EQ(ulong_array_value, ulong_array_t);
}

TEST(FastCDRResizeTests, STDArrayLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << long_array_t;
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    std::array<int32_t, 5> long_array_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> long_array_value;
    });

    EXPECT_EQ(long_array_value, long_array_t);
}

TEST(FastCDRResizeTests, STDArrayUnsignedLongLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << ulonglong_array_t;
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    std::array<uint64_t, 5> ulonglong_array_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> ulonglong_array_value;
    });

    EXPECT_EQ(ulonglong_array_value, ulonglong_array_t);
}

TEST(FastCDRResizeTests, STDArrayLongLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << longlong_array_t;
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    std::array<int64_t, 5> longlong_array_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> longlong_array_value;
    });

    EXPECT_EQ(longlong_array_value, longlong_array_t);
}

TEST(FastCDRResizeTests, STDArrayFloat)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << float_array_t;
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    std::array<float, 5> float_array_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> float_array_value;
    });

    EXPECT_EQ(float_array_value, float_array_t);
}

TEST(FastCDRResizeTests, STDArrayDouble)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << double_array_t;
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    std::array<double, 5> double_array_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> double_array_value;
    });

    EXPECT_EQ(double_array_value, double_array_t);
}

TEST(FastCDRResizeTests, STDArrayBoolean)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << bool_array_t;
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    std::array<bool, 5> bool_array_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> bool_array_value;
    });

    EXPECT_EQ(bool_array_value, bool_array_t);
}

TEST(FastCDRResizeTests, STDArrayString)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << string_array_t;
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    std::array<std::string, 5> string_array_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> string_array_value;
    });

    EXPECT_EQ(string_array_value, string_array_t);
}

TEST(FastCDRResizeTests, ArrayOctet)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeArray(octet_array_2_t, 5);
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    uint8_t octet_array_2_value[5];

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeArray(octet_array_2_value, 5);
    });

    EXPECT_ARRAY_EQ(octet_array_2_value, octet_array_2_t, 5);
}

TEST(FastCDRResizeTests, ArrayChar)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeArray(char_array_2_t, 5);
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    char char_array_2_value[5];

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeArray(char_array_2_value, 5);
    });

    EXPECT_ARRAY_EQ(char_array_2_value, char_array_2_t, 5);
}

TEST(FastCDRResizeTests, ArrayUnsignedShort)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeArray(ushort_array_2_t, 5);
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    uint16_t ushort_array_2_value[5];

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeArray(ushort_array_2_value, 5);
    });

    EXPECT_ARRAY_EQ(ushort_array_2_value, ushort_array_2_t, 5);
}

TEST(FastCDRResizeTests, ArrayShort)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeArray(short_array_2_t, 5);
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    int16_t short_array_2_value[5];

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeArray(short_array_2_value, 5);
    });

    EXPECT_ARRAY_EQ(short_array_2_value, short_array_2_t, 5);
}

TEST(FastCDRResizeTests, ArrayUnsignedLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeArray(ulong_array_2_t, 5);
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    uint32_t ulong_array_2_value[5];

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeArray(ulong_array_2_value, 5);
    });

    EXPECT_ARRAY_EQ(ulong_array_2_value, ulong_array_2_t, 5);
}

TEST(FastCDRResizeTests, ArrayLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeArray(long_array_2_t, 5);
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    int32_t long_array_2_value[5];

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeArray(long_array_2_value, 5);
    });

    EXPECT_ARRAY_EQ(long_array_2_value, long_array_2_t, 5);
}

TEST(FastCDRResizeTests, ArrayUnsignedLongLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeArray(ulonglong_array_2_t, 5);
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    uint64_t ulonglong_array_2_value[5];

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeArray(ulonglong_array_2_value, 5);
    });

    EXPECT_ARRAY_EQ(ulonglong_array_2_value, ulonglong_array_2_t, 5);
}

TEST(FastCDRResizeTests, ArrayLongLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeArray(longlong_array_2_t, 5);
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    int64_t longlong_array_2_value[5];

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeArray(longlong_array_2_value, 5);
    });

    EXPECT_ARRAY_EQ(longlong_array_2_value, longlong_array_2_t, 5);
}

TEST(FastCDRResizeTests, ArrayFloat)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeArray(float_array_2_t, 5);
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    float float_array_2_value[5];

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeArray(float_array_2_value, 5);
    });

    EXPECT_ARRAY_FLOAT_EQ(float_array_2_value, float_array_2_t, 5);
}

TEST(FastCDRResizeTests, ArrayDouble)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeArray(double_array_2_t, 5);
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    double double_array_2_value[5];

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeArray(double_array_2_value, 5);
    });

    EXPECT_ARRAY_DOUBLE_EQ(double_array_2_value, double_array_2_t, 5);
}

TEST(FastCDRResizeTests, ArrayBoolean)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeArray(bool_array_2_t, 5);
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    bool bool_array_2_value[5];

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeArray(bool_array_2_value, 5);
    });

    EXPECT_ARRAY_EQ(bool_array_2_value, bool_array_2_t, 5);
}

TEST(FastCDRResizeTests, ArrayString)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeArray(string_array_2_t, 5);
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    std::string string_array_2_value[5];

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeArray(string_array_2_value, 5);
    });

    EXPECT_ARRAY_EQ(string_array_2_value, string_array_2_t, 5);
}

TEST(FastCDRResizeTests, STDVectorOctet)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << octet_vector_t;
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    std::vector<uint8_t> octet_vector_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> octet_vector_value;
    });

    EXPECT_EQ(octet_vector_value, octet_vector_t);
}

TEST(FastCDRResizeTests, STDVectorChar)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << char_vector_t;
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    std::vector<char> char_vector_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> char_vector_value;
    });

    EXPECT_EQ(char_vector_value, char_vector_t);
}

TEST(FastCDRResizeTests, STDVectorUnsignedShort)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << ushort_vector_t;
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    std::vector<uint16_t> ushort_vector_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> ushort_vector_value;
    });

    EXPECT_EQ(ushort_vector_value, ushort_vector_t);
}

TEST(FastCDRResizeTests, STDVectorShort)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << short_vector_t;
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    std::vector<int16_t> short_vector_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> short_vector_value;
    });

    EXPECT_EQ(short_vector_value, short_vector_t);
}

TEST(FastCDRResizeTests, STDVectorUnsignedLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << ulong_vector_t;
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    std::vector<uint32_t> ulong_vector_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> ulong_vector_value;
    });

    EXPECT_EQ(ulong_vector_value, ulong_vector_t);
}

TEST(FastCDRResizeTests, STDVectorLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << long_vector_t;
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    std::vector<int32_t> long_vector_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> long_vector_value;
    });

    EXPECT_EQ(long_vector_value, long_vector_t);
}

TEST(FastCDRResizeTests, STDVectorUnsignedLongLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << ulonglong_vector_t;
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    std::vector<uint64_t> ulonglong_vector_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> ulonglong_vector_value;
    });

    EXPECT_EQ(ulonglong_vector_value, ulonglong_vector_t);
}

TEST(FastCDRResizeTests, STDVectorLongLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << longlong_vector_t;
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    std::vector<int64_t> longlong_vector_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> longlong_vector_value;
    });

    EXPECT_EQ(longlong_vector_value, longlong_vector_t);
}

TEST(FastCDRResizeTests, STDVectorFloat)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << float_vector_t;
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    std::vector<float> float_vector_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> float_vector_value;
    });

    EXPECT_EQ(float_vector_value, float_vector_t);
}

TEST(FastCDRResizeTests, STDVectorDouble)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << double_vector_t;
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    std::vector<double> double_vector_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> double_vector_value;
    });

    EXPECT_EQ(double_vector_value, double_vector_t);
}

TEST(FastCDRResizeTests, STDVectorBoolean)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << bool_vector_t;
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    std::vector<bool> bool_vector_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> bool_vector_value;
    });

    EXPECT_EQ(bool_vector_value, bool_vector_t);
}

TEST(FastCDRResizeTests, STDVectorString)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << string_vector_t;
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    std::vector<std::string> string_vector_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> string_vector_value;
    });

    EXPECT_EQ(string_vector_value, string_vector_t);
}

TEST(FastCDRResizeTests, STDTripleArrayUnsignedLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << triple_ulong_array_t;
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    std::array<std::array<std::array<uint32_t, 3>, 2>, 2> triple_ulong_array_value;

    EXPECT_NO_THROW(
    {
        cdr_des >> triple_ulong_array_value;
    });

    EXPECT_EQ(triple_ulong_array_value, triple_ulong_array_t);
}

TEST(FastCDRResizeTests, SequenceOctet)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeSequence(octet_seq_t, 5);
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    uint8_t *octet_seq_value = NULL; size_t octet_seq_len;

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeSequence(octet_seq_value, octet_seq_len);
    });

    EXPECT_EQ(octet_seq_len, 5);
    EXPECT_ARRAY_EQ(octet_seq_value, octet_seq_t, octet_seq_len);

    free(octet_seq_value);
}

TEST(FastCDRResizeTests, SequenceChar)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeSequence(char_seq_t, 5);
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    char *char_seq_value = NULL; size_t char_seq_len;

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeSequence(char_seq_value, char_seq_len);
    });

    EXPECT_EQ(char_seq_len, 5);
    EXPECT_ARRAY_EQ(char_seq_value, char_seq_t, char_seq_len);

    free(char_seq_value);
}

TEST(FastCDRResizeTests, SequenceUnsignedShort)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeSequence(ushort_seq_t, 5);
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    uint16_t *ushort_seq_value = NULL; size_t ushort_seq_len;

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeSequence(ushort_seq_value, ushort_seq_len);
    });

    EXPECT_EQ(ushort_seq_len, 5);
    EXPECT_ARRAY_EQ(ushort_seq_value, ushort_seq_t, ushort_seq_len);

    free(ushort_seq_value);
}

TEST(FastCDRResizeTests, SequenceShort)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeSequence(short_seq_t, 5);
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    int16_t *short_seq_value = NULL; size_t short_seq_len;

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeSequence(short_seq_value, short_seq_len);
    });

    EXPECT_EQ(short_seq_len, 5);
    EXPECT_ARRAY_EQ(short_seq_value, short_seq_t, short_seq_len);

    free(short_seq_value);
}

TEST(FastCDRResizeTests, SequenceUnsignedLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeSequence(ulong_seq_t, 5);
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    uint32_t *ulong_seq_value = NULL; size_t ulong_seq_len;

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeSequence(ulong_seq_value, ulong_seq_len);
    });

    EXPECT_EQ(ulong_seq_len, 5);
    EXPECT_ARRAY_EQ(ulong_seq_value, ulong_seq_t, ulong_seq_len);

    free(ulong_seq_value);
}

TEST(FastCDRResizeTests, SequenceLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeSequence(long_seq_t, 5);
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    int32_t *long_seq_value = NULL; size_t long_seq_len;

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeSequence(long_seq_value, long_seq_len);
    });

    EXPECT_EQ(long_seq_len, 5);
    EXPECT_ARRAY_EQ(long_seq_value, long_seq_t, long_seq_len);

    free(long_seq_value);
}

TEST(FastCDRResizeTests, SequenceUnsignedLongLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeSequence(ulonglong_seq_t, 5);
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    uint64_t *ulonglong_seq_value = NULL; size_t ulonglong_seq_len;

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeSequence(ulonglong_seq_value, ulonglong_seq_len);
    });

    EXPECT_EQ(ulonglong_seq_len, 5);
    EXPECT_ARRAY_EQ(ulonglong_seq_value, ulonglong_seq_t, ulonglong_seq_len);

    free(ulonglong_seq_value);
}

TEST(FastCDRResizeTests, SequenceLongLong)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeSequence(longlong_seq_t, 5);
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    int64_t *longlong_seq_value = NULL; size_t longlong_seq_len;

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeSequence(longlong_seq_value, longlong_seq_len);
    });

    EXPECT_EQ(longlong_seq_len, 5);
    EXPECT_ARRAY_EQ(longlong_seq_value, longlong_seq_t, longlong_seq_len);

    free(longlong_seq_value);
}

TEST(FastCDRResizeTests, SequenceFloat)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeSequence(float_seq_t, 5);
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    float *float_seq_value = NULL; size_t float_seq_len;

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeSequence(float_seq_value, float_seq_len);
    });

    EXPECT_EQ(float_seq_len, 5);
    EXPECT_ARRAY_FLOAT_EQ(float_seq_value, float_seq_t, float_seq_len);

    free(float_seq_value);
}

TEST(FastCDRResizeTests, SequenceDouble)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeSequence(double_seq_t, 5);
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    double *double_seq_value = NULL; size_t double_seq_len;

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeSequence(double_seq_value, double_seq_len);
    });

    EXPECT_EQ(double_seq_len, 5);
    EXPECT_ARRAY_DOUBLE_EQ(double_seq_value, double_seq_t, double_seq_len);

    free(double_seq_value);
}

TEST(FastCDRResizeTests, SequenceBoolean)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeSequence(bool_seq_t, 5);
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    bool *bool_seq_value = NULL; size_t bool_seq_len;

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeSequence(bool_seq_value, bool_seq_len);
    });

    EXPECT_EQ(bool_seq_len, 5);
    EXPECT_ARRAY_EQ(bool_seq_value, bool_seq_t, bool_seq_len);

    free(bool_seq_value);
}

TEST(FastCDRResizeTests, SequenceString)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serializeSequence(string_seq_t, 5);
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    std::string *string_seq_value = NULL; size_t string_seq_len;

    EXPECT_NO_THROW(
    {
        cdr_des.deserializeSequence(string_seq_value, string_seq_len);
    });

    EXPECT_EQ(string_seq_len, 5);
    EXPECT_ARRAY_EQ(string_seq_value, string_seq_t, string_seq_len);

    for(size_t count = 0; count < string_seq_len; ++count)
        string_seq_value[count].~basic_string();
    free(string_seq_value);
}

TEST(FastCDRResizeTests, CString)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser.serialize(c_string_t);
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    char *c_string_value = NULL;

    EXPECT_NO_THROW(
    {
        cdr_des.deserialize(c_string_value);
    });

    EXPECT_EQ(strcmp(c_string_value, c_string_t) , 0);

    free(c_string_value);
}


TEST(FastCDRResizeTests, Complete)
{
    // Serialization.
    FastBuffer cdrbuffer;
    FastCdr cdr_ser(cdrbuffer);

    EXPECT_NO_THROW(
    {
        cdr_ser << octet_t << char_t << ushort_t << short_t << ulong_t << long_t << ulonglong_t << longlong_t << float_tt << double_tt << bool_t << string_t;
        cdr_ser << octet_array_t << char_array_t << ushort_array_t << short_array_t << ulong_array_t << long_array_t << ulonglong_array_t << longlong_array_t << float_array_t << double_array_t << bool_array_t;
        cdr_ser.serializeArray(octet_array_2_t, 5).serializeArray(char_array_2_t, 5).serializeArray(ushort_array_2_t, 5).serializeArray(short_array_2_t, 5).serializeArray(ulong_array_2_t, 5);
        cdr_ser.serializeArray(long_array_2_t, 5).serializeArray(ulonglong_array_2_t, 5).serializeArray(longlong_array_2_t, 5).serializeArray(float_array_2_t, 5).serializeArray(double_array_2_t, 5).serializeArray(bool_array_2_t, 5);
        cdr_ser << octet_vector_t << char_vector_t << ushort_vector_t << short_vector_t << ulong_vector_t << long_vector_t << ulonglong_vector_t << longlong_vector_t << float_vector_t << double_vector_t << bool_vector_t;
        cdr_ser << triple_ulong_array_t;
        cdr_ser.serializeSequence(octet_seq_t, 5).serializeSequence(char_seq_t, 5).serializeSequence(ushort_seq_t, 5).serializeSequence(short_seq_t, 5);
        cdr_ser.serializeSequence(ulong_seq_t, 5).serializeSequence(long_seq_t, 5).serializeSequence(ulonglong_seq_t, 5).serializeSequence(longlong_seq_t, 5);
        cdr_ser.serializeSequence(float_seq_t, 5).serializeSequence(double_seq_t, 5);
        cdr_ser.serialize(c_string_t);
    });

    // Deseriazliation.
    FastCdr cdr_des(cdrbuffer);

    uint8_t octet_value = 0;
    char char_value = 0;
    uint16_t ushort_value =0;
    int16_t short_value = 0;
    uint32_t ulong_value = 0;
    int32_t long_value = 0;
    uint64_t ulonglong_value = 0;
    int64_t longlong_value = 0;
    float float_value = 0;
    double double_value = 0;
    bool bool_value = false;
    std::string string_value = "";
    std::array<uint8_t, 5> octet_array_value;
    uint8_t octet_array_2_value[5];
    std::array<char, 5> char_array_value;
    char char_array_2_value[5];
    std::array<uint16_t, 5> ushort_array_value;
    uint16_t ushort_array_2_value[5];
    std::array<int16_t, 5> short_array_value;
    int16_t short_array_2_value[5];
    std::array<uint32_t, 5> ulong_array_value;
    uint32_t ulong_array_2_value[5];
    std::array<int32_t, 5> long_array_value;
    int32_t long_array_2_value[5];
    std::array<uint64_t, 5> ulonglong_array_value;
    uint64_t ulonglong_array_2_value[5];
    std::array<int64_t, 5> longlong_array_value;
    int64_t longlong_array_2_value[5];
    std::array<float, 5> float_array_value;
    float float_array_2_value[5];
    std::array<double, 5> double_array_value;
    double double_array_2_value[5];
    std::array<bool, 5> bool_array_value;
    bool bool_array_2_value[5];
    std::vector<uint8_t> octet_vector_value;
    std::vector<char> char_vector_value;
    std::vector<uint16_t> ushort_vector_value;
    std::vector<int16_t> short_vector_value;
    std::vector<uint32_t> ulong_vector_value;
    std::vector<int32_t> long_vector_value;
    std::vector<uint64_t> ulonglong_vector_value;
    std::vector<int64_t> longlong_vector_value;
    std::vector<float> float_vector_value;
    std::vector<double> double_vector_value;
    std::vector<bool> bool_vector_value;
    std::array<std::array<std::array<uint32_t, 3>, 2>, 2> triple_ulong_array_value;
    uint8_t *octet_seq_value = NULL; size_t octet_seq_len;
    char *char_seq_value = NULL; size_t char_seq_len;
    uint16_t *ushort_seq_value = NULL; size_t ushort_seq_len;
    int16_t *short_seq_value = NULL; size_t short_seq_len;
    uint32_t *ulong_seq_value = NULL; size_t ulong_seq_len;
    int32_t *long_seq_value = NULL; size_t long_seq_len;
    uint64_t *ulonglong_seq_value = NULL; size_t ulonglong_seq_len;
    int64_t *longlong_seq_value = NULL; size_t longlong_seq_len;
    float *float_seq_value = NULL; size_t float_seq_len;
    double *double_seq_value = NULL; size_t double_seq_len;
    char *c_string_value = NULL;

    EXPECT_NO_THROW(
    {
        cdr_des >> octet_value >> char_value >> ushort_value >> short_value >> ulong_value >> long_value >> ulonglong_value >> longlong_value >> float_value >> double_value >> bool_value >> string_value;
        cdr_des >> octet_array_value >> char_array_value >> ushort_array_value >> short_array_value >> ulong_array_value >> long_array_value >> ulonglong_array_value >> longlong_array_value >> float_array_value >> double_array_value >> bool_array_value;
        cdr_des.deserializeArray(octet_array_2_value, 5).deserializeArray(char_array_2_value, 5).deserializeArray(ushort_array_2_value, 5).deserializeArray(short_array_2_value, 5).deserializeArray(ulong_array_2_value, 5);
        cdr_des.deserializeArray(long_array_2_value, 5).deserializeArray(ulonglong_array_2_value, 5).deserializeArray(longlong_array_2_value, 5).deserializeArray(float_array_2_value, 5).deserializeArray(double_array_2_value, 5).deserializeArray(bool_array_2_value, 5);
        cdr_des >> octet_vector_value >> char_vector_value >> ushort_vector_value >> short_vector_value >> ulong_vector_value >> long_vector_value >> ulonglong_vector_value >> longlong_vector_value >> float_vector_value >> double_vector_value >> bool_vector_value;
        cdr_des >> triple_ulong_array_value;
        cdr_des.deserializeSequence(octet_seq_value, octet_seq_len).deserializeSequence(char_seq_value, char_seq_len).deserializeSequence(ushort_seq_value, ushort_seq_len); 
        cdr_des.deserializeSequence(short_seq_value, short_seq_len).deserializeSequence(ulong_seq_value, ulong_seq_len).deserializeSequence(long_seq_value, long_seq_len); 
        cdr_des.deserializeSequence(ulonglong_seq_value, ulonglong_seq_len).deserializeSequence(longlong_seq_value, longlong_seq_len).deserializeSequence(float_seq_value, float_seq_len); 
        cdr_des.deserializeSequence(double_seq_value, double_seq_len);
        cdr_des.deserialize(c_string_value);
    });

    EXPECT_EQ(octet_value, octet_t);
    EXPECT_EQ(char_value, char_t);
    EXPECT_EQ(ushort_value, ushort_t);
    EXPECT_EQ(short_value, short_t);
    EXPECT_EQ(ulong_value, ulong_t);
    EXPECT_EQ(long_value, long_t);
    EXPECT_EQ(ulonglong_value, ulonglong_t);
    EXPECT_EQ(longlong_value, longlong_t);
    EXPECT_FLOAT_EQ(float_value, float_tt);
    EXPECT_DOUBLE_EQ(double_value, double_tt);
    EXPECT_EQ(bool_value, bool_t);
    EXPECT_EQ(string_value, string_t);

    EXPECT_EQ(octet_array_value, octet_array_t);
    EXPECT_EQ(char_array_value, char_array_t);
    EXPECT_EQ(ushort_array_value, ushort_array_t);
    EXPECT_EQ(short_array_value, short_array_t);
    EXPECT_EQ(ulong_array_value, ulong_array_t);
    EXPECT_EQ(long_array_value, long_array_t);
    EXPECT_EQ(ulonglong_array_value, ulonglong_array_t);
    EXPECT_EQ(longlong_array_value, longlong_array_t);
    EXPECT_EQ(float_array_value, float_array_t);
    EXPECT_EQ(double_array_value, double_array_t);
    EXPECT_EQ(bool_array_value, bool_array_t);

    EXPECT_ARRAY_EQ(octet_array_2_value, octet_array_2_t, 5);
    EXPECT_ARRAY_EQ(char_array_2_value, char_array_2_t, 5);
    EXPECT_ARRAY_EQ(ushort_array_2_value, ushort_array_2_t, 5);
    EXPECT_ARRAY_EQ(short_array_2_value, short_array_2_t, 5);
    EXPECT_ARRAY_EQ(ulong_array_2_value, ulong_array_2_t, 5);
    EXPECT_ARRAY_EQ(long_array_2_value, long_array_2_t, 5);
    EXPECT_ARRAY_EQ(ulonglong_array_2_value, ulonglong_array_2_t, 5);
    EXPECT_ARRAY_EQ(longlong_array_2_value, longlong_array_2_t, 5);
    EXPECT_ARRAY_FLOAT_EQ(float_array_2_value, float_array_2_t, 5);
    EXPECT_ARRAY_DOUBLE_EQ(double_array_2_value, double_array_2_t, 5);
    EXPECT_ARRAY_EQ(bool_array_2_value, bool_array_2_t, 5);

    EXPECT_EQ(octet_vector_value, octet_vector_t);
    EXPECT_EQ(char_vector_value, char_vector_t);
    EXPECT_EQ(ushort_vector_value, ushort_vector_t);
    EXPECT_EQ(short_vector_value, short_vector_t);
    EXPECT_EQ(ulong_vector_value, ulong_vector_t);
    EXPECT_EQ(long_vector_value, long_vector_t);
    EXPECT_EQ(ulonglong_vector_value, ulonglong_vector_t);
    EXPECT_EQ(longlong_vector_value, longlong_vector_t);
    EXPECT_EQ(float_vector_value, float_vector_t);
    EXPECT_EQ(double_vector_value, double_vector_t);
    EXPECT_EQ(bool_vector_value, bool_vector_t);

    EXPECT_EQ(triple_ulong_array_t, triple_ulong_array_value);
    EXPECT_EQ(octet_seq_len, 5);
    EXPECT_ARRAY_EQ(octet_seq_value, octet_seq_t, 5);
    EXPECT_EQ(char_seq_len, 5);
    EXPECT_ARRAY_EQ(char_seq_value, char_seq_t, 5);
    EXPECT_EQ(ushort_seq_len, 5);
    EXPECT_ARRAY_EQ(ushort_seq_value, ushort_seq_t, 5);
    EXPECT_EQ(short_seq_len, 5);
    EXPECT_ARRAY_EQ(short_seq_value, short_seq_t, 5);
    EXPECT_EQ(ulong_seq_len, 5);
    EXPECT_ARRAY_EQ(ulong_seq_value, ulong_seq_t, 5);
    EXPECT_EQ(long_seq_len, 5);
    EXPECT_ARRAY_EQ(long_seq_value, long_seq_t, 5);
    EXPECT_EQ(ulonglong_seq_len, 5);
    EXPECT_ARRAY_EQ(ulonglong_seq_value, ulonglong_seq_t, 5);
    EXPECT_EQ(longlong_seq_len, 5);
    EXPECT_ARRAY_EQ(longlong_seq_value, longlong_seq_t, 5);
    EXPECT_EQ(float_seq_len, 5);
    EXPECT_ARRAY_FLOAT_EQ(float_seq_value, float_seq_t, 5);
    EXPECT_EQ(double_seq_len, 5);
    EXPECT_ARRAY_DOUBLE_EQ(double_seq_value, double_seq_t, 5);

    EXPECT_EQ(strcmp(c_string_t, c_string_value), 0);

    free(octet_seq_value);
    free(char_seq_value);
    free(ushort_seq_value);
    free(short_seq_value);
    free(ulong_seq_value);
    free(long_seq_value);
    free(ulonglong_seq_value);
    free(longlong_seq_value);
    free(float_seq_value);
    free(double_seq_value);
    free(c_string_value);
}