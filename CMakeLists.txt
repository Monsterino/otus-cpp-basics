cmake_minimum_required(VERSION 3.5)

project(10.TikTakToe)



add_executable(TikTakToe 
			   src/main.cpp
			   src/Game.cpp
			   src/Game_interface.cpp
			   src/NeuralNetwork/Layer.cpp
			   src/NeuralNetwork/Weights_layers/Dense.cpp
			   src/NeuralNetwork/Net.cpp
			   src/NeuralNetwork/Activations/Activation.cpp
			   src/NeuralNetwork/Weights_initializators/Weights_initializators.cpp
			   src/Players/Players.cpp
			   src/Utils.cpp)

target_include_directories(TikTakToe PRIVATE include)

target_include_directories(TikTakToe PRIVATE libs/ubuntu/SFML/include)

target_link_directories (TikTakToe PRIVATE ${CMAKE_SOURCE_DIR}/libs/ubuntu/SFML/lib/)


target_link_libraries(TikTakToe PRIVATE  sfml-graphics
					 sfml-window
					 sfml-system)


#target_link_libraries(TikTakToe PRIVATE  ${CMAKE_SOURCE_DIR}/libs/SFML-2.5.1/lib/sfml-graphics
#					 ${CMAKE_SOURCE_DIR}/libs/SFML-2.5.1/lib/sfml-window
#					 ${CMAKE_SOURCE_DIR}/libs/SFML-2.5.1/lib/sfml-system)



set_target_properties(TikTakToe PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

