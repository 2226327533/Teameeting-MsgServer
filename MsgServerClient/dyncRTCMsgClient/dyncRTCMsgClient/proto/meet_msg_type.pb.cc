// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: meet_msg_type.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "meet_msg_type.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace pms {

namespace {

const ::google::protobuf::EnumDescriptor* EMsgType_descriptor_ = NULL;
const ::google::protobuf::EnumDescriptor* EMsgTag_descriptor_ = NULL;
const ::google::protobuf::EnumDescriptor* EMsgHead_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_meet_5fmsg_5ftype_2eproto() {
  protobuf_AddDesc_meet_5fmsg_5ftype_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "meet_msg_type.proto");
  GOOGLE_CHECK(file != NULL);
  EMsgType_descriptor_ = file->enum_type(0);
  EMsgTag_descriptor_ = file->enum_type(1);
  EMsgHead_descriptor_ = file->enum_type(2);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_meet_5fmsg_5ftype_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
}

}  // namespace

void protobuf_ShutdownFile_meet_5fmsg_5ftype_2eproto() {
}

void protobuf_AddDesc_meet_5fmsg_5ftype_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\023meet_msg_type.proto\022\003pms*=\n\010EMsgType\022\010"
    "\n\004TMSG\020\001\022\t\n\005TFILE\020\002\022\010\n\004TPIC\020\003\022\010\n\004TAUD\020\004\022"
    "\010\n\004TVID\020\005*9\n\007EMsgTag\022\n\n\006TENTER\020\001\022\n\n\006TLEA"
    "VE\020\002\022\t\n\005TCHAT\020\003\022\013\n\007TNOTIFY\020\004*\036\n\010EMsgHead"
    "\022\010\n\004HSND\020\001\022\010\n\004HGET\020\002", 180);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "meet_msg_type.proto", &protobuf_RegisterTypes);
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_meet_5fmsg_5ftype_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_meet_5fmsg_5ftype_2eproto {
  StaticDescriptorInitializer_meet_5fmsg_5ftype_2eproto() {
    protobuf_AddDesc_meet_5fmsg_5ftype_2eproto();
  }
} static_descriptor_initializer_meet_5fmsg_5ftype_2eproto_;
const ::google::protobuf::EnumDescriptor* EMsgType_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return EMsgType_descriptor_;
}
bool EMsgType_IsValid(int value) {
  switch(value) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      return true;
    default:
      return false;
  }
}

const ::google::protobuf::EnumDescriptor* EMsgTag_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return EMsgTag_descriptor_;
}
bool EMsgTag_IsValid(int value) {
  switch(value) {
    case 1:
    case 2:
    case 3:
    case 4:
      return true;
    default:
      return false;
  }
}

const ::google::protobuf::EnumDescriptor* EMsgHead_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return EMsgHead_descriptor_;
}
bool EMsgHead_IsValid(int value) {
  switch(value) {
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace pms

// @@protoc_insertion_point(global_scope)
