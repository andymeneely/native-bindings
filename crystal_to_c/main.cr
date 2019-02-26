#main.cr
@[Link(ldflags: "#{__DIR__}/main.o")]

lib Native 
  fun hello(name : LibC::Char*) : Void
  fun multiply(x : LibC::Int32T, y : LibC::Int32T) : Int32
end

puts ">> About to call hello(\"world\")"
Native.hello("world")

puts ">> Call multiply(3, 5)"
puts Native.multiply(3, 5) # in C

puts "^^ was that 15?? Then it worked!!"
