// Include the Ruby headers and goodies
#include "ruby.h"

// Defining a space for information and references about the module to be stored internally
VALUE Hello = Qnil;

// Prototype for the initialization method - Ruby calls this, not you
void Init_hello();

// Prototype for our method 'say_hello' - methods are prefixed by 'method_' here
VALUE method_say_hello(VALUE self);
VALUE method_multiply(VALUE self, VALUE rb_x, VALUE rb_y);

// The initialization method for this module
void Init_hello() {
	Hello = rb_define_class("Hello", rb_cObject);
	rb_define_method(Hello, "say_hello", method_say_hello, 0);
	rb_define_method(Hello, "multiply",  method_multiply, 2);
}

// Our 'say_hello' method.
VALUE method_say_hello(VALUE self) {
	char str[] = "Hello, World!";
	return rb_str_new(str, strlen(str));
}

VALUE method_multiply(VALUE self, VALUE rb_x, VALUE rb_y){
	// We're separating out each line here to explain - could be way less verbose
	int x = NUM2INT(rb_x);  //convert Ruby object to C int
	int y = NUM2INT(rb_y);
	int product = x * y;    //Do the stuff in C
	VALUE rb_product = INT2FIX(x*y); //convert back to Ruby Integer
	return rb_product;      
}


