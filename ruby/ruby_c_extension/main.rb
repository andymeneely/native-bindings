require_relative 'Hello/hello'

puts "\n--- Example C bindings Test ---"
hello = Hello.new

puts ">> About to call say_hello()"
puts hello.say_hello # in C

puts ">> Call multiply(4,5)"
puts hello.multiply(4,5) # in C

puts "^^ was that 20?? Then it worked!!" 
