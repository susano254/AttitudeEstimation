directories = AML/*.cpp example/*.cpp
includes = AML/
CXX = g++
output = build/AML_example

compile: 
	$(CXX) -g -I $(includes) $(directories) -o $(output)

run: compile 
	$(output)