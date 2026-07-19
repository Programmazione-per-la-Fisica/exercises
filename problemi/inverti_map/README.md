# Map Inverter
write a function inverti_diz(d) that takes a map as a parameter and returns its inverse.
Inverting a map means creating a new one where the values become keys and vice versa.
Since a value v can be associated with multiple keys in d, the inverted map has vectors containing the keys from the original as values.
For example: 
inverti_diz({{"g" : 1}, {"o" : 1}, {"p" : 3}, {"l" : 2}, {"a" : 3}}) = {{1 : {"g", "o"}}, {2 : "l"}, {3 : {"p", "a"}}}