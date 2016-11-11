// Copyright 2016 The Crashpad Authors. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "util/misc/arraysize_unsafe.h"

#include "gtest/gtest.h"

namespace crashpad {
namespace test {
namespace {

TEST(ArraySizeUnsafe, ArraySizeUnsafe) {
  char c0[0];
  static_assert(ARRAYSIZE_UNSAFE(c0) == 0, "c0");

  char c1[1];
  static_assert(ARRAYSIZE_UNSAFE(c1) == 1, "c1");

  char c2[2];
  static_assert(ARRAYSIZE_UNSAFE(c2) == 2, "c2");

  char c4[4];
  static_assert(ARRAYSIZE_UNSAFE(c4) == 4, "c4");

  int i0[0];
  static_assert(ARRAYSIZE_UNSAFE(i0) == 0, "i0");

  int i1[1];
  static_assert(ARRAYSIZE_UNSAFE(i1) == 1, "i1");

  int i2[2];
  static_assert(ARRAYSIZE_UNSAFE(i2) == 2, "i2");

  int i4[4];
  static_assert(ARRAYSIZE_UNSAFE(i4) == 4, "i4");

  long l8[8];
  static_assert(ARRAYSIZE_UNSAFE(l8) == 8, "l8");

  int l9[9];
  static_assert(ARRAYSIZE_UNSAFE(l9) == 9, "l9");

  struct S {
    char c;
    int i;
    long l;
    bool b;
  };

  S s0[0];
  static_assert(ARRAYSIZE_UNSAFE(s0) == 0, "s0");

  S s1[1];
  static_assert(ARRAYSIZE_UNSAFE(s1) == 1, "s1");

  S s10[10];
  static_assert(ARRAYSIZE_UNSAFE(s10) == 10, "s10");
}

}  // namespace
}  // namespace test
}  // namespace crashpad
