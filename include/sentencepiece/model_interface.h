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

#ifndef MODEL_INTERFACE_H_
#define MODEL_INTERFACE_H_

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "common.h"
#include "stringpiece.h"

namespace sentencepiece {

// "_this_is_a_pen" => ["_this", "_is", "_a", "_pen"]
std::vector<StringPiece> SplitIntoWords(StringPiece text);

class ModelProto;

// Underlying model interface.
// Given a normalized string, returns a sequence of sentence pieces with ids.
class ModelInterface {
 public:
  using PieceToIdMap = std::unordered_map<StringPiece, int, StringPieceHash>;

  static const uint32 kUnkID;

  // |model_proto| should not be deleted until ModelInterface is destroyed.
  explicit ModelInterface(const ModelProto &model_proto);
  ModelInterface() {}

  virtual ~ModelInterface();

  virtual const ModelProto &model_proto() const { return *model_proto_; }

  // Given a normalized string, returns a sequence of sentence pieces with ids.
  // The concatenation of pieces must be the same as |normalized|.
  virtual std::vector<std::pair<StringPiece, int>> Encode(
      StringPiece normalized) const = 0;

  // Returns the size of sentence pieces, which is the same
  // as the size of vocabulary for NMT.
  virtual int GetPieceSize() const;

  // Returns the vocab id of |piece|.
  // Returns UNK(0) if |piece| is unknown
  virtual int PieceToId(StringPiece piece) const;

  // Returns the string representation of vocab with |id|.
  // id must be 0 <= id < GetPieceSize().
  virtual std::string IdToPiece(int id) const;

  // Returns the score of |id|.
  // Score represents a log probability of the piece.
  // We can roughly estimate the unigram frequency of the piece.
  virtual float GetScore(int id) const;

  // Returns true if |id| is unknown symbol.
  virtual bool IsUnknown(int id) const;

  // Returns true if |id| is control symbol.
  virtual bool IsControl(int id) const;

 protected:
  void CheckControlSymbols() const;

  const ModelProto *model_proto_ = nullptr;

  // piece -> id map for normal pieces
  PieceToIdMap pieces_;

  // piece -> id map for control and unknown
  PieceToIdMap reserved_id_map_;
};
}  // namespace sentencepiece
#endif  // MODEL_INTERFACE_H_
