#include <node.h>

namespace hello {

using v8::Exception;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::NewStringType;
using v8::Number;
using v8::Integer;
using v8::Object;
using v8::String;
using v8::Value;

void Multiply(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

    if (args.Length() < 2) {
        // Throw an Error that is passed back to JavaScript
        isolate->ThrowException(Exception::TypeError(
            String::NewFromUtf8(isolate, "Wrong number of arguments", NewStringType::kNormal).ToLocalChecked())
        );
        return;
    }

    // Check the argument types
    if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
        isolate->ThrowException(Exception::TypeError(
            String::NewFromUtf8(isolate, "Wrong arguments", NewStringType::kNormal).ToLocalChecked())
        );
        return;
    }

    // multiplication function
    int value = args[0].As<Integer>()->Value() * args[1].As<Integer>()->Value();
    // end multiplication

    Local<Integer> num = Integer::New(isolate, value);
    args.GetReturnValue().Set(num);
}

void Initialize(Local<Object> exports) {
    NODE_SET_METHOD(exports, "multiply", Multiply);
    // Additional functions you want to expose
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

}
