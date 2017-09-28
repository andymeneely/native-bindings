import hello

print("\n--- Example C Bindings Test ---")

print(">> About to call say_hello()")
hello.say_hello()

print(">> Call multiply(4,5)")
print(hello.multiply(4, 5))

print("^^ Was that 20? Then it worked!")