// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: src/sentencepiece.proto

#ifndef PROTOBUF_src_2fsentencepiece_2eproto__INCLUDED
#define PROTOBUF_src_2fsentencepiece_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3003000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3003001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
namespace sentencepiece {
class SentencePieceText;
class SentencePieceTextDefaultTypeInternal;
extern SentencePieceTextDefaultTypeInternal _SentencePieceText_default_instance_;
class SentencePieceText_SentencePiece;
class SentencePieceText_SentencePieceDefaultTypeInternal;
extern SentencePieceText_SentencePieceDefaultTypeInternal _SentencePieceText_SentencePiece_default_instance_;
}  // namespace sentencepiece

namespace sentencepiece {

namespace protobuf_src_2fsentencepiece_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[];
  static const ::google::protobuf::uint32 offsets[];
  static void InitDefaultsImpl();
  static void Shutdown();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_src_2fsentencepiece_2eproto

// ===================================================================

class SentencePieceText_SentencePiece : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:sentencepiece.SentencePieceText.SentencePiece) */ {
 public:
  SentencePieceText_SentencePiece();
  virtual ~SentencePieceText_SentencePiece();

  SentencePieceText_SentencePiece(const SentencePieceText_SentencePiece& from);

  inline SentencePieceText_SentencePiece& operator=(const SentencePieceText_SentencePiece& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const SentencePieceText_SentencePiece& default_instance();

  static inline const SentencePieceText_SentencePiece* internal_default_instance() {
    return reinterpret_cast<const SentencePieceText_SentencePiece*>(
               &_SentencePieceText_SentencePiece_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(SentencePieceText_SentencePiece* other);

  // implements Message ----------------------------------------------

  inline SentencePieceText_SentencePiece* New() const PROTOBUF_FINAL { return New(NULL); }

  SentencePieceText_SentencePiece* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const SentencePieceText_SentencePiece& from);
  void MergeFrom(const SentencePieceText_SentencePiece& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(SentencePieceText_SentencePiece* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string piece = 1;
  bool has_piece() const;
  void clear_piece();
  static const int kPieceFieldNumber = 1;
  const ::std::string& piece() const;
  void set_piece(const ::std::string& value);
  #if LANG_CXX11
  void set_piece(::std::string&& value);
  #endif
  void set_piece(const char* value);
  void set_piece(const char* value, size_t size);
  ::std::string* mutable_piece();
  ::std::string* release_piece();
  void set_allocated_piece(::std::string* piece);

  // optional string surface = 3;
  bool has_surface() const;
  void clear_surface();
  static const int kSurfaceFieldNumber = 3;
  const ::std::string& surface() const;
  void set_surface(const ::std::string& value);
  #if LANG_CXX11
  void set_surface(::std::string&& value);
  #endif
  void set_surface(const char* value);
  void set_surface(const char* value, size_t size);
  ::std::string* mutable_surface();
  ::std::string* release_surface();
  void set_allocated_surface(::std::string* surface);

  // optional uint32 id = 2;
  bool has_id() const;
  void clear_id();
  static const int kIdFieldNumber = 2;
  ::google::protobuf::uint32 id() const;
  void set_id(::google::protobuf::uint32 value);

  // optional uint32 begin = 4;
  bool has_begin() const;
  void clear_begin();
  static const int kBeginFieldNumber = 4;
  ::google::protobuf::uint32 begin() const;
  void set_begin(::google::protobuf::uint32 value);

  // optional uint32 end = 5;
  bool has_end() const;
  void clear_end();
  static const int kEndFieldNumber = 5;
  ::google::protobuf::uint32 end() const;
  void set_end(::google::protobuf::uint32 value);

  GOOGLE_PROTOBUF_EXTENSION_ACCESSORS(SentencePieceText_SentencePiece)
  // @@protoc_insertion_point(class_scope:sentencepiece.SentencePieceText.SentencePiece)
 private:
  void set_has_piece();
  void clear_has_piece();
  void set_has_id();
  void clear_has_id();
  void set_has_surface();
  void clear_has_surface();
  void set_has_begin();
  void clear_has_begin();
  void set_has_end();
  void clear_has_end();

  ::google::protobuf::internal::ExtensionSet _extensions_;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr piece_;
  ::google::protobuf::internal::ArenaStringPtr surface_;
  ::google::protobuf::uint32 id_;
  ::google::protobuf::uint32 begin_;
  ::google::protobuf::uint32 end_;
  friend struct protobuf_src_2fsentencepiece_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class SentencePieceText : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:sentencepiece.SentencePieceText) */ {
 public:
  SentencePieceText();
  virtual ~SentencePieceText();

  SentencePieceText(const SentencePieceText& from);

  inline SentencePieceText& operator=(const SentencePieceText& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const SentencePieceText& default_instance();

  static inline const SentencePieceText* internal_default_instance() {
    return reinterpret_cast<const SentencePieceText*>(
               &_SentencePieceText_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(SentencePieceText* other);

  // implements Message ----------------------------------------------

  inline SentencePieceText* New() const PROTOBUF_FINAL { return New(NULL); }

  SentencePieceText* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const SentencePieceText& from);
  void MergeFrom(const SentencePieceText& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(SentencePieceText* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  typedef SentencePieceText_SentencePiece SentencePiece;

  // accessors -------------------------------------------------------

  // repeated .sentencepiece.SentencePieceText.SentencePiece pieces = 2;
  int pieces_size() const;
  void clear_pieces();
  static const int kPiecesFieldNumber = 2;
  const ::sentencepiece::SentencePieceText_SentencePiece& pieces(int index) const;
  ::sentencepiece::SentencePieceText_SentencePiece* mutable_pieces(int index);
  ::sentencepiece::SentencePieceText_SentencePiece* add_pieces();
  ::google::protobuf::RepeatedPtrField< ::sentencepiece::SentencePieceText_SentencePiece >*
      mutable_pieces();
  const ::google::protobuf::RepeatedPtrField< ::sentencepiece::SentencePieceText_SentencePiece >&
      pieces() const;

  // optional string text = 1;
  bool has_text() const;
  void clear_text();
  static const int kTextFieldNumber = 1;
  const ::std::string& text() const;
  void set_text(const ::std::string& value);
  #if LANG_CXX11
  void set_text(::std::string&& value);
  #endif
  void set_text(const char* value);
  void set_text(const char* value, size_t size);
  ::std::string* mutable_text();
  ::std::string* release_text();
  void set_allocated_text(::std::string* text);

  GOOGLE_PROTOBUF_EXTENSION_ACCESSORS(SentencePieceText)
  // @@protoc_insertion_point(class_scope:sentencepiece.SentencePieceText)
 private:
  void set_has_text();
  void clear_has_text();

  ::google::protobuf::internal::ExtensionSet _extensions_;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::sentencepiece::SentencePieceText_SentencePiece > pieces_;
  ::google::protobuf::internal::ArenaStringPtr text_;
  friend struct protobuf_src_2fsentencepiece_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// SentencePieceText_SentencePiece

// optional string piece = 1;
inline bool SentencePieceText_SentencePiece::has_piece() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void SentencePieceText_SentencePiece::set_has_piece() {
  _has_bits_[0] |= 0x00000001u;
}
inline void SentencePieceText_SentencePiece::clear_has_piece() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void SentencePieceText_SentencePiece::clear_piece() {
  piece_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_piece();
}
inline const ::std::string& SentencePieceText_SentencePiece::piece() const {
  // @@protoc_insertion_point(field_get:sentencepiece.SentencePieceText.SentencePiece.piece)
  return piece_.GetNoArena();
}
inline void SentencePieceText_SentencePiece::set_piece(const ::std::string& value) {
  set_has_piece();
  piece_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:sentencepiece.SentencePieceText.SentencePiece.piece)
}
#if LANG_CXX11
inline void SentencePieceText_SentencePiece::set_piece(::std::string&& value) {
  set_has_piece();
  piece_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:sentencepiece.SentencePieceText.SentencePiece.piece)
}
#endif
inline void SentencePieceText_SentencePiece::set_piece(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_piece();
  piece_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:sentencepiece.SentencePieceText.SentencePiece.piece)
}
inline void SentencePieceText_SentencePiece::set_piece(const char* value, size_t size) {
  set_has_piece();
  piece_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:sentencepiece.SentencePieceText.SentencePiece.piece)
}
inline ::std::string* SentencePieceText_SentencePiece::mutable_piece() {
  set_has_piece();
  // @@protoc_insertion_point(field_mutable:sentencepiece.SentencePieceText.SentencePiece.piece)
  return piece_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SentencePieceText_SentencePiece::release_piece() {
  // @@protoc_insertion_point(field_release:sentencepiece.SentencePieceText.SentencePiece.piece)
  clear_has_piece();
  return piece_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SentencePieceText_SentencePiece::set_allocated_piece(::std::string* piece) {
  if (piece != NULL) {
    set_has_piece();
  } else {
    clear_has_piece();
  }
  piece_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), piece);
  // @@protoc_insertion_point(field_set_allocated:sentencepiece.SentencePieceText.SentencePiece.piece)
}

// optional uint32 id = 2;
inline bool SentencePieceText_SentencePiece::has_id() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void SentencePieceText_SentencePiece::set_has_id() {
  _has_bits_[0] |= 0x00000004u;
}
inline void SentencePieceText_SentencePiece::clear_has_id() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void SentencePieceText_SentencePiece::clear_id() {
  id_ = 0u;
  clear_has_id();
}
inline ::google::protobuf::uint32 SentencePieceText_SentencePiece::id() const {
  // @@protoc_insertion_point(field_get:sentencepiece.SentencePieceText.SentencePiece.id)
  return id_;
}
inline void SentencePieceText_SentencePiece::set_id(::google::protobuf::uint32 value) {
  set_has_id();
  id_ = value;
  // @@protoc_insertion_point(field_set:sentencepiece.SentencePieceText.SentencePiece.id)
}

// optional string surface = 3;
inline bool SentencePieceText_SentencePiece::has_surface() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void SentencePieceText_SentencePiece::set_has_surface() {
  _has_bits_[0] |= 0x00000002u;
}
inline void SentencePieceText_SentencePiece::clear_has_surface() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void SentencePieceText_SentencePiece::clear_surface() {
  surface_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_surface();
}
inline const ::std::string& SentencePieceText_SentencePiece::surface() const {
  // @@protoc_insertion_point(field_get:sentencepiece.SentencePieceText.SentencePiece.surface)
  return surface_.GetNoArena();
}
inline void SentencePieceText_SentencePiece::set_surface(const ::std::string& value) {
  set_has_surface();
  surface_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:sentencepiece.SentencePieceText.SentencePiece.surface)
}
#if LANG_CXX11
inline void SentencePieceText_SentencePiece::set_surface(::std::string&& value) {
  set_has_surface();
  surface_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:sentencepiece.SentencePieceText.SentencePiece.surface)
}
#endif
inline void SentencePieceText_SentencePiece::set_surface(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_surface();
  surface_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:sentencepiece.SentencePieceText.SentencePiece.surface)
}
inline void SentencePieceText_SentencePiece::set_surface(const char* value, size_t size) {
  set_has_surface();
  surface_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:sentencepiece.SentencePieceText.SentencePiece.surface)
}
inline ::std::string* SentencePieceText_SentencePiece::mutable_surface() {
  set_has_surface();
  // @@protoc_insertion_point(field_mutable:sentencepiece.SentencePieceText.SentencePiece.surface)
  return surface_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SentencePieceText_SentencePiece::release_surface() {
  // @@protoc_insertion_point(field_release:sentencepiece.SentencePieceText.SentencePiece.surface)
  clear_has_surface();
  return surface_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SentencePieceText_SentencePiece::set_allocated_surface(::std::string* surface) {
  if (surface != NULL) {
    set_has_surface();
  } else {
    clear_has_surface();
  }
  surface_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), surface);
  // @@protoc_insertion_point(field_set_allocated:sentencepiece.SentencePieceText.SentencePiece.surface)
}

// optional uint32 begin = 4;
inline bool SentencePieceText_SentencePiece::has_begin() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void SentencePieceText_SentencePiece::set_has_begin() {
  _has_bits_[0] |= 0x00000008u;
}
inline void SentencePieceText_SentencePiece::clear_has_begin() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void SentencePieceText_SentencePiece::clear_begin() {
  begin_ = 0u;
  clear_has_begin();
}
inline ::google::protobuf::uint32 SentencePieceText_SentencePiece::begin() const {
  // @@protoc_insertion_point(field_get:sentencepiece.SentencePieceText.SentencePiece.begin)
  return begin_;
}
inline void SentencePieceText_SentencePiece::set_begin(::google::protobuf::uint32 value) {
  set_has_begin();
  begin_ = value;
  // @@protoc_insertion_point(field_set:sentencepiece.SentencePieceText.SentencePiece.begin)
}

// optional uint32 end = 5;
inline bool SentencePieceText_SentencePiece::has_end() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void SentencePieceText_SentencePiece::set_has_end() {
  _has_bits_[0] |= 0x00000010u;
}
inline void SentencePieceText_SentencePiece::clear_has_end() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void SentencePieceText_SentencePiece::clear_end() {
  end_ = 0u;
  clear_has_end();
}
inline ::google::protobuf::uint32 SentencePieceText_SentencePiece::end() const {
  // @@protoc_insertion_point(field_get:sentencepiece.SentencePieceText.SentencePiece.end)
  return end_;
}
inline void SentencePieceText_SentencePiece::set_end(::google::protobuf::uint32 value) {
  set_has_end();
  end_ = value;
  // @@protoc_insertion_point(field_set:sentencepiece.SentencePieceText.SentencePiece.end)
}

// -------------------------------------------------------------------

// SentencePieceText

// optional string text = 1;
inline bool SentencePieceText::has_text() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void SentencePieceText::set_has_text() {
  _has_bits_[0] |= 0x00000001u;
}
inline void SentencePieceText::clear_has_text() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void SentencePieceText::clear_text() {
  text_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_text();
}
inline const ::std::string& SentencePieceText::text() const {
  // @@protoc_insertion_point(field_get:sentencepiece.SentencePieceText.text)
  return text_.GetNoArena();
}
inline void SentencePieceText::set_text(const ::std::string& value) {
  set_has_text();
  text_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:sentencepiece.SentencePieceText.text)
}
#if LANG_CXX11
inline void SentencePieceText::set_text(::std::string&& value) {
  set_has_text();
  text_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:sentencepiece.SentencePieceText.text)
}
#endif
inline void SentencePieceText::set_text(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_text();
  text_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:sentencepiece.SentencePieceText.text)
}
inline void SentencePieceText::set_text(const char* value, size_t size) {
  set_has_text();
  text_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:sentencepiece.SentencePieceText.text)
}
inline ::std::string* SentencePieceText::mutable_text() {
  set_has_text();
  // @@protoc_insertion_point(field_mutable:sentencepiece.SentencePieceText.text)
  return text_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SentencePieceText::release_text() {
  // @@protoc_insertion_point(field_release:sentencepiece.SentencePieceText.text)
  clear_has_text();
  return text_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SentencePieceText::set_allocated_text(::std::string* text) {
  if (text != NULL) {
    set_has_text();
  } else {
    clear_has_text();
  }
  text_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), text);
  // @@protoc_insertion_point(field_set_allocated:sentencepiece.SentencePieceText.text)
}

// repeated .sentencepiece.SentencePieceText.SentencePiece pieces = 2;
inline int SentencePieceText::pieces_size() const {
  return pieces_.size();
}
inline void SentencePieceText::clear_pieces() {
  pieces_.Clear();
}
inline const ::sentencepiece::SentencePieceText_SentencePiece& SentencePieceText::pieces(int index) const {
  // @@protoc_insertion_point(field_get:sentencepiece.SentencePieceText.pieces)
  return pieces_.Get(index);
}
inline ::sentencepiece::SentencePieceText_SentencePiece* SentencePieceText::mutable_pieces(int index) {
  // @@protoc_insertion_point(field_mutable:sentencepiece.SentencePieceText.pieces)
  return pieces_.Mutable(index);
}
inline ::sentencepiece::SentencePieceText_SentencePiece* SentencePieceText::add_pieces() {
  // @@protoc_insertion_point(field_add:sentencepiece.SentencePieceText.pieces)
  return pieces_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::sentencepiece::SentencePieceText_SentencePiece >*
SentencePieceText::mutable_pieces() {
  // @@protoc_insertion_point(field_mutable_list:sentencepiece.SentencePieceText.pieces)
  return &pieces_;
}
inline const ::google::protobuf::RepeatedPtrField< ::sentencepiece::SentencePieceText_SentencePiece >&
SentencePieceText::pieces() const {
  // @@protoc_insertion_point(field_list:sentencepiece.SentencePieceText.pieces)
  return pieces_;
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


}  // namespace sentencepiece

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_src_2fsentencepiece_2eproto__INCLUDED
