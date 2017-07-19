// Copyright 2016 Google Inc.
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
// limitations under the License.!

#ifndef BUILDER_H_
#define BUILDER_H_

#include <map>
#include <string>
#include <vector>
#include "common.h"
#include "sentencepiece_model.pb.h"
#include "stringpiece.h"

namespace sentencepiece {
namespace normalizer {

// Builder creates a text normalization rule from user-defined string
// to string mappings. The normalization mapping is compiled into
// a single and compact blob index which is stored into the model proto.
// This class also provides pre-defined rules based on Unicode NFKC.
// https://en.wikipedia.org/wiki/Unicode_equivalence#Normalization
class Builder {
 public:
  Builder() = delete;
  ~Builder() = delete;

  // Basic Unicode character sequence.
  using Chars = std::vector<char32>;

  // String-to-string mapping.
  using CharsMap = std::map<Chars, Chars>;

  // Compiles |chars_map| into a binary index.
  static std::string CompileCharsMap(const CharsMap &chars_map);

  // Returns a pre-compiled binary index with |name|.
  static std::string GetPrecompiledCharsMap(const std::string &name);

  // Returns a normalizer spec with a binary index |name|.
  static NormalizerSpec GetNormalizerSpec(const std::string &name);

  // Makes a normalization mapping based on NFKC.
  //
  // Note that Normalizer/Builder classes do not support
  // full NFKC normalization, since full NFKC normalization cannot
  // be implemented with a simple longest matching string-to-string
  // replacement. One unsupported normalization is multiple combining
  // marks.
  //
  // Strings with multiple combining marks cannot correctly
  // be normalized, because it needs to sort the combining marks
  // with Canonical_Combining_Class (CCC).
  // http://unicode.org/reports/tr15/#Multiple_Mark_Figure
  //
  // Example:
  //  Original:    U+1E0B U+0323
  //  Decomposed:  U+0064 U+0307 U+0323
  //  NFKD:        U+0064 U+0323 U+0307 (Combining characters are sorted by CCC)
  //  NFKC:        U+1E0D U+0307 (U+0064 U+0323 => U+1E0D)
  //
  // To support the normalization above with a longest matching, we need to
  // enumerate all possible permutations of combining marks in advance,
  // which is not feasible. For example, suppose the case there are three
  // combining marks X, Y and Z, which are sorted into one canonical order
  // Z, Y, X with NFK(D|C).  In this case, all permutations (XYZ, XZY, YXZ...)
  // are normalized into ZYX. When we implement this normalization with
  // a longest matching, we need to have 3! rules. XYZ=>ZYX, XZY=>ZYX..
  // Since Unicode has more than 100 combining characters, it is not possible
  // to expand all permutations.
  //
  // We will not implement the full NFKC in SentencePiece because
  //  1) It is unusual to see decomposed Unicode characters in real text.
  //  2) Providing a flexible, user-customizable, and self-contained
  //     normalizer is the goal of SentencePiece.
  //
  // TODO(taku): Make NFC, NFD, and NFKD mapping if necessary.
  static CharsMap BuildNFKCMap();

  // Returns identity mapping, which dose not perform any normalization.
  static CharsMap BuildIdentityMap();

  // Builds Chars map save in |filename|.
  // Format:
  // src_uchar1 src_uchar2 ... <tab> trg_uchar1 trg_uchar2...
  // (src|trg)_ucharX must be a hex of UCS4.
  static CharsMap BuildMapFromFile(StringPiece filename);

 private:
  FRIEND_TEST(BuilderTest, RemoveRedundantMapTest);

  // Removes redundant rules from |chars_map|.
  // When char_maps have "aa" => "bb" and "a" => "b", the first
  // rule is not necessary since the second rule can cover the first rule.
  static CharsMap RemoveRedundantMap(const CharsMap &chars_map);
};
}  // namespace normalizer
}  // namespace sentencepiece
#endif  // BUILDER_H_
